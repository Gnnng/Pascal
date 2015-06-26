#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "CodeGenContext.h"
using namespace std;

// static member

// other definition
llvm::Type* ast::TypeDecl::toLLVMType() {
    this->init();    
    switch(this->sys_name) {
        case ast::TypeDecl::TypeName::integer: return llvm::Type::getInt32Ty(llvm::getGlobalContext()); break;
        default: return llvm::Type::getVoidTy(llvm::getGlobalContext()); break;
    }
}


// Code Gen section
llvm::Value* ast::Identifier::CodeGen(CodeGenContext& context) {
	std::cout << "Creating identifier: " << name << std::endl;
    if (context.locals().find(name) == context.locals().end()) {
        throw std::logic_error("Undeclared variable " + name);
        return nullptr;
    }
    return new llvm::LoadInst(context.locals()[name], "", false, context.currentBlock());
}

llvm::Value* ast::IntegerType::CodeGen(CodeGenContext& context) {
	cout << "Creating integer: " << val << endl;
	return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), val, true);
}

llvm::Value* ast::BinaryOperator::CodeGen(CodeGenContext& context) {
    std::cout << "Creating BinaryOperator " << typeid(this->op).name() << std::endl;
    llvm::Instruction::BinaryOps inst;
    if (this->op == ast::BinaryOperator::OpType::plus) {
        inst = llvm::Instruction::Add;
        auto ret = llvm::BinaryOperator::Create(inst, op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
        std::cout << "Finshed BinaryOperator" << std::endl;
        return ret;
    } else {
        return nullptr;
    }
}

llvm::Value* ast::AssignmentStmt::CodeGen(CodeGenContext& context) {
    std::cout << "Creating assignemnt for id " << this->lhs->name << endl;
    if (context.locals().find(lhs->name) == context.locals().end()) {
        throw std::domain_error("Undeclared variable " + lhs->name);
        return nullptr;
    }
    return new llvm::StoreInst(rhs->CodeGen(context), context.locals()[lhs->name], false, context.currentBlock());
}


llvm::Value* ast::VarDecl::CodeGen(CodeGenContext& context) {
    std::cout << "Creating variable declaration " << this->name->name << std::endl;
    auto alloc = new llvm::AllocaInst(this->type->toLLVMType(), this->name->name.c_str(), context.currentBlock());
    context.locals()[this->name->name] = alloc;
    return alloc;
}

llvm::Value* ast::Program::CodeGen(CodeGenContext& context) {
    llvm::Value* last = nullptr;
    // deal with variable declaration
    for(auto var_decl: *(this->var_part)) {
        std::cout << "Generating code for " << typeid(var_decl).name() << std::endl;
        last = var_decl->CodeGen(context);
    }
    for(auto routine : *(this->routine_part)) {
        std::cout << "Generating code for " << typeid(routine).name() << std::endl;
        last = routine->CodeGen(context);
    }
    // deal with program statements
    for(auto stmt : *(this->routine_body)) {
        std::cout << "Generating code for " << typeid(stmt).name() << std::endl;
        last = stmt->CodeGen(context);
    }
    std::cout << "Creating program" << endl;
    return last;
}

llvm::Value* ast::Routine::CodeGen(CodeGenContext& context) {
    std::vector<llvm::Type*> arg_types;
    for(auto it : *(this->argument_list))
        arg_types.push_back(it->type->toLLVMType()); 
    auto f_type = llvm::FunctionType::get(this->isProcedure() ? llvm::Type::getVoidTy(llvm::getGlobalContext()) : this->return_type->toLLVMType(), llvm::makeArrayRef(arg_types), false);
    auto function = llvm::Function::Create(f_type, llvm::GlobalValue::InternalLinkage, this->routine_name->name.c_str(), context.module);
    auto block = llvm::BasicBlock::Create(getGlobalContext(), "entry", function, 0);

    // push block and start routine
    context.pushBlock(block);

    // deal with arguments
    llvm::Value* arg_value;
    auto args_values = function->arg_begin();
    for(auto arg : *(this->argument_list)) {
        arg->CodeGen(context);
        arg_value = args_values++;
        arg_value->setName(arg->name->name.c_str());
        auto inst = new llvm::StoreInst(arg_value, context.locals()[arg->name->name], false, block);
    }

    // add function return variable
    if (this->isFunction()) {
        std::cout << "Creating function return value declaration" << std::endl;
        auto alloc = new llvm::AllocaInst(this->return_type->toLLVMType(), this->routine_name->name.c_str(), context.currentBlock());
        context.locals()[this->routine_name->name] = alloc;
    }
        
    // deal with variable declaration
    for(auto var_decl: *(this->var_part)) {
        std::cout << "Generating code for decl " << typeid(var_decl).name() << std::endl;
        var_decl->CodeGen(context);
    }
    // deal with program statements
    for(auto stmt : *(this->routine_body)) {
        std::cout << "Generating code for body " << typeid(stmt).name() << std::endl;
        stmt->CodeGen(context);
    }
    // return value
    if (this->isFunction()) {
        std::cout << "Generating return value for function" << std::endl;
        auto load_ret = new llvm::LoadInst(context.locals()[this->routine_name->name], "", false, context.currentBlock());
        llvm::ReturnInst::Create(llvm::getGlobalContext(), load_ret, block);
    }
    else if(this->isProcedure()) {
        std::cout << "Generating return void for procedure" << std::endl;
        llvm::ReturnInst::Create(llvm::getGlobalContext(), block);
        
    }

    // pop block and finsh
    context.popBlock();
    std::cout << "Creating " << this->toString() << ":" << this->routine_name->name << std::endl;
    return function;
}
llvm::Value* ast::FuncCall::CodeGen(CodeGenContext& context) {
    auto function = context.module->getFunction(this->id->name.c_str());
    if (function == nullptr)
        throw std::domain_error("Function not defined" + this->id->name);
    std::vector<Value*> args;
    for(auto arg : *(this->argument_list)) {
        args.push_back(arg->CodeGen(context));
    }
    auto call = llvm::CallInst::Create(function, llvm::makeArrayRef(args), "", context.currentBlock());
    std::cout << "Creating method call: " << this->id->name << std::endl;
    return call;
}

llvm::Value* ast::ProcCall::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::SysFuncCall::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::SysProcCall::SysProc_write(CodeGenContext& context, bool writeln) {
//
// Two Declaration of get
//
// llvm::FunctionType * get( llvm::Type *Result, ArrayRef<llvm::Type *> Params, bool isVarArg )
// llvm::FunctionType * get( llvm::Type *Result, bool isVarArg ) 
// 
// the isVarArg is for varied-length arguments function
//
    //auto func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(llvm::getGlobalContext()), true);
       
//llvm::Function * Create( llvm::FunctionType *Ty, llvm::GlobalValue::LinkageTypes Linkage, const llvm::Twine &N, llvm::Module *M )
    //auto write_func = llvm::Function::Create(func_type, llvm::Function::InternalLinkage, writeln ? llvm::Twine("writeln") : llvm::Twine("write"), context.module);

    //auto block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", write_func, 0);
    //context.pushBlock(block);
   
    std::string printf_format;
    std::vector<llvm::Value *> printf_args;

    for(auto arg : *argument_list) {
        auto arg_val = arg->CodeGen(context);
        if (arg_val->getType() == llvm::Type::getInt32Ty(llvm::getGlobalContext())) {
            printf_format += "%d";     
            std::cout << "SysFuncCall write variable previous name" << arg_val->getName().str() << std::endl;
            printf_args.push_back(arg_val);
        } else if (arg_val->getType() == llvm::Type::getDoubleTy(llvm::getGlobalContext())) {
            printf_format += "%lf";
            printf_args.push_back(arg_val);
        } else if (arg_val->getType() == llvm::Type::getInt8PtrTy(llvm::getGlobalContext())) {
            assert("print string" == "not implemented");
        }
    }
    
    if (writeln)
        printf_format += "\n";
    
    auto printf_format_const = llvm::ConstantDataArray::getString(llvm::getGlobalContext(), printf_format.c_str());

    auto format_string_var = new llvm::GlobalVariable(*context.module, llvm::ArrayType::get(llvm::IntegerType::get(llvm::getGlobalContext(), 8), printf_format.size() + 1), true, llvm::GlobalValue::PrivateLinkage, printf_format_const, ".str");
    
    auto zero = llvm::Constant::getNullValue(llvm::IntegerType::getInt32Ty(llvm::getGlobalContext()));    

    std::vector<llvm::Constant *> indices;
    indices.push_back(zero); indices.push_back(zero);
    auto var_ref = llvm::ConstantExpr::getGetElementPtr(format_string_var, indices);

    printf_args.insert(printf_args.begin(), var_ref);
    auto call = llvm::CallInst::Create(CodeGenContext::printf, llvm::makeArrayRef(printf_args), "", context.currentBlock());
    //llvm::ReturnInst::Create(llvm::getGlobalContext(), block);
    
    //context.popBlock();
    return call;
}

llvm::Value* ast::SysProcCall::CodeGen(CodeGenContext& context) {
    if (this->id->name == "write" or this->id->name == "writeln") {
        return this->SysProc_write(context, this->id->name == "writeln");
    } else {
        assert("System procedure" == "Not found");
    }
    return nullptr;
}

llvm::Value* ast::TypeDecl::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::Expression::CodeGen(CodeGenContext& context) {}

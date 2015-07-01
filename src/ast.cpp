#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "CodeGenContext.h"
using namespace std;
// int ast::IfStmt::instanceCount = 0;
// static member

// other definition
llvm::Type* ast::TypeDecl::toLLVMType() {
    this->init();    
    switch(this->sys_name) {
        case ast::TypeDecl::TypeName::integer: return llvm::Type::getInt32Ty(llvm::getGlobalContext()); break;
        case ast::TypeDecl::TypeName::real: return llvm::Type::getFloatTy(llvm::getGlobalContext()); break;
        case ast::TypeDecl::TypeName::character: return llvm::Type::getInt8Ty(llvm::getGlobalContext()); break;
        case ast::TypeDecl::TypeName::boolean: return llvm::Type::getInt1Ty(llvm::getGlobalContext()); break;
        default: return llvm::Type::getVoidTy(llvm::getGlobalContext()); break;
    }
}


// Code Gen section
llvm::Value* ast::Identifier::CodeGen(CodeGenContext& context) {
	std::cout << "Creating identifier: " << name << std::endl;
    context.getValue(name);
    // if (context.locals().find(name) == context.locals().end()) {
    //     throw std::logic_error("Undeclared variable " + name);
    //     return nullptr;
    // }
    return new llvm::LoadInst(context.getValue(name), "", false, context.currentBlock());
}

llvm::Value* ast::IntegerType::CodeGen(CodeGenContext& context) {
	cout << "Creating integer: " << val << endl;
	return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), val, true);
}

llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {
	cout << "Creating real: " << val << endl;
	return llvm::ConstantInt::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::CharType::CodeGen(CodeGenContext& context) {
	cout << "Creating char: " << val << endl;
	return llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::BooleanType::CodeGen(CodeGenContext& context) {
	cout << "Creating boolean: " << val << endl;
	return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvm::getGlobalContext()), val, true);
}

llvm::Value* ast::BinaryOperator::CodeGen(CodeGenContext& context) {
    llvm::Instruction::BinaryOps instr;
    switch (op) {
   
    // Arithmetic Operations
    case OpType::plus:    return llvm::BinaryOperator::Create( llvm::Instruction::Add,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::minus:   return llvm::BinaryOperator::Create( llvm::Instruction::Sub,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::mul:     return llvm::BinaryOperator::Create( llvm::Instruction::Mul,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::div:     return llvm::BinaryOperator::Create( llvm::Instruction::SDiv,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::mod:     return llvm::BinaryOperator::Create( llvm::Instruction::SRem,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());    
    case OpType::bit_and:     return llvm::BinaryOperator::Create( llvm::Instruction::And,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());  
    case OpType::bit_or:     return llvm::BinaryOperator::Create( llvm::Instruction::Or,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock()); 
    case OpType::bit_xor:     return llvm::BinaryOperator::Create( llvm::Instruction::Xor,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock()); 
    // Logical Operations
    
    case OpType::eq:  {auto ret = llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_EQ,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock()); 
                      std::cout << "boolean value is int1 " << ret->getType()->isIntegerTy() << std::endl;
                      return ret;}
    case OpType::ne:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_NE,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::lt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLT,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::gt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGT,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::le:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLE,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    case OpType::ge:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGE,
            op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    //case OpType::and: return  llvm::cmp
    }
    return nullptr;
}

llvm::Value* ast::AssignmentStmt::CodeGen(CodeGenContext& context) {
    std::cout << "Creating assignemnt for id " << this->lhs->name << endl;
    // if (context.locals().find(lhs->name) == context.locals().end()) {
    //     throw std::domain_error("Undeclared variable " + lhs->name);
    //     return nullptr;
    // }
    return new llvm::StoreInst(rhs->CodeGen(context), context.getValue(lhs->name), false, context.currentBlock());
}


llvm::Value* ast::VarDecl::CodeGen(CodeGenContext& context) {
    std::cout << "Creating variable declaration " << this->name->name << std::endl;
    auto alloc = new llvm::AllocaInst(this->type->toLLVMType(), this->name->name.c_str(), context.currentBlock());
    context.insert(this->name->name,alloc);
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
    routine_body->CodeGen(context);
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
    auto oldFunc = context.currentFunction;
    context.currentFunction = function;
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
    routine_body->CodeGen(context);
    // return value
    if (this->isFunction()) {
        std::cout << "Generating return value for function" << std::endl;
        auto load_ret = new llvm::LoadInst(context.locals()[this->routine_name->name], "", false, context.currentBlock());
        llvm::ReturnInst::Create(llvm::getGlobalContext(), load_ret, context.currentBlock());
    }
    else if(this->isProcedure()) {
        std::cout << "Generating return void for procedure" << std::endl;
        llvm::ReturnInst::Create(llvm::getGlobalContext(), context.currentBlock());
        
    }

    // pop block and finsh
    context.popBlock();
    context.currentFunction = oldFunc;
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

llvm::Value* ast::Expression::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::IfStmt::CodeGen(CodeGenContext& context) {
    Value* test = condition->CodeGen( context );
    BasicBlock *btrue = BasicBlock::Create(getGlobalContext(), "thenStmt", context.currentFunction);
    BasicBlock *bfalse = BasicBlock::Create(getGlobalContext(), "elseStmt", context.currentFunction);
    BasicBlock *bmerge = BasicBlock::Create(getGlobalContext(), "mergeStmt", context.currentFunction);    
    auto ret = llvm::BranchInst::Create(btrue,bfalse,test,context.currentBlock());

    context.pushBlock(btrue);
    thenStmt->CodeGen(context);
    llvm::BranchInst::Create(bmerge,context.currentBlock());
    context.popBlock();
    context.pushBlock(bfalse);
    if (elseStmt != nullptr)
        elseStmt->CodeGen(context);
    llvm::BranchInst::Create(bmerge,context.currentBlock());
    context.popBlock();
    context.pushBlock(bmerge);


    return ret;
}
llvm::Value* ast::WhileStmt::CodeGen(CodeGenContext& context) {
    BasicBlock *sloop = BasicBlock::Create(getGlobalContext(), "startloop", context.currentFunction);
    BasicBlock *bloop = BasicBlock::Create(getGlobalContext(), "loopStmt", context.currentFunction);
    BasicBlock *bexit = BasicBlock::Create(getGlobalContext(), "eixtStmt", context.currentFunction);    
    llvm::BranchInst::Create(sloop,context.currentBlock());
    context.pushBlock(sloop);
    Value* test = condition->CodeGen( context );
    llvm::Instruction *ret = llvm::BranchInst::Create(bloop,bexit,test,context.currentBlock());
    context.popBlock();

    context.pushBlock(bloop);
    loopStmt->CodeGen(context);
    llvm::BranchInst::Create(sloop,context.currentBlock());
    context.popBlock();

    context.pushBlock(bexit);

    return ret;
}
llvm::Value* ast::RepeatStmt::CodeGen(CodeGenContext& context) {
    BasicBlock *bloop = BasicBlock::Create(getGlobalContext(), "loopStmt", context.currentFunction);
    BasicBlock *bexit = BasicBlock::Create(getGlobalContext(), "eixtStmt", context.currentFunction);    
    llvm::BranchInst::Create(bloop,context.currentBlock());

    context.pushBlock(bloop);
    loopStmt->CodeGen(context);
    Value* test = condition->CodeGen( context );
    llvm::Instruction *ret = llvm::BranchInst::Create(bexit,bloop,test,context.currentBlock());
    context.popBlock();

    context.pushBlock(bexit);

    return ret;
}
llvm::Value* ast::ForStmt::CodeGen(CodeGenContext& context) {
    BasicBlock *sloop = BasicBlock::Create(getGlobalContext(), "startloop", context.currentFunction);
    BasicBlock *bloop = BasicBlock::Create(getGlobalContext(), "loopStmt", context.currentFunction);
    BasicBlock *bexit = BasicBlock::Create(getGlobalContext(), "eixtStmt", context.currentFunction);    
//  initial for   
    AssignmentStmt* initial = new AssignmentStmt(loopVar,startExp);
    initial->CodeGen(context);
    llvm::BranchInst::Create(sloop,context.currentBlock());
//  for test
    context.pushBlock(sloop);
    BinaryOperator* compare = new BinaryOperator(loopVar, BinaryOperator::OpType::eq, endExp);
    Value* test = compare->CodeGen(context);
    llvm::Instruction *ret = llvm::BranchInst::Create(bexit,bloop,test,context.currentBlock());
    context.popBlock();

    context.pushBlock(bloop);
    loopStmt->CodeGen(context);
//update
    BinaryOperator* update;
    auto int1 = new IntegerType(1);
    if (direction == 1) {
        update = new BinaryOperator(loopVar, BinaryOperator::OpType::plus,int1);
    }
    else{
        update = new BinaryOperator(loopVar, BinaryOperator::OpType::minus,int1);
    }
    auto updateStmt = new AssignmentStmt(loopVar,update);
    updateStmt->CodeGen(context);
    llvm::BranchInst::Create(sloop,context.currentBlock());
    context.popBlock();

    context.pushBlock(bexit);
    loopStmt->CodeGen(context);
    delete initial;
    delete compare;
    delete int1;
    delete update;
    delete updateStmt;
    return ret;

}



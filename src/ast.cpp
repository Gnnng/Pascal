#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>
#include <map>
#include <functional>

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
        std::cerr << "Undeclared variable " << name << std::endl;
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
        return llvm::BinaryOperator::Create(inst, op1->CodeGen(context), op2->CodeGen(context), "", context.currentBlock());
    } else
        return nullptr;
}

llvm::Value* ast::AssignmentStmt::CodeGen(CodeGenContext& context) {
    std::cout << "Creating assignemnt for id " << this->lhs->name << endl;
    if (context.locals().find(lhs->name) == context.locals().end()) {
        std::cerr << "Undeclared variable" << lhs->name << endl;
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
    // deal with program statements
    for(auto stmt : *(this->var_part)) {
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
    auto f_type = llvm::FunctionType::get(this->return_type->toLLVMType(), llvm::makeArrayRef(arg_types), false);
    auto function = llvm::Function::Create(f_type, llvm::GlobalValue::InternalLinkage, this->routine_name->name.c_str(), context.module);
    auto block = llvm::BasicBlock::Create(getGlobalContext(), "entrypoint", function, 0);

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
    for(auto stmt : *(this->routine_list)) {
        std::cout << "Generating code for body " << typeid(stmt).name() << std::endl;
        stmt->CodeGen(context);
    }
    // return value
    if (this->isFunction())
        llvm::ReturnInst::Create(llvm::getGlobalContext(), block);
    else if(this->isProcedure())
        llvm::ReturnInst::Create(llvm::getGlobalContext(), context.locals()[this->routine_name->name], block);

    // pop block and finsh
    context.popBlock();
    std::cout << "Creating Routine" << std::endl;
    return function;
}

llvm::Value* ast::TypeDecl::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::Expression::CodeGen(CodeGenContext& context) {}

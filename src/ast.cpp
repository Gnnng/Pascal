#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>
#include <map>
#include <functional>

#include "CodeGenContext.h"
using namespace std;

// global variables 

//static llvm::Module *TheModule;
//static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
//static map<string, llvm::Value*> NamedValues;

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


void ast::VarDecl::addVar(VarDecl* var_list) {
	var_part = true;
    // var_list->print_node("PRINT ADDVAR BEFORE ", true, true);
	for(auto decl_i: var_list->var_decl_list) {
		auto list = decl_i->name->name_list;
        for(auto id_i: list) {
            auto n = new VarDecl();
            n->name = id_i;
            n->type = decl_i->type;
            n->debug = "VarDecl";
            this->var_decl_list.push_back(n);
            // std::cout << "Adding var " << n->name->name << std::endl;
        }
	}
	// var_list->print_node("PRINT ADDVAR AFTER ", true, true);
}

llvm::Value* ast::VarDecl::CodeGen(CodeGenContext& context) {
    std::cout 
        << "Creating variable declaration " << ast::TypeDecl::getName[this->type->sys_type_name] << " " 
        << this->name->name << std::endl;
    auto alloc = new llvm::AllocaInst([](ast::TypeDecl::TypeName type) -> llvm::Type* {
            if (type == ast::TypeDecl::TypeName::integer)
                return llvm::Type::getInt32Ty(llvm::getGlobalContext());
            return llvm::Type::getVoidTy(llvm::getGlobalContext());
        }(this->type->sys_type_name), this->name->name.c_str(), context.currentBlock());
    context.locals()[this->name->name] = alloc;
    return alloc;
}

llvm::Value* ast::Program::CodeGen(CodeGenContext& context) {
    llvm::Value* last = nullptr;
    // deal with variable declaration
    for(auto var_decl: this->var_part->var_decl_list) {
        std::cout << "Generating code for " << typeid(var_decl).name() << std::endl;
        last = var_decl->CodeGen(context);
    }
    // deal with program statements
    for(auto stmt : this->routine_body->stmt_list) {
        std::cout << "Generating code for " << typeid(stmt).name() << std::endl;
        last = stmt->CodeGen(context);
    }
    std::cout << "Creating program" << endl;
    return last;
}


std::map<ast::TypeDecl::TypeName, std::string> ast::TypeDecl::getName = {
		{ ast::TypeDecl::TypeName::integer, "integer"},
		{ ast::TypeDecl::TypeName::real, "real"},
		{ ast::TypeDecl::TypeName::error, "error"}
};

llvm::Value* ast::TypeDecl::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::Expression::CodeGen(CodeGenContext& context) {}

#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <map>

using namespace std;

// global variables 

//static llvm::Module *TheModule;
//static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
//static map<string, llvm::Value*> NamedValues;

// Code Gen section
llvm::Value* ast::Identifier::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::IntegerType::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::BinaryOperator::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::AssignmentStmt::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::VarDecl::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::Program::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::TypeDecl::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {}

llvm::Value* ast::Expression::CodeGen(CodeGenContext& context) {}
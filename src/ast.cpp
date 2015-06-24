#include "ast.h"

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <map>

using namespace std;
// global variables 

static llvm::Module *TheModule;
static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
static map<string, llvm::Value*> NamedValues;

// utils functions
llvm::Value* Error(const char *str) {
	Error(str);
	return 0;
}

// Code Gen section
llvm::Value* Identifier::Codegen() {}

llvm::Value* IntegerType::Codegen() {}

llvm::Value* BinaryOperator::Codegen() {}

llvm::Value* AssignmentStmt::Codegen() {}

llvm::Value* VarDecl::Codegen() {}

llvm::Value* Program::Codegen() {}

llvm::Value* TypeDecl::Codegen() {}

llvm::Value* RealType::Codegen() {}

llvm::Value* Expression::Codegen() {}
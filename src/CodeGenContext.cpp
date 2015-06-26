#include <iostream>
#include <vector>
#include <map>

#include "ast.h"
#include "CodeGenContext.h"
#include "parser.hpp"

llvm::Function* CodeGenContext::printf;

llvm::Function* createPrintf(CodeGenContext& context) {
	std::vector<llvm::Type *> printf_arg_types;
    printf_arg_types.push_back(llvm::Type::getInt8PtrTy(llvm::getGlobalContext()));
    auto printf_type = llvm::FunctionType::get(llvm::Type::getInt32Ty(getGlobalContext()), printf_arg_types, true);
    auto func = llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("printf"), context.module);
    func->setCallingConv(llvm::CallingConv::C);
    return func;
}

/* Compile the AST into a module */
void CodeGenContext::generateCode(ast::Program& root)
{
	std::cout << "Generating code...\n";
	
	/* Create the top level interpreter function to call as entry */
	std::vector<Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	// change GlobalValue::InternalLinkage into ExternalLinkage
	mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);
	
	CodeGenContext::printf = createPrintf(*this);

	/* Push a new variable/block context */
	pushBlock(bblock);
	root.CodeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();
	
	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	std::cout << "Code is generated.\n";
	PassManager pm;
	pm.add(createPrintModulePass(outs()));
	//pm.run(*module);

    // write IR to stderr
    module->dump();
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode() {
	std::cout << "Running begining...\n";
	std::cout << 
	"========================================" << std::endl;
	ExecutionEngine *ee = EngineBuilder(module).create();
	std::vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(mainFunction, noargs);
	std::cout << 
	"========================================" << std::endl;
	std::cout << "Running end.\n";
	return v;
}

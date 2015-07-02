#ifndef __CODEGENCONTEXT_H__
#define __CODEGENCONTEXT_H__ 

#include <stack>
#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/ValueSymbolTable.h>

#include "ast.h"
using namespace llvm;
class CodeGenBlock {
public:
    BasicBlock *block;
    Value *returnValue;
    CodeGenBlock * parent;
    std::map<std::string, Value*> locals;
};

class CodeGenContext {
    std::stack<CodeGenBlock *> blocks;
    

public:
    static std::vector<int> labels;
    llvm::BasicBlock* labelBlock[10000];
    Function* currentFunction;
    Function *mainFunction;
    static llvm::Function* printf;
    Module *module;
    CodeGenContext() { module = new Module("main", getGlobalContext()); }
    void generateCode(ast::Program& root);
    GenericValue runCode();
    Value* getValue(std::string name){
        // CodeGenBlock *nowBlock= blocks.top();
        // while (nowBlock->locals.find(name) == nowBlock->locals.end()) {
        //     if (nowBlock->parent == nullptr){
        //         throw std::logic_error("Undeclared variable " + name);
        //         return nullptr;
        //     } else
        //     {
        //         nowBlock = nowBlock->parent;
        //     }
        // }
        // std::cout<<"location:"<<nowBlock->locals[name]<<"\n";
        return currentFunction->getValueSymbolTable().lookup(name);
        // return nowBlock->locals[name];
    }
    void insert(std::string name, Value* alloc){
        // blocks.top()->locals[name] = alloc;
    }
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }
    BasicBlock *currentBlock() { return blocks.top()->block; }
    void pushBlock(BasicBlock *block) { 
        // std::cout<<"haha!\n";
        CodeGenBlock* newb =new CodeGenBlock();
        // // std::cout<<"haha!\n";
        // if (blocks.empty()) {
        //     std::cout<<"father\n";
        //     newb->parent = nullptr;
        // }else{
        //     std::cout<<"new child block!\n";
        //     newb->parent = blocks.top();     
        // }
        
        // // std::cout<<"haha!\n";
        blocks.push(newb); 
        blocks.top()->returnValue = nullptr; 
        blocks.top()->block = block; 
         // blocks.push(new CodeGenBlock()); blocks.top()->block = block;
    }
    void popBlock() { CodeGenBlock *top = blocks.top(); blocks.pop(); delete top; }
    void setCurrentReturnValue(Value *value) { blocks.top()->returnValue = value; }
    Value* getCurrentReturnValue() { return blocks.top()->returnValue; }
};

#endif

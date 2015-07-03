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
    std::map<std::string, ast::ConstValue*> const_locals;
};

class CodeGenContext {
    std::stack<CodeGenBlock *> blocks;
    
public:
    static std::vector<int> labels;
    std::map<Function*,Function*> parent;
    llvm::BasicBlock* labelBlock[10000];
    Function* currentFunction;
    Function *mainFunction;
    static llvm::Function* printf;
    Module *module;
    CodeGenContext() { module = new Module("main", getGlobalContext()); }
    void generateCode(ast::Program& root);
    GenericValue runCode();
    Value* getValue(std::string name){
        std::cout<<"found:"<<currentFunction->getValueSymbolTable().lookup(name)<<"\n";
        std::cout<<"main:"<<mainFunction<<"\n";
        std::cout<<"current:"<<currentFunction<<"\n";
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
        llvm::Function* nowFunc = currentFunction;

        while ((nowFunc->getValueSymbolTable().lookup(name))==NULL)
        {
            std::cout<<"found:"<<nowFunc->getValueSymbolTable().lookup(name)<<"\n";
            if (nowFunc == mainFunction)
            {
                throw std::logic_error("Undeclared variable " + name);
                return nullptr;
            }
            else
            {
                nowFunc = parent[nowFunc];
            }
        }
        std::cout<<nowFunc->getValueSymbolTable().lookup(name)<<"found\n";
        return nowFunc->getValueSymbolTable().lookup(name);
        // return nowBlock->locals[name];
    }
    ast::ConstValue* getConstValue(std::string name) {
        auto n_block = blocks.top();
        while (n_block->const_locals.find(name) == n_block->const_locals.end()) {
            if (n_block->parent == nullptr) {
                throw std::logic_error("Undeclared const " + name);
                return nullptr;
            } else 
                n_block = n_block->parent;
        }
    }
    void insert(std::string name, Value* alloc){
        // blocks.top()->locals[name] = alloc;
    }
    void insertConst(std::string name, ast::ConstValue* const_v){ blocks.top()->const_locals[name] = const_v; }
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }
    BasicBlock *currentBlock() { return blocks.top()->block; }
    void pushBlock(BasicBlock *block) { 
        // std::cout<<"haha!\n";
        CodeGenBlock* newb =new CodeGenBlock();
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

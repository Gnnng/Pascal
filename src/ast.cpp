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
#include "utils.h"
using namespace std;
// int ast::IfStmt::instanceCount = 0;
// static member

// other definition
llvm::Type* ast::TypeDecl::toLLVMType() {
    this->init();    
    switch(this->sys_name) {
        case ast::TypeDecl::TypeName::integer:  return llvm::Type::getInt32Ty(llvm::getGlobalContext());    break;
        case ast::TypeDecl::TypeName::real:     return llvm::Type::getFloatTy(llvm::getGlobalContext());    break;
        case ast::TypeDecl::TypeName::character:return llvm::Type::getInt8Ty(llvm::getGlobalContext());     break;
        case ast::TypeDecl::TypeName::boolean:  return llvm::Type::getInt1Ty(llvm::getGlobalContext());     break;
        case ast::TypeDecl::TypeName::range:    return llvm::Type::getInt32Ty(llvm::getGlobalContext());    break;
        case ast::TypeDecl::TypeName::array:    return llvm::ArrayType::get(this->array_type->array_type->toLLVMType(), this->array_type->subscript->range_type->size()); break;
        default:                                return llvm::Type::getVoidTy(llvm::getGlobalContext());     break;
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
    std::cout << "Creating integer: " << val << std::endl;
	return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::RealType::CodeGen(CodeGenContext& context) {
    std::cout << "Creating real: " << val << std::endl;
    return llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), val);
	//return llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::CharType::CodeGen(CodeGenContext& context) {
    std::cout << "Creating char: " << val << std::endl;
	return llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::BooleanType::CodeGen(CodeGenContext& context) {
    std::cout << "Creating boolean: " << val << std::endl;
	return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvm::getGlobalContext()), val, true);
}
llvm::Value* ast::RangeType::CodeGen(CodeGenContext& context) {
    if (this->isNameRange) {
        //TODO: need to use correspoding value to assign to low and high
        auto low_v = context.getConstValue(this->low_s);
        auto high_v = context.getConstValue(this->high_s);
        if (low_v->notRange() || high_v->notRange() ) {
            throw std::domain_error("Not a valid range type: real");
        }
        this->low = context.getConstValue(this->low_s)->toRange();
        this->high = context.getConstValue(this->high_s)->toRange();
    }
    if (this->low > this->high) {
        throw std::logic_error("High range limit < low range limit");
    }
    std::cout << "Creating subscript range from " << this->low << " to " << this->high << std::endl;
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
    if (this->complex_assign)
        std::cout << "Creating assignment for array: " << getlhsName() << "[]" << std::endl;
    else
        std::cout << "Creating assignemnt for id " << getlhsName() << std::endl;
    // if (context.locals().find(lhs->name) == context.locals().end()) {
    //     throw std::domain_error("Undeclared variable " + lhs->name);
    //     return nullptr;
    // }
    if (this->complex_assign)
        return new llvm::StoreInst(rhs->CodeGen(context), ((ArrayRef* )lhs)->getRef(context), false, context.currentBlock());

    //auto rhs_val = new llvm::LoadInst(rhs->CodeGen(context), "", false, context.currentBlock());
    //return new llvm::StoreInst(rhs_val, context.getValue(this->getlhsName()), false, context.currentBlock());
    return new llvm::StoreInst(rhs->CodeGen(context), context.getValue(this->getlhsName()), false, context.currentBlock());
}

llvm::Value* ast::ConstDecl::CodeGen(CodeGenContext& context) {
    std::cout << "Creating constant declaration " << this->name->name << std::endl;
    auto alloc = new llvm::AllocaInst(this->type->toLLVMType(), this->name->name.c_str(), context.currentBlock());
    context.insert(this->name->name, alloc);
    auto store = new llvm::StoreInst(this->val->CodeGen(context), alloc, false, context.currentBlock());

    context.insertConst(this->name->name, this->val);
    return store;
}


llvm::Value* ast::VarDecl::CodeGen(CodeGenContext& context) {
    std::cout << "Creating variable declaration " << this->name->name << std::endl;
    llvm::Value* alloc;
    if (isGolbal)
    {
            DBVAR((int)this->type->sys_name);
            DBVAR(this->type->array_type);
            DBVAR(this->type->raw_name);
        if (this->type->sys_name  == ast::TypeDecl::TypeName::array) {
            DBVAR("decl global of array");
            auto sub_type = this->type->array_type->array_type->sys_name;
            auto vec = std::vector<llvm::Constant *>();
            for(int i = 0 ; i < this->type->array_type->subscript->range_type->size(); i++) {
                auto const_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0, true);
                vec.push_back(const_0);
            }
            auto arr_type_0 = (llvm::ArrayType *) this->type->toLLVMType();
            auto arr_const = llvm::ConstantArray::get(arr_type_0, vec);

            auto go= new llvm::GlobalVariable(*context.module, this->type->toLLVMType(), false, llvm::GlobalValue::ExternalLinkage , arr_const, this->name->name);
            alloc = go;


        } else {
            DBVAR("decl global not a array");
        auto go= new llvm::GlobalVariable(*context.module, this->type->toLLVMType(), false, llvm::GlobalValue::ExternalLinkage , llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0, true), this->name->name);
        alloc = go;
        }
    }
    else
        alloc = new llvm::AllocaInst(this->type->toLLVMType(), this->name->name.c_str(), context.currentBlock());
    context.insert(this->name->name,alloc);
    std::cout << "Creating variable declaration successfully " << this->name->name << std::endl;
    return alloc;
}

llvm::Value* ast::Program::CodeGen(CodeGenContext& context) {
    llvm::Value* last = nullptr;

    /* const decl part */
    for(auto const_decl: *(this->const_part)) {
        std::cout << "Generating code for " << typeid(const_decl).name() << std::endl;
        last = const_decl->CodeGen(context);
    }
    // deal with variable declaration

    for(auto var_decl: *(this->var_part)) {
        std::cout << "Generating code for " << typeid(var_decl).name() << std::endl;
        var_decl->isGolbal = 1;
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
    auto block = llvm::BasicBlock::Create(getGlobalContext(), "entry", function,NULL);
    auto oldFunc = context.currentFunction;
    context.currentFunction = function;
    auto oldBlock = context.currentBlock();
    context.parent[function] = oldFunc;
    // push block and start routine
    context.pushBlock(block);

    // deal with arguments
    llvm::Value* arg_value;
    auto args_values = function->arg_begin();
    for(auto arg : *(this->argument_list)) {
        arg->CodeGen(context);
        arg_value = args_values++;
        arg_value->setName(arg->name->name.c_str());
        auto inst = new llvm::StoreInst(arg_value, context.getValue(arg->name->name), false, block);
    }

    std::cout<<"is func?"<<this->isFunction()<<" part suc!\n"; 
    // add function return variable
    if (this->isFunction()) {
        std::cout << "Creating function return value declaration" << std::endl;
        auto alloc = new llvm::AllocaInst(this->return_type->toLLVMType(), this->routine_name->name.c_str(), context.currentBlock());
        // context.insert(this->routine_name->name) = alloc;
    }
    std::cout<<"func part suc!\n";    
    // deal with variable declaration
    for(auto var_decl: *(this->var_part)) {
        std::cout << "Generating code for decl " << typeid(var_decl).name() << std::endl;
        var_decl->CodeGen(context);
    }
    for(auto routine : *(this->routine_part)) {
        std::cout << "Generating code for " << typeid(routine).name() << std::endl;
        routine->CodeGen(context);
    }
    // deal with program statements
    std::cout<<"var part suc!\n";
    routine_body->CodeGen(context);
    // return value

    
    if (this->isFunction()) {
        std::cout << "Generating return value for function" << std::endl;
        auto load_ret = new llvm::LoadInst(context.getValue(this->routine_name->name), "", false, context.currentBlock());
        llvm::ReturnInst::Create(llvm::getGlobalContext(), load_ret, context.currentBlock());
    }
    else if(this->isProcedure()) {
        std::cout << "Generating return void for procedure" << std::endl;
        llvm::ReturnInst::Create(llvm::getGlobalContext(), context.currentBlock());
        
    }

    // pop block and finsh
    while (context.currentBlock() != oldBlock)
        context.popBlock();
    context.currentFunction = oldFunc;
    std::cout << "Creating " << this->toString() << ":" << this->routine_name->name << std::endl;
    return function;
}
llvm::Value* ast::FuncCall::CodeGen(CodeGenContext& context) {
    auto function = context.module->getFunction(this->id->name.c_str());
    if (function == nullptr)
        throw std::domain_error("Function not defined: " + this->id->name);
    std::vector<Value*> args;
    for(auto arg : *(this->argument_list)) {
        args.push_back(arg->CodeGen(context));
    }
    auto call = llvm::CallInst::Create(function, llvm::makeArrayRef(args), "", context.currentBlock());
    std::cout << "Creating method call: " << this->id->name << std::endl;
    return call;
}

llvm::Value* ast::ProcCall::CodeGen(CodeGenContext& context) {
    auto function = context.module->getFunction(this->id->name.c_str());
    if (function == nullptr)
        throw std::domain_error("procedure not defined: " + this->id->name);
    std::vector<Value*> args;
    for(auto arg : *(this->argument_list)) {
        args.push_back(arg->CodeGen(context));
    }
    auto call = llvm::CallInst::Create(function, llvm::makeArrayRef(args), "", context.currentBlock());
    std::cout << "Creating method(p) call: " << this->id->name << std::endl;
    return call;
}

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
llvm::Value* ast::CaseStmt::CodeGen(CodeGenContext& context){
    
    cout<<"in case"<<condition<<endl;
    auto ret = thenStmt->CodeGen(context);
     cout<<"in case 2"<<condition<<endl;
    llvm::BranchInst::Create(bexit,context.currentBlock());
     cout<<"in case 3"<<condition<<endl;
    return ret;
}
llvm::Value* ast::SwitchStmt::CodeGen(CodeGenContext& context) {
    BasicBlock* bexit = BasicBlock::Create(getGlobalContext(), "exit", context.currentFunction);

    std::vector<BasicBlock *> bblocks;
    cout<<(*list)[1]->condition<<endl;
   
    for (int i=0;i<(list->size());i++){ 
        auto bblock = BasicBlock::Create(getGlobalContext(), "caseStmt", context.currentFunction);
        bblocks.push_back(bblock);
    }

    for (int i=0;i<bblocks.size()-1;i++)
    {    
        cout<<"in bblocks\n";
        cout<<(*list)[0]->condition<<"\n";
        auto con = new BinaryOperator(exp, BinaryOperator::OpType::eq,(*list)[i]->condition);
        BasicBlock* bnext = BasicBlock::Create(getGlobalContext(), "next", context.currentFunction);
        llvm::BranchInst::Create(bblocks[i],bnext,con->CodeGen(context),context.currentBlock());
        context.pushBlock(bnext);
    }
    auto con = new BinaryOperator(exp, BinaryOperator::OpType::eq,(*list)[bblocks.size()-1]->condition);
    auto ret= llvm::BranchInst::Create(bblocks[bblocks.size()-1],bexit,con->CodeGen(context),context.currentBlock());
    for (int i=0;i<bblocks.size();i++)
    { 
        context.pushBlock(bblocks[i]);
        auto cst = (*list)[i];
        cst->bexit = bexit;
        cst->CodeGen(context);
        cout<<"gggg~~~\n";
        context.popBlock(); 
    }
    
    context.pushBlock(bexit);

    return ret;
}
llvm::Value* ast::GotoStmt::CodeGen(CodeGenContext& context){
    llvm::Value* test= (new BooleanType("true"))->CodeGen(context);
    BasicBlock* bafter = BasicBlock::Create(getGlobalContext(), "afterGoto", context.currentFunction);
    auto ret = llvm::BranchInst::Create(context.labelBlock[label],context.currentBlock());
    context.pushBlock(bafter);
    return ret;
}
llvm::Value* ast::LabelStmt::CodeGen(CodeGenContext& context){
    llvm::BranchInst::Create(context.labelBlock[label],context.currentBlock());

    context.pushBlock(context.labelBlock[label]);
    return statement->CodeGen(context);
}

llvm::Value* ast::ArrayType::CodeGen(CodeGenContext& context) {
}

llvm::Value* ast::ArrayRef::CodeGen(CodeGenContext& context) {
    return new llvm::LoadInst(this->getRef(context), "", false, context.currentBlock());
}

llvm::Value* ast::ArrayRef::getRef(CodeGenContext& context) {
    DBMSG("Creating ArrayRef");
    DBVAR(this->array->name);
    auto arr = context.getValue(this->array->name);
    DBVAR(typeid(arr).name());
    DBMSG("Creating ArrayRef: array part is generated");
    
 //   auto a_type = llvm::ArrayType::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 9);
//    auto arr_t = new llvm::AllocaInst(a_type, std::string("mem"), context.currentBlock());

//    DBVAR(typeid(arr_t).name());
//    auto vec = std::vector<Value *>();
//    vec.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0));
//    vec.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 1));
//    auto ret = llvm::GetElementPtrInst::CreateInBounds(arr_t, llvm::ArrayRef<llvm::Value*>(vec), "ret", context.currentBlock());
//    //return ret;
    auto idx_list = std::vector<llvm::Value*>();
    idx_list.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0));
    //idx_list.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), 0));
    DBVAR("before codgen");
    idx_list.push_back(index->CodeGen(context));
    DBVAR("after codgen");
    DBVAR(this->index->toString());
    return llvm::GetElementPtrInst::CreateInBounds(arr, llvm::ArrayRef<llvm::Value*>(idx_list), "tempname", context.currentBlock());
}

#ifndef __AST_H__
#define __AST_H__

#include "llvm/IR/Value.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

//used forward-declaration to deal with cross-reference issue
class CodeGenContext;

// namespace ast start
namespace ast {

// forward declaration
class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
class Statement;
class Identifier;
class Routine;

typedef std::vector<Statement *>    StatementList;
typedef std::vector<VarDecl *>      VarDeclList;
typedef std::vector<Identifier *>   IdentifierList;
typedef std::vector<Routine *>      RoutineList;
typedef std::vector<std::string>    NameList;

// pure virtual class for all ast nodes
class Node {
public:
    std::string     debug;

    void print_node(std::string prefix, bool tail, bool root) {
        std::string tailStr = "└── ";
        std::string branchStr = "├── ";
        std::string ch_tailStr = "    ";
        std::string ch_branchStr = "|   ";
        std::cout << (root ? prefix : (prefix + (tail ? tailStr : branchStr))) << (this->toString()) << std::endl;
        auto children_list = this->getChildren();
        auto ch_prefix = tail ? prefix + ch_tailStr : prefix + ch_branchStr;
        for(size_t i = 0; i < children_list.size(); i++) {
            children_list[i] ? children_list[i]->print_node(ch_prefix, i == children_list.size() - 1, false) : []() {}();
        }
    }

    virtual std::vector<Node *> getChildren() { return *(new std::vector<Node *>()); }
    virtual ~Node() {}
    virtual std::string toString() = 0;
    virtual llvm::Value *CodeGen(CodeGenContext& context) = 0;
};

class Program : public Node {
public:
    LabelDecl*      lable_part;
    ConstDecl*      const_part;
    TypeDecl*       type_part;
    VarDeclList*    var_part;
    RoutineList*    routine_part;
    StatementList*  routine_body;

    Program() {}
    Program(LabelDecl* lp, ConstDecl* cp, TypeDecl* tp, VarDeclList* vp, RoutineList* rp, StatementList* rb) :
        lable_part(lp),
        const_part(cp),
        type_part(tp),
        var_part(vp),
        routine_part(rp),
        routine_body(rb) {}
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        for(auto i : *(var_part)) list.push_back((Node *)i);
        for(auto i : *(routine_part)) list.push_back((Node *)i);
        for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "Program start"; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Routine : public Program {
public:
    enum class RoutineType { function, procedure, error };
    Identifier*     routine_name;
    TypeDecl*       return_type;
    VarDeclList*    argument_list;
    RoutineType     routine_type; // function or procedure 

    Routine(RoutineType rt, Identifier* rn, VarDeclList* vdl, TypeDecl* td) :
        Program(),
        routine_name(rn),
        return_type(td),
        argument_list(vdl),
        // routine_list(nullptr),
        routine_type(rt) {}
    Routine(Routine* r, Program* p) : 
        Program(*p),
        routine_name(r->routine_name),
        return_type(r->return_type),
        argument_list(r->argument_list),
        // routine_list(r->routine_list),
        routine_type(r->routine_type) {}

    bool isFunction() { return routine_type == RoutineType::function; }
    bool isProcedure() { return routine_type == RoutineType::procedure; }

    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)routine_name);
        list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        for(auto i : *(var_part)) list.push_back((Node *)i);
        for(auto i : *(routine_part)) list.push_back((Node *)i);
        for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "Routine start"; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Expression : public Node {
public:
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Statement : public Node {
public:
    Statement() {};

    virtual llvm::Value *CodeGen(CodeGenContext& context) {}
};

class LabelDecl : public Statement {

};

class ConstDecl : public Statement {

};

class TypeDecl : public Statement {
public:
    enum class TypeName : int{
        error,
        integer,
        real
    };
    std::string     raw_name;
    TypeName        sys_name;

    TypeDecl(const std::string &str) 
        : raw_name(str), sys_name(TypeName::error) {}
    TypeDecl(const char * ptr_c) 
        : raw_name(*(new std::string(ptr_c))), sys_name(TypeName::error) {}
    void init() { 
        if (sys_name == TypeName::error && !raw_name.empty()) {
            if (raw_name == "integer") sys_name = TypeName::integer;
        }
    }
    
    llvm::Type* toLLVMType();
    virtual std::string toString() { return raw_name; }
    virtual llvm::Value* CodeGen(CodeGenContext& context);
};

class Identifier : public Expression {
public:
    std::string         name;

    Identifier(const std::string& name) : name(name) {}
    Identifier(const char * ptr_s) : name(*(new std::string(ptr_s))) {}
    virtual std::string toString() { return "Identifier: " + name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class VarDecl : public Statement {
public:
    Identifier*     name;
    TypeDecl*       type;

    VarDecl(Identifier* name, TypeDecl* type) : name(name), type(type) {}
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)name);
        list.push_back((Node *)type);
        return list;
    }
    std::string toString() { return "VarDecl: " + name->toString() + "-" + type->toString(); }
    virtual llvm::Value* CodeGen(CodeGenContext& context);
};

class FuncDecl : public Statement {

};

// Expression subclass 
class Block : public Expression {

};

class IntegerType : public Expression {
public:
    int val;

    IntegerType(int val): val(val) {}
    virtual std::string toString() { return [=]() {std::stringstream oss; oss << val; return oss.str(); }(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class RealType : public Expression {
public:
    float val;

    RealType(float val) : val(val) {}   
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};


class MethodCall : public Expression {
public:
    std::string callee;
    std::vector<Node *> args;

    //MethodCall(const std::string &callee, std::vector<Node *> &args);

    virtual llvm::Value *CodeGen(CodeGenContext& context) {}
};

class BinaryOperator : public Expression {
public:
    enum class OpType : int {
        plus,
        minus,
        div,
        mod,
        bit_and,
        bit_or
    };

    Expression *op1, *op2;
    OpType op;

    BinaryOperator(Expression* op1, OpType op, Expression* op2) :
        op1(op1),
        op(op),
        op2(op2)
    {}

    
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)op1);
        list.push_back((Node *)op2);
        return list;
    }
    virtual std::string toString() { 
        return "Binary op: " + [=]() -> std::string {
            switch (op) {
            case OpType::plus: return "plus";
            case OpType::minus: return "minus";
            }
        }(); 
    }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class AssignmentStmt : public Expression {
public:
    Identifier* lhs; // left-hand side
    Expression* rhs;

    AssignmentStmt(Identifier* lhs, Expression* rhs) : lhs(lhs), rhs(rhs) {}
    
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)lhs);
        list.push_back((Node *)rhs);
        return list;
    }
    virtual std::string toString() { return "Assignment"; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

// namespace ast end
}

#endif

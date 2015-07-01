#ifndef __AST_H__
#define __AST_H__

#include "llvm/IR/Value.h"
#include "llvm/IR/instruction.h"

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
class Expression;
class StatementList;
class CaseStmt;


typedef std::vector<VarDecl *>      VarDeclList;
typedef std::vector<Identifier *>   IdentifierList;
typedef std::vector<Routine *>      RoutineList;
typedef std::vector<std::string>    NameList;
typedef std::vector<Expression *>   ExpressionList;
typedef std::vector<CaseStmt *>     CaseList;
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
class Statement : public Node {
public:
    Statement() {};

    virtual llvm::Value *CodeGen(CodeGenContext& context) {}
};

class StatementList : public Statement{
public:
    std::vector<Statement*> list;
    virtual llvm::Value *CodeGen(CodeGenContext& context) {
        for (auto stmt: list){
            stmt->CodeGen(context);
        }
    }
    virtual std::string toString(){ return "stmt_list";}
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
        for(auto i : routine_body->list) list.push_back((Node *)i);
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
    StatementList*   routine_body;
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
        for(auto i : routine_body->list) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return routine_type == RoutineType::function ? "Function" : "Procedure"; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Expression : public Node {
public:
    virtual llvm::Value *CodeGen(CodeGenContext& context);
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
        real,
        character,
        boolean
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
            if (raw_name == "real") sys_name = TypeName::real;
            if (raw_name == "char") sys_name = TypeName::character;
            if (raw_name == "boolean") sys_name = TypeName::boolean;
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
    std::string toString() { return "VarDecl"; }
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
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class CharType : public Expression {
public:
    char val;

    CharType(const char * p_str) : val(*p_str) {}   
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class BooleanType : public Expression {
public:
    bool val;

    BooleanType(const char * str) : val(std::string(str) == "true" ? true : false) {}   
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};




class FuncCall : public Expression, public Statement {
public:
    Identifier* id;
    ExpressionList* argument_list;

    FuncCall(Identifier* id) : id(id), argument_list(nullptr) {}
    FuncCall(Identifier* id, ExpressionList* argument_list) : id(id), argument_list(argument_list) {}

    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)id);
        // list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        // for(auto i : *(var_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "FuncCall " + id->name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class ProcCall : public Statement {
public:
    Identifier* id;
    ExpressionList* argument_list;

    ProcCall(Identifier* id) : id(id), argument_list(nullptr) {}
    ProcCall(Identifier* id, ExpressionList* argument_list) : id(id), argument_list(argument_list) {}

    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        list.push_back((Node *)id);
        // list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        // for(auto i : *(var_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "ProcCall " + id->name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class SysProcCall : public ProcCall {
public:
    SysProcCall(Identifier* id) : ProcCall(id) {}
    SysProcCall(Identifier* id, ExpressionList* al) : ProcCall(id, al) {}

    llvm::Value* SysProc_write(CodeGenContext& context, bool writeln);
    
    virtual std::string toString() { return "System Porcedure Call " + id->name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class SysFuncCall : public FuncCall {
public:
    SysFuncCall(Identifier* id) : FuncCall(id) {}
    SysFuncCall(Identifier* id, ExpressionList* al) : FuncCall(id, al) {}

    virtual std::string toString() { return "System Function Call " + id->name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class BinaryOperator : public Expression {
public:
    enum class OpType : int {
        plus,
        minus,
        mul,
        div,
        mod,
        bit_and,
        bit_or,
        bit_xor,
        eq,
        ne,
        lt,
        gt,
        le,
        ge
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
            case OpType::eq:    return "equal";
            }
        }(); 
    }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class AssignmentStmt : public Statement {
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

class IfStmt : public Statement {
private:
    int instanceCount;
public:
    Expression* condition; 
    Statement* thenStmt; 
    Statement* elseStmt;
    IfStmt(Expression* condition,Statement* thenStmt,Statement* elseStmt) : condition(condition),thenStmt(thenStmt),elseStmt(elseStmt) {};
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "If"; }
};
class WhileStmt : public Statement {
public:
    Expression* condition;
    Statement* loopStmt;
    WhileStmt(Expression* condition,Statement* loopStmt):condition(condition),loopStmt(loopStmt){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "while"; }


};
class RepeatStmt : public Statement {
public:
    Expression* condition;
    Statement* loopStmt;
    RepeatStmt(Expression* condition,StatementList* loopStmt):condition(condition),loopStmt(loopStmt){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "repeat"; }


};
// namespace ast end
class ForStmt : public Statement {
public:
    Identifier* loopVar;
    Expression* startExp;
    Expression* endExp;
    int direction;
    Statement* loopStmt;
    ForStmt(Identifier* loopVar, Expression* startExp, Expression* endExp, int direction,Statement* loopStmt):
        loopVar(loopVar),
        startExp(startExp),
        endExp(endExp),
        loopStmt(loopStmt),
        direction(direction){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "for"; }
};
class CaseStmt : public Statement {
public:
    Expression* condition;
    Statement* thenStmt;
    llvm::BasicBlock* bblock,*bexit;
    CaseStmt(Expression* condition,Statement* thenStmt):condition(condition),thenStmt(thenStmt){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "case statement"; }
};
class SwitchStmt : public Statement {
public:
    Expression* exp;
    CaseList* list;
    SwitchStmt(Expression* exp,CaseList* list):exp(exp),list(list){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "switch statement"; }
};
class LabelStmt : public Statement {
public:
    int label;
    Statement* statement;
    LabelStmt(int label,Statement* statement):label(label),statement(statement){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "label statement"; }

};
class GotoStmt : public Statement {
public:
    int label;
    GotoStmt(int label):label(label){}
    virtual llvm::Value* CodeGen(CodeGenContext& context);
    virtual std::string toString() { return "label statement"; }

};
}
#endif


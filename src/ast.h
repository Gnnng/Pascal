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
class Expression;
class StatementList;
class IntegerType;
class RealType;
class CharType;
class BooleanType;
class RangeType;
class ArrayType;
class ConstValue;
class FieldDecl;
class RecordType;

typedef std::vector<VarDecl *>      VarDeclList;
typedef std::vector<Identifier *>   IdentifierList;
typedef std::vector<Routine *>      RoutineList;
typedef std::vector<std::string>    NameList;
typedef std::vector<Expression *>   ExpressionList;
typedef std::vector<ConstDecl *>    ConstDeclList;
typedef std::vector<FieldDecl *>    FieldDeclList;
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
            children_list[i] ? children_list[i]->print_node(ch_prefix, i == children_list.size() - 1, false) : []() {std::cout << "nullptr in tree";}();
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
    ConstDeclList*      const_part;
    TypeDecl*       type_part;
    VarDeclList*    var_part;
    RoutineList*    routine_part;
    StatementList*  routine_body;

    Program() {}
    Program(LabelDecl* lp, ConstDeclList* cp, TypeDecl* tp, VarDeclList* vp, RoutineList* rp, StatementList* rb) :
        lable_part(lp),
        const_part(cp),
        type_part(tp),
        var_part(vp),
        routine_part(rp),
        routine_body(rb) {}
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list;
        for(auto i : *(const_part)) list.push_back((Node *)i);
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
        for(auto i : *(const_part)) list.push_back((Node *)i);
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
class TypeDecl : public Statement {
public:
    enum class TypeName : int{
        error,
        integer,
        real,
        character,
        boolean,
        range,
        array,
        record
    };

    std::string     raw_name = "";
    TypeName        sys_name = TypeName::error;
    RangeType*      range_type = nullptr;
    ArrayType*      array_type = nullptr;
    RecordType*     record_type = nullptr;

    TypeDecl(ArrayType* atp) : array_type(atp) {}
    TypeDecl(RecordType* rtp) :  record_type(rtp) {}
    TypeDecl(RangeType* rtp) : range_type(rtp) {}
    TypeDecl(TypeName tpname) : sys_name(tpname) { std::cout << "TypeDecl TypeName tpname called" << std::endl; }
    TypeDecl(const std::string &str) : raw_name(str){}
    TypeDecl(const char * ptr_c) : raw_name(*(new std::string(ptr_c))) {}

    void init() { 
        std::cout << this << std::endl;
        if (sys_name != TypeName::error)
            return;
        if (raw_name == "integer")          sys_name = TypeName::integer;
        else if (raw_name == "real")        sys_name = TypeName::real;
        else if (raw_name == "char")        sys_name = TypeName::character;
        else if (raw_name == "boolean")     sys_name = TypeName::boolean;
        else if (range_type)                sys_name = TypeName::range;
        else if (array_type)                sys_name = TypeName::array;
        //else if (record_type)               sys_name = TypeName::record;
        else                                throw std::logic_error("Unimplemented type");
    }
    
    llvm::Type* toLLVMType();
    virtual std::string toString() { return raw_name; }
    virtual llvm::Value* CodeGen(CodeGenContext& context);
};

class ArrayType: public Statement {
public:
    TypeDecl*   subscript = nullptr;
    TypeDecl*   array_type = nullptr;

    ArrayType(TypeDecl* ss, TypeDecl* at) : subscript(ss), array_type(at) {}
    virtual std::string toString() { return "Array of " + (array_type ? array_type->raw_name : "#error"); }
    virtual llvm::Value* CodeGen(CodeGenContext& context) {}
};

class FieldDecl: public Statement {
public:
    Identifier* first;
    TypeDecl*   second; 
    FieldDecl(Identifier* first, TypeDecl* second) : first(first), second(second) {}
    virtual std::string toString() { return "FieldDecl"; }
    virtual llvm::Value* CodeGen(CodeGenContext& context) {}
};

class RecordType: public Statement {
public:
    FieldDeclList*      field_list;

    RecordType(FieldDeclList* list) : field_list(list)  {} 
    virtual std::string toString() { return "RecordType"; }
    virtual llvm::Value* CodeGen(CodeGenContext& context) {}
};

class ArrayRef : public Expression {
public:
    Identifier*     array = nullptr;
    Expression*     index = nullptr;

    ArrayRef(Identifier* array, Expression* index) : array(array), index(index) {}
    virtual std::string toString() { return "ArrayRef"; }
    virtual llvm::Value* CodeGen(CodeGenContext& context) {}
};

class RecordRef : public Expression {
public:
    Identifier*     record = nullptr;
    Identifier*     field = nullptr;

    RecordRef(Identifier* record, Identifier* field) : record(record), field(field) {}
    virtual std::string toString() { return "RecordRef"; }
    virtual llvm::Value* CodeGen(CodeGenContext& context) {}
};


class Identifier : public Expression {
public:
    std::string         name;

    Identifier(const std::string& name) : name(name) {}
    Identifier(const char * ptr_s) : name(*(new std::string(ptr_s))) {}
    virtual std::string toString() { return "Identifier: " + name; }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class ConstValue : public Expression {
public:
    virtual TypeDecl::TypeName getConstType() = 0;
    virtual int toRange() = 0;
    /* canRange : bool, if subclass can not be a range, overwrite it and return true  */
    virtual bool notRange() { return false; } 
};


class ConstDecl : public Statement {
public:
    Identifier*     name = nullptr;
    ConstValue*     val = nullptr;
    TypeDecl*       type = nullptr;

    ConstDecl(Identifier* name, ConstValue* cv)     : name(name), val(cv), type(new TypeDecl(val->getConstType())) {}
//
//    ConstDecl(Identifier* name, IntegerType* it)    : name(name), val((ConstValue *)it), type(new TypeDecl("integer")) {}
//    ConstDecl(Identifier* name, RealType* it)       : name(name), val((ConstValue *)it), type(new TypeDecl("real"))    {}
//    ConstDecl(Identifier* name, CharType* it)       : name(name), val((ConstValue *)it), type(new TypeDecl("char"))    {}
//    ConstDecl(Identifier* name, BooleanType* it)    : name(name), val((ConstValue *)it), type(new TypeDecl("boolean")) {}
    virtual std::vector<Node *> getChildren() { 
        std::vector<Node *> list; 
        list.push_back(name); 
        list.push_back(val);
        list.push_back(type);
        return list;
    }
    virtual std::string toString() { std::stringstream oss; oss << "Const " << name->name << ":" << val->toRange(); return oss.str(); }
    virtual llvm::Value* CodeGen(CodeGenContext& context);
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
class IntegerType : public ConstValue {
public:
    int val;

    IntegerType(int val): val(val) {}
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::integer; }
    virtual int toRange() { return val; }
    virtual std::string toString() { return [=]() {std::stringstream oss; oss << val; return oss.str(); }(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class RealType : public ConstValue {
public:
    float val;

    RealType(float val) : val(val) {}   

    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::real; }
    virtual int toRange() { return 0; }
    virtual bool notRange() { return true; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class CharType : public ConstValue {
public:
    char val;

    CharType(const char * p_str) : val(*(p_str)) {}   
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::character; }
    virtual int toRange() { return (int)val; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class BooleanType : public ConstValue {
public:
    int val;

    BooleanType(const char * str) : val(std::string(str) == "true" ? 1 : 0) {}   
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::boolean; }
    virtual int toRange() { return val; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class RangeType : public Expression {
public:
    //TypeDecl*       base_type; //TODO: distinguish int range, char range, boolean range
    int             low, high;
    std::string     low_s, high_s;
    bool            isNameRange = false;

    RangeType(int low, int high) : low(low), high(high) {}
    RangeType(std::string low_s, std::string high_s) : low_s(low_s), high_s(high_s), isNameRange(true) {}
    size_t size() { return high - low + 1; }
    virtual std::string toString() { std::stringstream oss; oss << "[" << low << "," << high << "]"; return oss.str(); }
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
        return "Binary op: " + (std::map<OpType, std::string>){
            { OpType::plus, "plus" },
            { OpType::minus, "minus" },
            { OpType::mul, "mul" },
            { OpType::div, "div" },
            { OpType::mod, "mod" },
            { OpType::bit_and, "bit_and" },
            { OpType::bit_or, "bit_or" },
            { OpType::bit_xor, "bit_xor" },
            { OpType::eq, "eq" },
            { OpType::ne, "ne" },
            { OpType::lt, "lt" },
            { OpType::gt, "gt" },
            { OpType::le, "le" },
            { OpType::ge, "ge" }
        }[op];
    }
    virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class AssignmentStmt : public Statement {
public:
    Identifier* lhs = nullptr; // left-hand side
    Expression* rhs = nullptr;
    bool        complex_assign = false;
    AssignmentStmt(Identifier* lhs, Expression* rhs) : lhs(lhs), rhs(rhs) {}
    AssignmentStmt(ArrayRef* lhs, Expression* rhs) : lhs((Identifier *)lhs), rhs(rhs), complex_assign(true) {}
    AssignmentStmt(RecordRef* lhs, Expression* rhs) : lhs((Identifier *)lhs), rhs(rhs), complex_assign(true) {}
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
}
#endif


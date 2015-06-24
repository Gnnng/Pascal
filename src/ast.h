#ifndef __AST_H__
#define __AST_H__

#include "llvm/IR/Value.h"

#include <string>
#include <map>
#include <vector>

// Delcaration
class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
class Statement;
class Identifier;

// pure virtual class for all ast nodes
class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value *Codegen() {}
	//virtual void print();

	std::string debug;
};

class Program : public Node {
public:
	LabelDecl* lable_part;
	ConstDecl* const_part;
	TypeDecl* type_part;
	VarDecl* var_part;

	Statement* stmt_list;

	Program() {};
	virtual ~Program() {};
	virtual llvm::Value *Codegen();
};

class Expression : public Node {
public:
	Expression() {};
	virtual ~Expression() {};
	virtual llvm::Value *Codegen();
};

class Statement : public Node {
public:
	Statement() {};
	virtual ~Statement() {};
	std::vector<Statement *> stmt_list;
	virtual llvm::Value *Codegen() {}
};

class LabelDecl : public Statement {

};

class ConstDecl : public Statement {

};

class TypeDecl : public Statement {
public:
	TypeDecl() {};
	TypeDecl(const std::string &str) {
		if (str == "integer")
			sys_type_name = TypeDecl::TypeName::integer;
		else
			sys_type_name = TypeDecl::TypeName::error;
	}
	virtual ~TypeDecl() {};
	enum class TypeName{
		error,
		integer,
		real
	};
	TypeName sys_type_name;
	virtual llvm::Value* Codegen();
};

class VarDecl : public Statement {
public:
	VarDecl() {};
	virtual ~VarDecl() {};
	// var_decl_list
	std::vector<VarDecl *> var_decl_list;

	// var_decl <- name_list COLON type_decl SEMI
	Identifier* names;
	TypeDecl* type;

	inline void addVar(VarDecl* v) {
		// add those variables 
	}
	virtual llvm::Value* Codegen();
};

class FuncDecl : public Statement {

};

// Expression subclass 
class Block : public Expression {

};

class IntegerType : public Expression {
public:
	int val;

	IntegerType(int val);// : val(val) {}
	virtual ~IntegerType() {}
	virtual llvm::Value *Codegen();
};

inline IntegerType::IntegerType(int val) : val(val) {

}

class RealType : public Expression {
public:
	float val;

	RealType(float val) : val(val) {}
	virtual ~RealType() {}
	virtual llvm::Value *Codegen();
};

class Identifier : public Expression {
public:
	std::string name;
	std::vector<Identifier *> name_list;

	Identifier(const char *) {
		name = *(new std::string(name));
	}
//	virtual ~Identifier() {}
	virtual llvm::Value *Codegen();
};

class MethodCall : public Expression {
	std::string callee;
	std::vector<Node *> args;
	MethodCall(const std::string &callee, std::vector<Node *> &args);
	virtual ~MethodCall() {}
	virtual llvm::Value *Codegen() {}
};

class BinaryOperator : public Expression {
public:
	enum class OpType {
		plus,
		minus,
		div,
		mod,
		bit_and,
		bit_or
	};

	BinaryOperator(Expression* op1, OpType op, Expression* op2) :
		op1(op1),
		op(op),
		op2(op2)
	{}
	virtual ~BinaryOperator() {}
	Expression *op1, *op2;
	OpType op;
	virtual llvm::Value *Codegen();
};

class AssignmentStmt : public Expression {
public:
	Identifier* lhs; // left-hand side
	Expression* rhs;
	AssignmentStmt(Identifier* lhs, Expression* rhs) : lhs(lhs), rhs(rhs) {}
	virtual ~AssignmentStmt() {}
	virtual llvm::Value *Codegen();
};

// Utility functions
llvm::Value *Error(const char *str);

#endif

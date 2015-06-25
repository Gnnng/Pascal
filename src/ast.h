#ifndef __AST_H__
#define __AST_H__

#include "llvm/IR/Value.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>

//used forward-declaration to deal with cross-reference issue
class CodeGenContext;

// Delcaration
namespace ast {

class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
class Statement;
class Identifier;
class Routine;

// pure virtual class for all ast nodes
class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context) = 0;
	
	virtual std::vector<Node *> getChildren() { return *(new std::vector<Node *>()); }

	void print_node(std::string prefix, bool tail, bool root) {
		std::string tailStr = "└── ";
		std::string branchStr = "├── ";
		std::string ch_tailStr = "    ";
		std::string ch_branchStr = "|   ";

		std::cout << (root ? prefix : (prefix + (tail ? tailStr : branchStr))) << (this->dummy ? "dummy node" : this->debug) << std::endl;

		auto children_list = this->getChildren();
		auto ch_prefix = tail ? prefix + ch_tailStr : prefix + ch_branchStr;
		for(size_t i = 0; i < children_list.size(); i++) {
			children_list[i] ? children_list[i]->print_node(ch_prefix, i == children_list.size() - 1, false) : []() {}();
		}
	}

	std::string debug;
	bool dummy;
};

class Program : public Node {
public:
	LabelDecl* 	lable_part;
	ConstDecl* 	const_part;
	TypeDecl* 	type_part;
	VarDecl* 	var_part;
	Routine* 	routine_part;

	Statement* 	routine_body;

	Program() {};
	virtual ~Program() {};
	virtual llvm::Value *CodeGen(CodeGenContext& context);
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
		list.push_back((Node *)var_part);
		list.push_back((Node *)routine_body);
		return list;
	}
};

class Routine : public Program {
public:
	enum class RoutineType {
		function,
		procedure,
		error,
	};

	// necessary section
	Identifier* routine_name;
	TypeDecl* 	return_type;
	// VarDecl* 	return_value;
	std::vector<VarDecl *> argument_list;
	RoutineType routine_type; // function or procedure 


	// for dummy node usage
	std::vector<Routine *> routine_list;

	virtual ~Routine() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context);
	bool isFunction() { return routine_type == RoutineType::function; }
	bool isProcedure() { return routine_type == RoutineType::procedure; }
};

class Expression : public Node {
public:
	Expression() {};
	virtual ~Expression() {};
	virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Statement : public Node {
public:
	Statement() {};
	virtual ~Statement() {};
	std::vector<Statement *> stmt_list;
	virtual llvm::Value *CodeGen(CodeGenContext& context) {}
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
        for(auto i: stmt_list) list.push_back((Node *)i);
		return list;
	}
};

class LabelDecl : public Statement {

};

class ConstDecl : public Statement {

};

class TypeDecl : public Statement {
public:
	TypeDecl() {};
	TypeDecl(const std::string &str) {
		// std::cout << "TypeDecl Ctor " << str << std::endl;
		this->debug = str;
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
	static std::map<TypeName, std::string> mapToString;
	
	llvm::Type* toLLVMType();
	virtual llvm::Value* CodeGen(CodeGenContext& context);
};


class VarDecl : public Statement {
public:
	VarDecl() {};
	virtual ~VarDecl() {};

	// for dummy usage
	std::vector<VarDecl *> var_decl_list;

	// var_decl <- name_list COLON type_decl SEMI
	void addVar(VarDecl* var_list);
	Identifier* name;
	TypeDecl* type;

	bool var_part;


	virtual llvm::Value* CodeGen(CodeGenContext& context);
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
		list.push_back((Node *)name);
		list.push_back((Node *)type);
		list.insert(list.end(),  var_decl_list.begin(), var_decl_list.end());
		return list;
	}
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
	virtual ~IntegerType() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class RealType : public Expression {
public:
	float val;

	RealType(float val) : val(val) {}
	virtual ~RealType() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context);
};

class Identifier : public Expression {
public:
	std::string name;
	std::vector<Identifier *> name_list;

	Identifier(const char *name) {
		this->name = *(new std::string(name));
		debug = this->name;
		//std::cout << "Calling Identifier Ctor " << debug << std::endl;
	}
//	virtual ~Identifier() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context);
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
		list.insert(list.end(),  name_list.begin(), name_list.end());
		return list;
	}
};

class MethodCall : public Expression {
	std::string callee;
	std::vector<Node *> args;
	MethodCall(const std::string &callee, std::vector<Node *> &args);
	virtual ~MethodCall() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context) {}
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
	virtual llvm::Value *CodeGen(CodeGenContext& context);
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
        list.push_back((Node *)op1);
        list.push_back((Node *)op2);
		return list;
	}
};

class AssignmentStmt : public Expression {
public:
	Identifier* lhs; // left-hand side
	Expression* rhs;
	AssignmentStmt(Identifier* lhs, Expression* rhs) : lhs(lhs), rhs(rhs) {}
	virtual ~AssignmentStmt() {}
	virtual llvm::Value *CodeGen(CodeGenContext& context);
	virtual std::vector<Node *> getChildren() { 
		std::vector<Node *> list;
        list.push_back((Node *)lhs);
        list.push_back((Node *)rhs);
		return list;
	}
};

// Utility functions

// namespace ast end
}

#endif

%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "ast.h"
#include "utils.h"
#include "parser.hpp"
#include "ccalc.h"
using namespace std;

int yydebug = 1;
ast::Node* ast_root;
%}
%union{
	char* 					debug;

    ast::Node* 				ast_Node; 
    ast::Statement* 		ast_Statement;
    ast::Expression* 		ast_Expression;
    ast::Program* 			ast_Program;
    ast::Routine* 			ast_Routine;
    ast::TypeDecl* 			ast_TypeDecl;
    ast::VarDecl* 			ast_VarDecl;
    ast::Identifier* 		ast_Identifier;
    ast::AssignmentStmt* 	ast_AssignmentStmt;

    ast::StatementList* 	ast_StatementList;
    ast::VarDeclList* 		ast_VarDeclList;
    ast::IdentifierList* 	ast_IdentifierList;
    ast::RoutineList* 		ast_RoutineList;
    ast::NameList* 			ast_NameList;
    ast::ExpressionList* 	ast_ExpressionList;
}

%token PROGRAM IDD DOT EQUAL LTHAN LEQU GT GE PLUS MINUS MUL DIV RIGHTP LEFTP 
%token ASSIGN COLON COMMA SEMI UNTIL OR AND MOD OF READ REPEAT TO UNEQUAL 
%token IF THEN ELSE WHILE DO BEGINN END CASE DOWNTO FOR GOTO INTEGER LB RB NOT 
%token NUMBER SYS_CON SYS_BOOL SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY 
%token VAR PROCEDURE RECORD FUNCTION TYPE

%start program

%type <debug> PROGRAM IDD DOT NAME EQUAL LTHAN LEQU GT GE PLUS MINUS MUL DIV 
%type <debug> ASSIGN COLON COMMA SEMI IF THEN ELSE WHILE DO BEGINN FUNCTION LB
%type <debug> NOT OR AND MOD OF READ REPEAT TO UNEQUAL UNTIL NUMBER SYS_CON RB
%type <debug> SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY VAR TYPE 
%type <debug> RIGHTP LEFTP DOWNTO FOR GOTO INTEGER PROCEDURE RECORD END CASE SYS_BOOL

// default type is ast node
%type <ast_Node> label_part const_part const_expr_list const_value field_decl 
%type <ast_Node> field_decl_list record_type_decl array_type_decl 
%type <ast_Node> type_definition 
%type <ast_Node> case_stmt 
%type <ast_Node> case_expr_list case_expr goto_stmt 

%type <ast_Program> 		program program_head routine routine_head sub_routine
%type <ast_TypeDecl> 		type_part type_decl type_decl_list simple_type_decl 
%type <ast_Statement> 		proc_stmt stmt non_label_stmt else_clause for_stmt repeat_stmt while_stmt if_stmt
%type <ast_AssignmentStmt> 	assign_stmt 
%type <ast_Expression> 		expression expr term factor 
%type <ast_Routine> 		function_decl function_head procedure_head procedure_decl
%type <ast_VarDeclList> 	parameters para_decl_list para_type_list
%type <ast_RoutineList> 	routine_part 
%type <ast_StatementList> 	routine_body compound_stmt stmt_list 
%type <ast_VarDeclList> 	var_part var_decl_list var_decl
%type <ast_NameList> 		name_list
%type <ast_ExpressionList>  expression_list

%%

NAME: IDD 										{ $$ = $1; };

program: program_head routine DOT 				{ ast_root = $2; };
program_head: PROGRAM IDD SEMI {} | {};

routine: // ast_Program
	routine_head routine_body 					{ $$ = $1; $$->routine_body = $2; /*$$->print_node("", true, true);*/ }
;

sub_routine: // ast_Program
	routine_head routine_body 					{ $$ = $1; $$->routine_body = $2; }
;

routine_head: //ast_Program
	//label_part const_part type_part var_part routine_part { 
	var_part routine_part { 
		$$ = new ast::Program(nullptr, nullptr, nullptr, $1, $2, nullptr); 
	}
;

label_part: 									{ $$ = ast_dbg("empty label_part"); }
;

const_part:
	CONST const_expr_list {
		$$ = ast_newNode2(ast_dbg($1), $2);
		$$->debug = "const_part";
	}
	| 											{ $$ = ast_dbg("empty const_part"); }
;

const_expr_list:
	const_expr_list NAME EQUAL const_value SEMI { 
		// printf("in const_expr_list recursively\n");
		$$ = ast_newNode5($1, ast_dbg($2), ast_dbg($3), $4, ast_dbg($5)); $$->debug = "const_expr_list";}
	| NAME EQUAL const_value SEMI {
		// printf("in const_expr_list\n");
		$$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4));$$->debug = "const_expr_list"; }
;

const_value:
	INTEGER 									{ $$ = new ast::IntegerType(atoi($1)); $$->debug = $1; }
	| REAL 										{ $$ = new ast::RealType(atof($1)); $$->debug = $1; }
	| CHAR 										{ $$ = new ast::CharType($1+1); $$->debug = $1; }
//	| STRING 					{ $$ = ast_dbg($1);}
	| SYS_BOOL									{ $$ = new ast::BooleanType($1); }
//	| SYS_CON
;


type_part:
	TYPE type_decl_list 						{ $$ = ast_dbg($1); $$->debug = "type_part";}
	|											{ $$ = ast_dbg("empty type_part");}
;

type_decl_list:
	type_decl_list type_definition 				{ $$ = ast_newNode2($1, $2);$$->debug = "type_decl_list";}
	| type_definition							{ $$ = ast_newNode1($1);$$->debug = "type_decl_list";}
;

type_definition:
	IDD EQUAL type_decl SEMI 					{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4));$$->debug = "type_definition";}
;

type_decl:
	simple_type_decl 							{ $$ = $1; }
//	| array_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
//	| record_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
;

simple_type_decl:
	SYS_TYPE									{ $$ = new ast::TypeDecl($1); }
//	| NAME  					{ $$ = ast_dbg($1); $$->debug = "simple_type_decl";}
//	| LEFTP name_list RIGHTP 			{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "simple_type_decl";}
//	| const_value DOT DOT const_value 				{ $$ = ast_newNode4($1, ast_dbg($2), ast_dbg($3), $4);$$->debug = "simple_type_decl";}
//	| MINUS const_value DOT DOT const_value			{ $$ = ast_newNode5(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), $5);$$->debug = "simple_type_decl";}
//	| MINUS const_value DOT DOT MINUS const_value 	{ $$ = ast_newNode6(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), ast_dbg($5), $6);$$->debug = "simple_type_decl";}
//	| NAME DOT DOT NAME 		{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), ast_dbg($3), ast_dbg($4));$$->debug = "simple_type_decl";}
;

array_type_decl:
	ARRAY LB simple_type_decl RB OF type_decl 	{ $$ = ast_newNode6(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4), ast_dbg($5), $6); $$->debug = "array_type_decl";}
;

record_type_decl:
	RECORD field_decl_list END 					{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "record_type_decl";}
;

field_decl_list:
	field_decl_list field_decl 					{ $$ = ast_newNode2($1, $2);$$->debug = "field_decl_list";}
	| field_decl 								{ $$ = ast_newNode1($1); $$->debug = "field_decl_list";}
;

field_decl:
	name_list COLON type_decl SEMI 				{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));$$->debug = "field_decl";}
;

name_list: // ast_NameList
	name_list COMMA IDD 						{ $$ = $1; $$->push_back($3); }
	| IDD 										{ $$ = new ast::NameList(); $$->push_back($1); }
;

var_part:
	VAR var_decl_list 							{ $$ = $2; }
	|  											{ $$ = new ast::VarDeclList(); }
;

var_decl_list:
	var_decl_list var_decl 						{ $$ = $1; $1->insert($1->end(), $2->begin(), $2->end()); }
	| var_decl 									{ $$ = $1; }
;

var_decl:
	name_list COLON type_decl SEMI { $$ = new ast::VarDeclList(); for(auto name : *($1)) $$->push_back(new ast::VarDecl(new ast::Identifier(name), $3)); }
;

routine_part:
	routine_part function_decl 					{ $$ = $1; $1->push_back($2); }
	| routine_part procedure_decl 				{ $$ = $1; $1->push_back($2); }
	| 											{ $$ = new ast::RoutineList(); }
;

function_decl:
	function_head SEMI sub_routine SEMI 		{ $$ = new ast::Routine($1, $3); }
;

function_head:
	FUNCTION IDD parameters COLON simple_type_decl { $$ = new ast::Routine(ast::Routine::RoutineType::function, new ast::Identifier($2), $3, $5); }
;

procedure_decl:
	procedure_head SEMI sub_routine SEMI 		{ $$ = new ast::Routine($1, $3); }
;

procedure_head:
	PROCEDURE IDD parameters 					{ $$ = new ast::Routine(ast::Routine::RoutineType::procedure, new ast::Identifier($2), $3, nullptr); }
;

parameters:
	LEFTP para_decl_list RIGHTP 				{ $$ = $2; }
	| LEFTP RIGHTP 								{ $$ = new ast::VarDeclList(); }
	| 											{ $$ = new ast::VarDeclList(); }
;

para_decl_list:
	para_decl_list SEMI para_type_list 			{ $$ = $1; $1->insert($1->end(), $3->begin(), $3->end()); }
	| para_type_list 							{ $$ = $1; }
;

para_type_list: //TODO: var is different
	VAR name_list COLON simple_type_decl 		{ $$ = new ast::VarDeclList(); for(auto name: *($2)) $$->push_back(new ast::VarDecl(new ast::Identifier(name), $4)); }
	| name_list COLON simple_type_decl 			{ $$ = new ast::VarDeclList(); for(auto name: *($1)) $$->push_back(new ast::VarDecl(new ast::Identifier(name), $3)); }
;

//
//var_para_list:
//	VAR name_list 				{ $$ = ast_newNode2(ast_dbg($1), $2); $$->debug = "var_para_list";}
//;
//
//val_para_list:
//	name_list 					{ $$ = ast_newNode1($1); $$->debug = "val_para_list";}
//;

// boundary
routine_body:  
	compound_stmt { $$ = $1; }
;

compound_stmt : 
	BEGINN stmt_list END { $$ = $2; }
;

stmt_list : 
	stmt_list stmt 								{yyerror("expected ';' at the end of the last line"); }
	| stmt_list  stmt  SEMI 					{ $$ = $1; $1->list.push_back($2);}
	| 											{ $$ = new ast::StatementList(); }
;

stmt: 
	non_label_stmt 								{ $$ = $1; }
	//| INTEGER  COLON  non_label_stmt { 
		//$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),$3);$$->debug = "stmt";
	//}
;
non_label_stmt : 
	error
	|assign_stmt { $$ = (ast::Statement *)$1; }
	| proc_stmt 								{ $$ = (ast::Statement *) $1; }	
	| compound_stmt 				{ $$ = $1;}
	| if_stmt 						{ $$ = (ast::Statement *)$1;}		
	| repeat_stmt 					{ $$ = (ast::Statement *)$1;}
	| while_stmt					{ $$ = (ast::Statement *)$1;}	
	| for_stmt						{ $$ = (ast::Statement *)$1;}
//	| case_stmt 					{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}	
//	| goto_stmt						{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}
;

assign_stmt : 

	IDD  ASSIGN  expression 					{ $$ = new ast::AssignmentStmt(new ast::Identifier($1), $3); }
	//| ID LB expression RB ASSIGN expression     { $$ = ast_newNode6(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4),ast_dbg($5),$6);$$->debug = "assign_stmt";} 
	//| ID  DOT  ID  ASSIGN  expression           { $$ = ast_newNode5(ast_dbg($1),ast_dbg($2),ast_dbg($3),ast_dbg($4),$5);$$->debug = "assign_stmt";} 
;

proc_stmt : 
	IDD                   						{ $$ = new ast::ProcCall(new ast::Identifier($1)); }
	|  IDD  LEFTP  expression_list  RIGHTP 		{ $$ = new ast::ProcCall(new ast::Identifier($1), $3); }
	|  SYS_PROC									{ $$ = new ast::SysProcCall(new ast::Identifier($1)); }
	|  SYS_PROC  LEFTP  expression_list  RIGHTP { $$ = new ast::SysProcCall(new ast::Identifier($1), $3); }
//	|  READ  LEFTP  factor  RIGHTP 			    { $$ = new ast::SysProcCall(new ast::Identifier($1), $3); }

// TODO: if_stmt may contains a shift/reduce conflict
if_stmt : 
	IF  expression THEN stmt else_clause 		{ $$ = (ast::Statement*)new ast::IfStmt($2,$4,$5);}
;

else_clause : 
	ELSE stmt 									{ $$ = $2;}
	| 											{ $$ = nullptr;}
;

repeat_stmt : 
	REPEAT  stmt_list  UNTIL  expression        { $$ = (ast::Statement*)new ast::RepeatStmt($4,$2);}
;
while_stmt : 
	WHILE  expression  DO stmt                  { $$ = (ast::Statement*)new ast::WhileStmt($2,$4);}
;
for_stmt : 
	FOR  IDD  ASSIGN  expression  TO  expression  DO stmt 	{
		$$ = new ast::ForStmt(new ast::Identifier($2), $4,$6,1,$8); 
	}
	|FOR  IDD  ASSIGN  expression  DOWNTO  expression  DO stmt 	{ 
		$$ = new ast::ForStmt(new ast::Identifier($2), $4,$6,0,$8); 
	}
;
case_stmt : 
	CASE expression OF case_expr_list  END		{ $$ = ast_newNode5(ast_dbg($1),$2,ast_dbg($3),$4,ast_dbg($5));$$->debug = "case_stmt";}
;
case_expr_list : 
	case_expr_list  case_expr  					{ $$ = ast_newNode2($1,$2);$$->debug = "case_expr_list";}
	|  case_expr 								{ $$ = ast_newNode1($1);$$->debug = "case_expr_list";}
;
case_expr : 
	const_value  COLON  stmt  SEMI				{ $$ = ast_newNode4($1,ast_dbg($2),$3,ast_dbg($4));$$->debug = "case_expr";}
	|  IDD  COLON  stmt  SEMI					{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "case_expr";}
;
goto_stmt : 
	GOTO  INTEGER 								{$$ = ast_newNode2(ast_dbg($1),ast_dbg($2));$$->debug = "goto_stmt";}
;

expression_list: 
	expression_list COMMA expression   			{ $$ = $1; $1->push_back($3); }
	|  expression 								{ $$ = new ast::ExpressionList(); $$->push_back($1); }

expression:
	error
	|expr { $$ = $1; }
	|  expression  GE  expr  					{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::ge, $3);}
	|  expression  GT  expr  					{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::gt, $3);}
	|  expression  LEQU  expr 					{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::le, $3);}
    |  expression  LTHAN  expr  				{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::lt, $3);}
	|  expression  EQUAL  expr  				{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::eq, $3);}                 
	|  expression  UNEQUAL  expr  				{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::ne, $3);}	
;

expr: 
	expr PLUS term {$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::plus, $3); }
	|  expr  MINUS  term  						{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::minus, $3);}	
	|  expr  OR  term  							{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::bit_or, $3);}
	|  term { $$ = $1; }
;

term: 
	error
	|  factor { $$ = $1; }
	|  term  MUL  factor  						{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::mul, $3);}
	|  term  DIV  factor  						{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::div, $3);}
	|  term  MOD  factor 						{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::mod, $3);}
 	|  term  AND  factor  						{$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::bit_and, $3);}
;

factor: 
	NAME 										{ $$ = new ast::Identifier($1); }
	|  NAME LEFTP expression_list RIGHTP		{ $$ = new ast::FuncCall(new ast::Identifier($1), $3); }
	|  SYS_FUNCT 								{ $$ = new ast::SysFuncCall(new ast::Identifier($1)); }
    |  SYS_FUNCT LEFTP expression_list RIGHTP 	{ $$ = new ast::SysFuncCall(new ast::Identifier($1), $3); }
	|  const_value 								{ $$ = (ast::Expression *)$1; };
	|  LEFTP  expression  RIGHTP 				{ $$ = (ast::Expression *)$2; }
	|  NOT  factor  							{ $$ = new ast::BinaryOperator(/*need to be bool type*/new ast::IntegerType(1), ast::BinaryOperator::OpType::bit_xor, $2);}
	|  MINUS  factor  							{$$ = new ast::BinaryOperator(new ast::IntegerType(0), ast::BinaryOperator::OpType::minus, $2);}
//	|  IDD  LB  expression  RB 					{$$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "factor";}
//	|  IDD  DOT  IDD 								{$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),ast_dbg($3));$$->debug = "factor";}
;

//args_list : 
//	args_list  COMMA  expression  {  
//	|  expression 				  { $$ = new ast::Exp
//;
%%



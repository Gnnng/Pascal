%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "ast.h"
#include "utils.h"
#include "parser.hpp"

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
%token NUMBER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY 
%token VAR PROCEDURE RECORD FUNCTION TYPE

%start program

%type <debug> PROGRAM IDD DOT NAME EQUAL LTHAN LEQU GT GE PLUS MINUS MUL DIV 
%type <debug> ASSIGN COLON COMMA SEMI IF THEN ELSE WHILE DO BEGINN FUNCTION LB
%type <debug> NOT OR AND MOD OF READ REPEAT TO UNEQUAL UNTIL NUMBER SYS_CON RB
%type <debug> SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY VAR TYPE 
%type <debug> RIGHTP LEFTP DOWNTO FOR GOTO INTEGER PROCEDURE RECORD END CASE 

// default type is ast node
%type <ast_Node> label_part const_part const_expr_list const_value 
%type <ast_Node> procedure_head procedure_decl field_decl 
%type <ast_Node> field_decl_list record_type_decl array_type_decl 
%type <ast_Node> type_definition proc_stmt if_stmt else_clause 
%type <ast_Node> repeat_stmt while_stmt for_stmt direction case_stmt 
%type <ast_Node> case_expr_list case_expr goto_stmt 

%type <ast_Program> 		program program_head routine routine_head sub_routine
%type <ast_TypeDecl> 		type_part type_decl type_decl_list simple_type_decl 
%type <ast_Statement> 		stmt non_label_stmt
%type <ast_AssignmentStmt> 	assign_stmt
%type <ast_Expression> 		expression expr term factor 
%type <ast_Routine> 		function_decl function_head 

%type <ast_VarDeclList> 	parameters para_decl_list para_type_list
%type <ast_RoutineList> 	routine_part
%type <ast_StatementList> 	routine_body compound_stmt stmt_list
%type <ast_VarDeclList> 	var_part var_decl_list var_decl
%type <ast_NameList> 		name_list
%type <ast_ExpressionList>  expression_list

%%

NAME: IDD { $$ = $1; };

program: program_head routine DOT { ast_root = $2; };
program_head: PROGRAM IDD SEMI {} | {};

routine: // ast_Program
	routine_head routine_body { $$ = $1; $$->routine_body = $2; $$->print_node("", true, true); }
;

sub_routine: // ast_Program
	routine_head routine_body { $$ = $1; $$->routine_body = $2; $$->print_node("SUB_ROUTINE ", true, true); }
;

routine_head: //ast_Program
	//label_part const_part type_part var_part routine_part { 
	var_part routine_part { 
		$$ = new ast::Program(nullptr, nullptr, nullptr, $1, $2, nullptr); 
	}
;

label_part: 					{ $$ = ast_dbg("empty label_part"); }
;

const_part:
	CONST const_expr_list {
		$$ = ast_newNode2(ast_dbg($1), $2);
		$$->debug = "const_part";
	}
	| 							{ $$ = ast_dbg("empty const_part"); }
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
	INTEGER { 
		$$ = new ast::IntegerType(atoi($1));
		$$->debug = $1;
	}
//	| REAL 						{ $$ = ast_dbg($1);}
//	| CHAR 						{ $$ = ast_dbg($1);}
//	| STRING 					{ $$ = ast_dbg($1);}
//	| SYS_CON					{ $$ = ast_dbg($1);}
;


type_part:
	TYPE type_decl_list 		{ $$ = ast_dbg($1); $$->debug = "type_part";}
	|							{ $$ = ast_dbg("empty type_part");}
;

type_decl_list:
	type_decl_list type_definition { $$ = ast_newNode2($1, $2);$$->debug = "type_decl_list";}
	| type_definition			{ $$ = ast_newNode1($1);$$->debug = "type_decl_list";}
;

type_definition:
	IDD EQUAL type_decl SEMI 	{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4));$$->debug = "type_definition";}
;

type_decl:
	simple_type_decl { $$ = $1; }
//	| array_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
//	| record_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
;

simple_type_decl:
	SYS_TYPE { $$ = new ast::TypeDecl($1); }
//	| NAME  					{ $$ = ast_dbg($1); $$->debug = "simple_type_decl";}
//	| LEFTP name_list RIGHTP 			{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "simple_type_decl";}
//	| const_value DOT DOT const_value 				{ $$ = ast_newNode4($1, ast_dbg($2), ast_dbg($3), $4);$$->debug = "simple_type_decl";}
//	| MINUS const_value DOT DOT const_value			{ $$ = ast_newNode5(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), $5);$$->debug = "simple_type_decl";}
//	| MINUS const_value DOT DOT MINUS const_value 	{ $$ = ast_newNode6(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), ast_dbg($5), $6);$$->debug = "simple_type_decl";}
//	| NAME DOT DOT NAME 		{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), ast_dbg($3), ast_dbg($4));$$->debug = "simple_type_decl";}
;

array_type_decl:
	ARRAY LB simple_type_decl RB OF type_decl 		{ $$ = ast_newNode6(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4), ast_dbg($5), $6); $$->debug = "array_type_decl";}
;

record_type_decl:
	RECORD field_decl_list END 	{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "record_type_decl";}
;

field_decl_list:
	field_decl_list field_decl 	{ $$ = ast_newNode2($1, $2);$$->debug = "field_decl_list";}
	| field_decl 				{ $$ = ast_newNode1($1); $$->debug = "field_decl_list";}
;

field_decl:
	name_list COLON type_decl SEMI 					{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));$$->debug = "field_decl";}
;

name_list: // ast_NameList
	name_list COMMA IDD { $$ = $1; $$->push_back($3); }
	| IDD 				{ $$ = new ast::NameList(); $$->push_back($1); }
;

var_part:
	VAR var_decl_list 	{ $$ = $2; }
	|  					{ $$ = new ast::VarDeclList(); }
;

var_decl_list:
	var_decl_list var_decl { $$ = $1; $1->insert($1->end(), $1->begin(), $1->end()); }
	| var_decl { $$ = $1; }
;

var_decl:
	name_list COLON type_decl SEMI { 
		$$ = new ast::VarDeclList();
		for(auto name : *($1))
			$$->push_back(new ast::VarDecl(new ast::Identifier(name), $3));
	}
;

routine_part:
	routine_part function_decl  { $$ = $1; $1->push_back($2); }
//	| routine_part procedure_decl 					{ $$ = ast_newNode2($1, $2);$$->debug = "routine_part";}
//	| procedure_decl			{ $$ = ast_newNode1($1);$$->debug = "routine_part";}
//	| function_decl				{ $$ = ast_newNode1($1);$$->debug = "routine_part";}
	| 							{ $$ = new ast::RoutineList(); }
;

function_decl:
	function_head SEMI sub_routine SEMI { $$ = new ast::Routine($1, $3); }
;

function_head:
	FUNCTION IDD parameters COLON simple_type_decl { 
		$$ = new ast::Routine(ast::Routine::RoutineType::function, new ast::Identifier($2), $3, $5);
	}
;

procedure_decl:
	procedure_head SEMI sub_routine SEMI 			{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4)); $$->debug = "procedure_decl";}
;

procedure_head:
	PROCEDURE IDD parameters 						{ $$ = ast_newNode3(ast_dbg($1), ast_dbg($2), $3);$$->debug = "procedure_head";}
;

parameters:
	LEFTP para_decl_list RIGHTP { $$ = $2; }
	| LEFTP RIGHTP { $$ = new ast::VarDeclList(); }
	| { $$ = new ast::VarDeclList(); }
;

para_decl_list:
	para_decl_list SEMI para_type_list { $$ = $1; $1->insert($1->end(), $3->begin(), $3->end()); }
	| para_type_list { $$ = $1; }
;

para_type_list: //TODO: var is different
	VAR name_list COLON simple_type_decl {
		$$ = new ast::VarDeclList();
		for(auto name: *($2)) $$->push_back(new ast::VarDecl(new ast::Identifier(name), $4));
	}
	| name_list COLON simple_type_decl {
		$$ = new ast::VarDeclList();
		for(auto name: *($1)) $$->push_back(new ast::VarDecl(new ast::Identifier(name), $3));
	}
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
	stmt_list stmt {
		//yyerror("SEMI error");
	}
	| stmt_list  stmt  SEMI { $$ = $1; $1->push_back($2); }
	| { $$ = new ast::StatementList(); }
;

stmt: 
	non_label_stmt { $$ = $1; }
	//| INTEGER  COLON  non_label_stmt { 
		//$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),$3);$$->debug = "stmt";
	//}
;
non_label_stmt : 
	assign_stmt { $$ = (ast::Statement *)$1; }
//	| proc_stmt 					{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}	
//	| compound_stmt 				{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}
//	| if_stmt 						{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}		
//	| repeat_stmt 					{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}
//	| while_stmt					{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}	
//	| for_stmt						{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}
//	| case_stmt 					{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}	
//	| goto_stmt						{ $$ = ast_newNode1($1);$$->debug = "non_label_stmt";}
;

assign_stmt :  
	IDD  ASSIGN  expression { $$ = new ast::AssignmentStmt(new ast::Identifier($1), $3); }
	//| ID LB expression RB ASSIGN expression     { $$ = ast_newNode6(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4),ast_dbg($5),$6);$$->debug = "assign_stmt";} 
	//| ID  DOT  ID  ASSIGN  expression           { $$ = ast_newNode5(ast_dbg($1),ast_dbg($2),ast_dbg($3),ast_dbg($4),$5);$$->debug = "assign_stmt";} 
;

proc_stmt : 
	IDD                   						{ $$ = ast_dbg($1);$$->debug = "proc_stmt";}
	|  IDD  LEFTP  expression_list  RIGHTP 		{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}
	|  SYS_PROC									{ $$ = ast_dbg($1);$$->debug = "proc_stmt";}
	|  SYS_PROC  LEFTP  expression_list  RIGHTP        { $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}

	|  READ  LEFTP  factor  RIGHTP 					{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}
     
;

// TODO: if_stmt may contains a shift/reduce conflict
if_stmt : 
	IF  expression THEN stmt else_clause 			{ $$ = ast_newNode5(ast_dbg($1),$2,ast_dbg($3),$4, $5);$$->debug = "if_stmt";}
;

else_clause : 
	ELSE stmt 									{ $$ = ast_newNode2(ast_dbg($1),$2);$$->debug = "else_clause";}
	| 											{ $$ = ast_dbg("empty else_clause");}
;

repeat_stmt : 
	REPEAT  stmt_list  UNTIL  expression        { $$ = ast_newNode4(ast_dbg($1),$2,ast_dbg($3),$4);$$->debug = "repeat_stmt";}
;
while_stmt : 
	WHILE  expression  DO stmt                  { $$ = ast_newNode4(ast_dbg($1),$2,ast_dbg($3),$4);$$->debug = "while_stmt";}
;
for_stmt : 
	FOR  IDD  ASSIGN  expression  direction  expression  DO stmt 	{ $$ = ast_newNode8(ast_dbg($1),ast_dbg($2),ast_dbg($3),$4,$5,$6,ast_dbg($7),$8);$$->debug = "for_stmt";}
;
direction : 
	TO 											{ $$ = ast_dbg($1);$$->debug = "direction";}
	| DOWNTO									{ $$ = ast_dbg($1);$$->debug = "direction";}	
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
	expr { $$ = $1; }
//	|  expression  GE  expr  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  GT  expr  					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  LEQU  expr 					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//    |  expression  LTHAN  expr  					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  EQUAL  expr  				{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  UNEQUAL  expr  				{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}	
;

expr: 
	expr PLUS term {$$ = new ast::BinaryOperator($1, ast::BinaryOperator::OpType::plus, $3); }
//	|  expr  MINUS  term  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expr";}	
//	|  expr  OR  term  							{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expr";}
	|  term { $$ = $1; }
;

term: 
	factor { $$ = $1; }
//	|  term  MUL  factor  							{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
//	|  term  DIV  factor  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
//	|  term  MOD  factor 						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
// 	|  term  AND  factor  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
;

factor: 
	NAME { $$ = new ast::Identifier($1); }
	|  NAME LEFTP expression_list RIGHTP { $$ = new ast::MethodCall(new ast::Identifier($1), $3); }
//	|  SYS_FUNCT 
//  |  SYS_FUNCT  LEFTP  args_list  RIGHTP  	{$$ = ast_newNode5(ast_dbg($1),ast_dbg($2),ast_dbg($3),$4,ast_dbg($5));$$->debug = "factor";}
	|  const_value { $$ = (ast::Expression *)$1; };
//	|  LEFTP  expression  RIGHTP 						{$$ = ast_newNode3(ast_dbg($1),$2,ast_dbg($3));$$->debug = "factor";}
//	|  NOT  factor  							{$$ = ast_newNode2(ast_dbg($1),$2);$$->debug = "factor";}
//	|  MINUS  factor  							{$$ = ast_newNode2(ast_dbg($1),$2);$$->debug = "factor";}
//	|  IDD  LB  expression  RB 					{$$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "factor";}
//	|  IDD  DOT  IDD 								{$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),ast_dbg($3));$$->debug = "factor";}
;

//args_list : 
//	args_list  COMMA  expression  {  
//	|  expression 				  { $$ = new ast::Exp
//;
%%



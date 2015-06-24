%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>

#include "ast.h"
#include "utils.h"
#include "parser.hpp"

int yydebug = 1;
Node* ast_root;
using namespace std;
%}

%union{
    Node* 				ast_Node; 
    Statement* 			ast_Statement;
    Expression* 		ast_Expression;
    Program* 			ast_Program;
    TypeDecl* 			ast_TypeDecl;
    VarDecl* 			ast_VarDecl;
    Identifier* 		ast_Identifier;
    AssignmentStmt* 	ast_AssignmentStmt;
}

%token PROGRAM ID DOT
%token EQUAL
%token LT
%token LE
%token GT
%token GE
%token PLUS
%token MINUS
%token MUL
%token DIV
%token RP
%token LP
%token ASSIGN
%token COLON COMMA SEMI
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token BEGINN END
%token CASE 
%token DOWNTO
%token FOR
%token GOTO
%token INTEGER
%token LB RB
%token NOT OR AND MOD
%token OF
%token READ REPEAT TO UNEQUAL UNTIL
%token NUMBER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE
%token CHAR CONST STRING REAL
%token ARRAY VAR PROCEDURE RECORD FUNCTION TYPE 
%start program

// default type is ast node
%type <ast_Node> sub_routine label_part const_part
%type <ast_Node> const_expr_list const_value 
%type <ast_Node> procedure_head para_type_list var_para_list val_para_list
%type <ast_Node> para_decl_list parameters procedure_decl function_decl function_head
%type <ast_Node> routine_part field_decl field_decl_list
%type <ast_Node> record_type_decl array_type_decl type_definition 
%type <ast_Node> proc_stmt if_stmt else_clause repeat_stmt while_stmt for_stmt
%type <ast_Node> direction case_stmt case_expr_list case_expr goto_stmt expression_list
%type <ast_Node> args_list

%type <ast_Program> 		program program_head routine routine_head 
%type <ast_TypeDecl> 		type_part type_decl type_decl_list simple_type_decl 
%type <ast_VarDecl> 		var_part var_decl_list var_decl
%type <ast_Statement> 		routine_body compound_stmt stmt_list stmt non_label_stmt
%type <ast_Identifier>		name_list
%type <ast_AssignmentStmt> 	assign_stmt
%type <ast_Expression> 		expression expr term factor 

%type <debug> PROGRAM ID DOT NAME
%type <debug> EQUAL
%type <debug> LT
%type <debug> LE
%type <debug> GT
%type <debug> GE
%type <debug> PLUS
%type <debug> MINUS
%type <debug> MUL
%type <debug> DIV
%type <debug> RP
%type <debug> LP
%type <debug> ASSIGN
%type <debug> COLON COMMA SEMI
%type <debug> IF
%type <debug> THEN
%type <debug> ELSE
%type <debug> WHILE
%type <debug> DO
%type <debug> BEGINN END
%type <debug> CASE 
%type <debug> DOWNTO
%type <debug> FOR
%type <debug> GOTO
%type <debug> INTEGER
%type <debug> LB RB
%type <debug> NOT OR AND MOD
%type <debug> OF
%type <debug> READ REPEAT TO UNEQUAL UNTIL
%type <debug> NUMBER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE
%type <debug> CHAR CONST STRING REAL
%type <debug> ARRAY VAR PROCEDURE RECORD FUNCTION TYPE 
%%

NAME:
	ID {
		$$ = $1;
	}
;

program:
	program_head routine DOT { 
		ast_root = $2;
		//$$ = ast_newNode3($1, $2, ast_dbg($3));
		//$$->debug = "Start point";
		//ast_travel($$);
	}
;

program_head:
	PROGRAM ID SEMI {
		//$$ = new Program();
		//$$ = ast_newNode3(ast_dbg($1), ast_dbg($2), ast_dbg($3));
		//$$->debug = "program_head";
	}
	| {
		//$$ = new Program();
		//$$ = ast_dbg("empty program_head");
	}
;

routine:
	// TODO routine_head routine_body
	routine_head routine_body {
		$$ = new Program();
		$$->var_part = $1->var_part;
		$$->stmt_list = $2;
		delete $1;
		//$$ = ast_newNode2($1,$2);$$->debug = "routine";
	}
;

sub_routine:
	routine_head routine_body{ $$ = ast_newNode2($1,$2);$$->debug = "sub_routine";}
;

routine_head:
	// TODO add routine_part will generate error: fatal error: symbol program does not derive any sentences
	//label_part const_part type_part var_part routine_part { 
	var_part {
		$$ = new Program();
		$$->debug = "Routine top level";
		//$$->label_part = $1;
		//$$->const_part = $2;
		//$$->type_part = $3;
		$$->var_part = $1;
		cerr << "routine_head parsed" << endl;
		//TODO: route_part's ast node not implemented
		//$$->routine_part = $5

//		$$ = ast_newNode5($1, $2, $3, $4, $5);
//		$$->debug = "routine_head";
	}
	/* routine_part  */
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
		$$ = new IntegerType(atoi($1));
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
	ID EQUAL type_decl SEMI 	{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4));$$->debug = "type_definition";}
;

type_decl:
	simple_type_decl { 
		$$ = $1;
		//$$ = ast_newNode1($1);$$->debug = "type_decl";
	}
//	| array_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
//	| record_type_decl			{ $$ = ast_newNode1($1);$$->debug = "type_decl";}
;

simple_type_decl:
	SYS_TYPE { 
		std::string type_string($1);
		$$ = new TypeDecl(type_string);
		//$$ = ast_dbg($1); $$->debug = "simple_type_decl";
	}
//	| NAME  					{ $$ = ast_dbg($1); $$->debug = "simple_type_decl";}
//	| LP name_list RP 			{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "simple_type_decl";}
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

name_list:
	name_list COMMA ID { 
		//$$ = ast_newNode3($1, ast_dbg($2), ast_dbg($3));$$->debug = "name_list";
		$$ = $1;
		$1->name_list.push_back(new Identifier($3));
	}
	| ID {
		$$ = new Identifier($1);
		$$->debug = "name list start"
		//$$ = ast_newNode1(ast_dbg($1));$$->debug = "name_list";
	}
;

var_part:
	VAR var_decl_list 			{ 
		$$ = new VarDecl();
		$$->debug = "var_part";
		$$->addVar($2); // TODO insert into symbol table;
		//$$ = ast_newNode2(ast_dbg($1), $2); $$->debug = "var_part";
	}
	|  	{
		//$$ = new VarDecl();
		//$$ = ast_dbg("empty var_part");
	}
;

var_decl_list:
	var_decl_list var_decl 		{ 
		$$ = $1;
		$1->var_decl_list.push_back((VarDecl *)$1);
		//$$ = ast_newNode2($1, $2);
		//$$->debug = "var_decl_list";
	}
	| var_decl 					{ 
		$$ = new VarDecl();
		$$->debug = "var start";
		$$->var_decl_list.push_back((VarDecl *)$1);
		//$$ = ast_newNode1($1);$$->debug = "var_decl_list"; 
	}
;

var_decl:
	name_list COLON type_decl SEMI { 
		$$ = new VarDecl();
		$$->names = $1;
		$$->type = $3;
		$$->debug = "declaration item";
		//$$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));$$->debug = "var_decl";
	}
;

routine_part:
	routine_part function_decl  { $$ = ast_newNode2($1, $2);$$->debug = "routine_part";}
	| routine_part procedure_decl 					{ $$ = ast_newNode2($1, $2);$$->debug = "routine_part";}
//	| procedure_decl			{ $$ = ast_newNode1($1);$$->debug = "routine_part";}
//	| function_decl				{ $$ = ast_newNode1($1);$$->debug = "routine_part";}
	| 							{ $$ = ast_dbg("empty routine_part");}
;

function_decl:
	function_head SEMI sub_routine SEMI { $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));$$->debug = "function_decl";}
;

function_head:
	FUNCTION ID parameters COLON simple_type_decl 	{ $$ = ast_newNode5(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4), $5); $$->debug = "function_head";}
;

procedure_decl:
	procedure_head SEMI sub_routine SEMI 			{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4)); $$->debug = "procedure_decl";}
;

procedure_head:
	PROCEDURE ID parameters 						{ $$ = ast_newNode3(ast_dbg($1), ast_dbg($2), $3);$$->debug = "procedure_head";}
;

parameters:
	LP para_decl_list RP 							{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));$$->debug = "parameters";}
	|  												{ $$ = ast_dbg("empty parameters"); }
;

para_decl_list:
	para_decl_list SEMI para_type_list 				{ $$ = ast_newNode3($1, ast_dbg($2), $3);$$->debug = "para_decl_list";}
	| para_type_list								{ $$ = ast_newNode1($1);$$->debug = "para_decl_list";}
;

para_type_list:
	var_para_list COLON simple_type_decl 			{ $$ = ast_newNode3($1, ast_dbg($2), $3); $$->debug = "para_type_list";}
	| val_para_list COLON simple_type_decl 			{ $$ = ast_newNode3($1, ast_dbg($2), $3); $$->debug = "para_type_list";}
;

var_para_list:
	VAR name_list 				{ $$ = ast_newNode2(ast_dbg($1), $2); $$->debug = "var_para_list";}
;

val_para_list:
	name_list 					{ $$ = ast_newNode1($1); $$->debug = "val_para_list";}
;

// boundary
routine_body:  
	compound_stmt { 
		$$ = $1;
		cerr << "routine_body parsed" << endl;
		//$$ = ast_newNode1($1);$$->debug = "routine_body";
	}
;

compound_stmt : 
	BEGINN  stmt_list  END { 
		$$ = $2;
		//$$ = ast_newNode3(ast_dbg($1),$2,ast_dbg($3));$$->debug = "compound_stmt";
	}
;
stmt_list : 
	stmt_list stmt {
		//yyerror("SEMI error");
	}
	| stmt_list  stmt  SEMI { 
		$$ = $1;
		$1->stmt_list.push_back($2);
		//$$ = ast_newNode3($1,$2,ast_dbg($3));$$->debug = "stmt_list";
	}
	| { 
		$$ = new Statement();
		//$$ = ast_dbg("empty stmt_list");
	}
		
;
stmt: 
	non_label_stmt { 
		$$ = (Statement *)$1;
		//$$ = ast_newNode1($1);$$->debug = "stmt";
	}
	//| INTEGER  COLON  non_label_stmt { 
		//$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),$3);$$->debug = "stmt";
	//}
;
non_label_stmt : 
	assign_stmt { 
		//$$ = ast_newNode1($1);$$->debug = "non_label_stmt";
		$$ = (Statement *)$1;
	}
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
	ID  ASSIGN  expression { 
		$$ = new AssignmentStmt(new Identifier($1), $3);
		//$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),$3);$$->debug = "assign_stmt";
	}
	//| ID LB expression RB ASSIGN expression     { $$ = ast_newNode6(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4),ast_dbg($5),$6);$$->debug = "assign_stmt";} 
	//| ID  DOT  ID  ASSIGN  expression           { $$ = ast_newNode5(ast_dbg($1),ast_dbg($2),ast_dbg($3),ast_dbg($4),$5);$$->debug = "assign_stmt";} 
;

proc_stmt : 
	ID                   						{ $$ = ast_dbg($1);$$->debug = "proc_stmt";}
	|  ID  LP  args_list  RP 					{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}
	|  SYS_PROC									{ $$ = ast_dbg($1);$$->debug = "proc_stmt";}
	|  SYS_PROC  LP  expression_list  RP        { $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}

	|  READ  LP  factor  RP 					{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "proc_stmt";}
     
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
	FOR  ID  ASSIGN  expression  direction  expression  DO stmt 	{ $$ = ast_newNode8(ast_dbg($1),ast_dbg($2),ast_dbg($3),$4,$5,$6,ast_dbg($7),$8);$$->debug = "for_stmt";}
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
	|  ID  COLON  stmt  SEMI					{ $$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "case_expr";}
;
goto_stmt : 
	GOTO  INTEGER 								{$$ = ast_newNode2(ast_dbg($1),ast_dbg($2));$$->debug = "goto_stmt";}
;

expression_list: 
	expression_list  COMMA  expression   		{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression_list";}
	|  expression 								{$$ = ast_newNode1($1);$$->debug = "expression_list";}

expression: 
	expr {
		$$ = $1;
		//$$ = ast_newNode1($1);$$->debug = "expression";
	}
//	|  expression  GE  expr  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  GT  expr  					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  LE  expr 					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//    |  expression  LT  expr  					{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  EQUAL  expr  				{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}
//	|  expression  UNEQUAL  expr  				{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expression";}	
;

expr: 
	expr  PLUS  term {
		$$ = new BinaryOperator($1, BinaryOperator::OpType::plus, $3);
		//$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expr";
	}
//	|  expr  MINUS  term  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expr";}	
//	|  expr  OR  term  							{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "expr";}
	|  term {
		$$ = $1;
		//$$ = ast_newNode1($1);$$->debug = "expr";
	}
;

term: 
	factor {
		$$ = $1;
		//$$ = ast_newNode1($1);$$->debug = "term";
	}
//	|  term  MUL  factor  							{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
//	|  term  DIV  factor  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
//	|  term  MOD  factor 						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
// 	|  term  AND  factor  						{$$ = ast_newNode3($1,ast_dbg($2),$3);$$->debug = "term";}
;

factor: 
	NAME {
		$$ = new Identifier($1);
		//$$ = ast_newNode1(ast_dbg($1));$$->debug = "factor";
	}
//	|  NAME  LP  args_list  RP  				{$$ = ast_newNode1(ast_dbg($1));$$->debug = "factor";}
//	|  SYS_FUNCT SYS_FUNCT  LP  args_list  RP  	{$$ = ast_newNode5(ast_dbg($1),ast_dbg($2),ast_dbg($3),$4,ast_dbg($5));$$->debug = "factor";}
	|  const_value {
		$$ = (Expression *)$1;
		//$$ = ast_newNode1($1);$$->debug = "factor";
	};
//	|  LP  expression  RP 						{$$ = ast_newNode3(ast_dbg($1),$2,ast_dbg($3));$$->debug = "factor";}
//	|  NOT  factor  							{$$ = ast_newNode2(ast_dbg($1),$2);$$->debug = "factor";}
//	|  MINUS  factor  							{$$ = ast_newNode2(ast_dbg($1),$2);$$->debug = "factor";}
//	|  ID  LB  expression  RB 					{$$ = ast_newNode4(ast_dbg($1),ast_dbg($2),$3,ast_dbg($4));$$->debug = "factor";}
//	|  ID  DOT  ID 								{$$ = ast_newNode3(ast_dbg($1),ast_dbg($2),ast_dbg($3));$$->debug = "factor";}
;
args_list : 
	args_list  COMMA  expression  				{$$ =ast_newNode3($1,ast_dbg($2),$3);$$->debug = "args_list";}
	|  expression 								{$$ = ast_newNode1($1);$$->debug = "args_list";}
;
%%
int main(int argc, char** argv) {
	yyparse();
	return 0;
}


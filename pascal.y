%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "pascal.tab.h"
int yydebug = 1;
%}

%union{
	ast_node *a;
	int integer;
	char* debug;
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
%type <a> program program_head routine sub_routine label_part const_part
%type <a> const_expr_list const_value routine_head 
%type <a> type_part type_decl_list type_decl simple_type_decl name_list 
%type <a> procedure_head para_type_list var_para_list val_para_list
%type <a> para_decl_list parameters procedure_decl function_decl function_head
%type <a> routine_part var_decl var_decl_list var_part field_decl field_decl_list
%type <a> record_type_decl array_type_decl type_definition 
%type <debug> ID NAME
%type <debug> DOT PROGRAM SEMI CONST EQUAL INTEGER REAL
%type <debug> CHAR STRING SYS_CON LB RB ARRAY OF MINUS SYS_TYPE
%type <debug> VAR COLON LP RP PROCEDURE FUNCTION COMMA RECORD END TYPE 
%%

NAME:
	ID {
		$$ = $1;
	}
;

program:
	program_head routine DOT { 
		$$ = ast_newNode3($1, $2, ast_dbg($3));
		$$->debug = "Start point";
		ast_travel($$);
	}
;

program_head:
	PROGRAM ID SEMI { 
		$$ = ast_newNode3(ast_dbg($1), ast_dbg($2), ast_dbg($3));
		$$->debug = "program_head";
	}
;

routine:
	// TODO routine_head routine_body
	routine_head { $$ = ast_newNode1($1); $$->debug = "routine"; }
;

sub_routine:
	// TODO routine_head routine_body
	routine_head { $$ = ast_newNode1($1); }
;

routine_head:
	// TODO add routine_part will generate error: fatal error: symbol program does not derive any sentences
	label_part const_part type_part var_part { 
		$$ = ast_newNode4($1, $2, $3, $4);
		$$->debug = "routine_head";
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
		$$ = ast_newNode5($1, ast_dbg($2), ast_dbg($3), $4, ast_dbg($5)); }
	| NAME EQUAL const_value SEMI {
		// printf("in const_expr_list\n");
		$$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4)); }
;

const_value:
	INTEGER  					{ $$ = ast_dbg($1);}
	| REAL 						{ $$ = ast_dbg($1);}
	| CHAR 						{ $$ = ast_dbg($1);}
	| STRING 					{ $$ = ast_dbg($1);}
	| SYS_CON					{ $$ = ast_dbg($1);}
;


type_part:
	TYPE type_decl_list 		{ $$ = ast_dbg($1); }
	|							{ $$ = ast_dbg("empty type_part");}
;

type_decl_list:
	type_decl_list type_definition { $$ = ast_newNode2($1, $2);}
	| type_definition			{ $$ = ast_newNode1($1);}
;

type_definition:
	ID EQUAL type_decl SEMI 	{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4));}
;

type_decl:
	simple_type_decl 			{ $$ = ast_newNode1($1);}
	| array_type_decl			{ $$ = ast_newNode1($1);}
	| record_type_decl			{ $$ = ast_newNode1($1);}
;

simple_type_decl:
	SYS_TYPE					{ $$ = ast_dbg($1); }
	| NAME  					{ $$ = ast_dbg($1); }
	| LP name_list RP 			{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));}
	| const_value DOT DOT const_value 				{ $$ = ast_newNode4($1, ast_dbg($2), ast_dbg($3), $4);}
	| MINUS const_value DOT DOT const_value			{ $$ = ast_newNode5(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), $5);}
	| MINUS const_value DOT DOT MINUS const_value 	{ $$ = ast_newNode6(ast_dbg($1), $2, ast_dbg($3), ast_dbg($4), ast_dbg($5), $6);}
	| NAME DOT DOT NAME 		{ $$ = ast_newNode4(ast_dbg($1), ast_dbg($2), ast_dbg($3), ast_dbg($4));}
;

array_type_decl:
	ARRAY LB simple_type_decl RB OF type_decl 		{ $$ = ast_newNode6(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4), ast_dbg($5), $6); }
;

record_type_decl:
	RECORD field_decl_list END 	{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));}
;

field_decl_list:
	field_decl_list field_decl 	{ $$ = ast_newNode2($1, $2);}
	| field_decl 				{ $$ = ast_newNode1($1); }
;

field_decl:
	name_list COLON type_decl SEMI 					{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));}
;

name_list:
	name_list COMMA ID 			{ $$ = ast_newNode3($1, ast_dbg($2), ast_dbg($3));}
	| ID 						{ $$ = ast_newNode1(ast_dbg($1));}
;

var_part:
	VAR var_decl_list 			{ $$ = ast_newNode2(ast_dbg($1), $2); $$->debug = "var_part";}
	|  							{ $$ = ast_dbg("empty var_part");}
;

var_decl_list:
	var_decl_list var_decl 		{ $$ = ast_newNode2($1, $2);}
	| var_decl 					{ $$ = ast_newNode1($1); }
;

var_decl:
	name_list COLON type_decl SEMI 					{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));}
;

routine_part:
	routine_part function_decl  { $$ = ast_newNode2($1, $2);}
	| routine_part procedure_decl 					{ $$ = ast_newNode2($1, $2);}
	| function_decl				{ $$ = ast_newNode1($1);}
	| procedure_decl 			{ $$ = ast_newNode1($1);}
;

function_decl:
	function_head SEMI sub_routine SEMI { $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4));}
;

function_head:
	FUNCTION ID parameters COLON simple_type_decl 	{ $$ = ast_newNode5(ast_dbg($1), ast_dbg($2), $3, $4, $5); }
;

procedure_decl:
	procedure_head SEMI sub_routine SEMI 			{ $$ = ast_newNode4($1, ast_dbg($2), $3, ast_dbg($4)); }
;

procedure_head:
	PROCEDURE ID parameters 						{ $$ = ast_newNode3(ast_dbg($1), ast_dbg($2), $3);}
;

parameters:
	LP para_decl_list RP 							{ $$ = ast_newNode3(ast_dbg($1), $2, ast_dbg($3));}
	|  												{ $$ = ast_dbg("empty parameters"); }
;

para_decl_list:
	para_decl_list SEMI para_type_list 				{ $$ = ast_newNode3($1, ast_dbg($2), $3);}
;

para_type_list:
	var_para_list COLON simple_type_decl 			{ $$ = ast_newNode3($1, ast_dbg($2), $3); }
	| val_para_list COLON simple_type_decl 			{ $$ = ast_newNode3($1, ast_dbg($2), $3); }
;

var_para_list:
	VAR name_list 				{ $$ = ast_newNode2(ast_dbg($1), $2); }
;

val_para_list:
	name_list 					{ $$ = ast_newNode1($1); }
;

// boundary
/*
routine_body :  
	compound_stmt
;
compound_stmt : 
	BEGINN  stmt_list  END
;
stmt_list : 
		stmt_list  stmt  SEMI  
		|  
		
;
stmt : 
	INTEGER  COLON  non_label_stmt  
	|  
	non_label_stmt
;
non_label_stmt : 
	assign_stmt 
	| proc_stmt 
	| compound_stmt 
	| if_stmt 
	| repeat_stmt 
	| while_stmt
	| for_stmt
	| case_stmt 
	| goto_stmt
;
assign_stmt : 
	ID  ASSIGN  expression
	| ID LB expression RB ASSIGN expression
	| ID  DOT  ID  ASSIGN  expression
;
proc_stmt : 
	ID
	|  ID  LP  args_list  RP
	|  SYS_PROC
	|  SYS_PROC  LP  expression_list  RP
	|  READ  LP  factor  RP
;
if_stmt : 
	IF  expression  THEN  else_clause
;
else_clause : 
	ELSE stmt 
	| 
;
repeat_stmt : 
	REPEAT  stmt_list  UNTIL  expression
;
while_stmt : 
	WHILE  expression  DO stmt
;
for_stmt : 
	FOR  ID  ASSIGN  expression  direction  expression  DO stmt
;
direction : 
	TO 
	| DOWNTO
;
case_stmt : 
	CASE expression OF case_expr_list  END
;
case_expr_list : 
	case_expr_list  case_expr  
	|  case_expr
;
case_expr : 
	const_value  COLON  stmt  SEMI
	|  ID  COLON  stmt  SEMI
;
goto_stmt : 
	GOTO  INTEGER
;
expression_list : 
	expression_list  COMMA  expression  
	|  expression
;
expression : 
	expression  GE  expr  
	|  expression  GT  expr  
	|  expression  LE  expr
    |  expression  LT  expr  
	|  expression  EQUAL  expr  
	|  expression  UNEQUAL  expr  
	|  expr
;
expr : 
	expr  PLUS  term  
	|  expr  MINUS  term  
	|  expr  OR  term  
	|  term
;
term : 
	term  MUL  factor  
	|  term  DIV  factor  
	|  term  MOD  factor 
 	|  term  AND  factor  
	|  factor
;
factor : 
	NAME  
	|  NAME  LP  args_list  RP  
	|  SYS_FUNCT SYS_FUNCT  LP  args_list  RP  
	|  const_value  
	|  LP  expression  RP
	|  NOT  factor  
	|  MINUS  factor  
	|  ID  LB  expression  RB
	|  ID  DOT  ID
;
args_list : 
	args_list  COMMA  expression  
	|  expression
;
*/
%%
int main(int argc, char** argv) {
	yyparse();
	return 0;
}


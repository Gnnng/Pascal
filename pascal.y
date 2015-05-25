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
%start program
%type <a> program program_head routine sub_routine label_part const_part
%type <a> const_expr_list const_value routine_head 
%type <debug> ID NAME
%type <debug> DOT PROGRAM SEMI CONST EQUAL INTEGER REAL
%type <debug> CHAR STRING SYS_CON
%%

NAME:
	ID {
		$$ = ast_newNode1($1);
		$$.debug = "name";
	}
;

program:
	program_head routine DOT { 
		$$ = ast_newNode3($1, $2, ast_dbg($3));
		ast_travel($$);
	}
;

program_head:
	PROGRAM ID SEMI { 
		$$ = ast_newNode3(ast_dbg($1), ast_dbg($2), ast_dbg($3));
	}
;

routine:
	routine_head				{ $$ = ast_newNode1($1); $$->debug = "routine"; }
;

sub_routine:
	routine_head 				{ $$ = ast_newNode1($1); }
;

routine_head:
	// FIXME: need to start with label_part
	label_part const_part		{ 
		$$ = ast_newNode2($1, $2); 
		if ($2 == NULL) 
			$$->debug = "empty routine_head";
		else 
			$$->debug = "routine_head";
	}
	//const_part		{ $$ = ast_newNode1($1); $$->debug = "routine_head";}
	/* label_part const_part type_part var_part routine_part */
;

label_part: 					{ $$ = ast_dbg("label_part"); }
;

const_part:
	CONST const_expr_list {
		$$ = ast_newNode2(ast_dbg($1), $2);
		printf("in const_part\n");
		$$->debug = "const_part";
	}
	| 							{ $$ = NULL; }
;

const_expr_list:
	// FIXME ID --> NAME
	const_expr_list ID EQUAL const_value SEMI { 
		printf("in const_expr_list recursively\n");
		$$ = ast_newNode5($1, ast_dbg($2), ast_dbg($3), $4, ast_dbg($5)); }
	// FIXME ID --> NAME
	| ID EQUAL const_value SEMI {
		printf("in const_expr_list\n");
		$$ = ast_newNode4(ast_dbg($1), ast_dbg($2), $3, ast_dbg($4)); }
;

const_value:
	INTEGER  					{ $$ = ast_dbg($1); printf("%s\n", $1); }
	| REAL 						{ $$ = ast_dbg($1);}
	| CHAR 						{ $$ = ast_dbg($1);}
	| STRING 					{ $$ = ast_dbg($1);}
	| SYS_CON					{ $$ = ast_dbg($1);}
;

/*
type_part:
	TYPE type_decl_list 
	|
;

type_decl_list:
	type_decl_list type_definition
	| type_definition
;

type_definition:
	ID EQUAL type_decl SEMI
;

type_decl:
	simple_type_decl
	| array_type_decl
	| record_type_decl
;

simple_type_decl:
	SYS_TYPE
	| NAME
	| LP name_list RP
	| const_value DOT DOT const_value
	| MINUS const_value DOT DOT const_value
	| MINUS const_value DOT DOT MINUS const_value
	| NAME DOT DOT NAME
;

array_type_decl:
	ARRAY LB simple_type_decl RB OF type_decl
;

record_type_decl:
	RECORD field_decl_list END
;

field_decl_list:
	field_decl_list field_decl
	| field_decl
;

field_decl:
	name_list COLON type_decl SEMI
;

name_list:
	name_list COMMA ID
	| ID
;

var_part:
	VAR var_decl_list
	| 
;

var_decl_list:
	var_decl_list var_decl
	| var_decl
;

var_decl:
	name_list COLON type_decl SEMI
;

routine_part:
	routine_part function_decl 
	| routine_part prodedure_decl
	| function_decl
	| procedure_decl
;

function_decl:
	function_head SEMI sub_routine SEMI
;

function_head:
	FUNCTION ID parmeters colon simple_type_decl
;

procedure_decl:
	procedure_head SEMI sub_routine SEMI
;

procedure_head:
	PROCEDURE ID parameters
;

parameters:
	LP para_decl_list RP
	| 
;

para_decl_list:
	para_decl_list SEMI para_type_list
;

para_type_list:
	var_para_list COLON simple_type_decl
	| val_para_list COLON simple_type_decel
;

var_para_list:
	VAR name_list
;

val_para_list:
	name_list
;
*/

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

%%
int main(int argc, char** argv) {
	yyparse();
	return 0;
}


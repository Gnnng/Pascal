%{
#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "pascal.tab.h"
int yydebug = 1;

%}

%token PROGRAM ID SEMI DOT
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
%token COLON
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token BEGIN END
%token CASE 
%token COMMA
%token DOWNTO
%token FOR
%token GOTO
%token INTEGER
%token LB RB
%token NOT OR AND MOD
%token OF
%token READ REPEAT TO UNEQUAL UNTIL
%token NUMBER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE NAME
%start program

%%
program:
	program_head DOT 	{ printf("%d %d\n", $1, $2); }
;

program_head:
	PROGRAM ID COLON
;

routine_body :  
	compound_stmt
;
compound_stmt : 
	BEGIN  stmt_list  END
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

void yyerror(char *s, ...) {
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "error at: %s\n", yytext);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int main(int argc, char** argv) {
	yyparse();
	return 0;
}


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
%token MULT
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
%token NUMBER SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE NAME
%start program

%%
program:
	program_head DOT 	{ printf("%d %d\n", $1, $2); }
;

program_head:
	PROGRAM ID COLON
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


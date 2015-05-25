%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "pascal.tab.h"

%}
%%
"="      	{ yylval.debug = strdup(yytext); return EQUAL; }
"<"      	{ return LT; }
"<="     	{ return LE; }
">"      	{ return GT; }
">="     	{ return GE; }
"+"      	{ return PLUS; }
"-"      	{ return MINUS; }
"*"      	{ return MULT; }
"/"      	{ return DIV; }
")"      	{ return RP; }
"("      	{ return LP; }
":="     	{ return ASSIGN; }
","		 	{ yylval.debug = strdup(yytext); return COMMA; }
":" 	 	{ yylval.debug = strdup(yytext); return COLON; }
";"      	{ yylval.debug = strdup(yytext); return SEMI; }
"if"     	{ return IF; }
"then"   	{ return THEN; }
"else"   	{ return ELSE; }
"while"  	{ return WHILE; }
"do"     	{ return DO; }
"Program" 	{ yylval.debug = strdup(yytext); return PROGRAM; }
"."      	{ yylval.debug = strdup(yytext); return DOT; }
"false" | 
"maxint" | 
"true"   	{ return SYS_CON; }
"abs" |
"chr" | 
"ord" | 
"pred" | 
"sqr" | 
"succ"    	{ return SYS_FUNCT; }
"write" | 
"writeln"  	{ return SYS_PROC; }
"boolean" |
"char" |
"integer" |
"real"    	{ return SYS_TYPE;}
"const" 	{ yylval.debug = strdup(yytext); return CONST;} 
[0-9]+   	{ yylval.debug = strdup(yytext); printf("%s\n", yytext); return INTEGER; }
([_a-zA-Z])([_a-zA-Z0-9])* { yylval.debug = strdup(yytext); return ID; }
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

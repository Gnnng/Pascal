%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "ast.h"
#include "parser.hpp"

#define YYLVAL_DEBUG yylval.debug = strdup(yytext); 
%}
%%
"="      { YYLVAL_DEBUG return EQUAL; }
"<"      { YYLVAL_DEBUG return LTHAN; }
"<="     { YYLVAL_DEBUG return LEQU; }
">"      { YYLVAL_DEBUG return GT; }
">="     { YYLVAL_DEBUG return GE; }
"<>"     { YYLVAL_DEBUG return UNEQUAL; }
"+"      { YYLVAL_DEBUG return PLUS; }
"-"      { YYLVAL_DEBUG return MINUS; }
"*"      { YYLVAL_DEBUG return MUL; }
"/"|"div"      { YYLVAL_DEBUG return DIV; }		
")"      { YYLVAL_DEBUG return RIGHTP; }
"("      { YYLVAL_DEBUG return LEFTP; }
"["		 { YYLVAL_DEBUG return LB; }
"]"      { YYLVAL_DEBUG return RB; }
":="     { YYLVAL_DEBUG return ASSIGN; }
";"      { YYLVAL_DEBUG return SEMI; }
","		 { YYLVAL_DEBUG return COMMA; }
":"		 { YYLVAL_DEBUG return COLON; }
"begin"  { YYLVAL_DEBUG return BEGINN; }
"end"	 { YYLVAL_DEBUG return END; }
"case"   { YYLVAL_DEBUG return CASE; }
"for"    { YYLVAL_DEBUG return FOR; }
"goto"   { YYLVAL_DEBUG return GOTO; }
"mod"    { YYLVAL_DEBUG return MOD; }
"and"    { YYLVAL_DEBUG return AND; }
"or"     { YYLVAL_DEBUG return OR; }
"read"|"readln"   { YYLVAL_DEBUG return READ; }
"repeat" { YYLVAL_DEBUG return REPEAT; }
"until"  { YYLVAL_DEBUG return UNTIL; }
"if"     { YYLVAL_DEBUG return IF; }
"then"   { YYLVAL_DEBUG return THEN; }
"else"   { YYLVAL_DEBUG return ELSE; }
"while"  { YYLVAL_DEBUG return WHILE; }
"do"     { YYLVAL_DEBUG return DO; }
"downto" { YYLVAL_DEBUG return DOWNTO; } 
"to"     { YYLVAL_DEBUG return TO; }
"of"     { YYLVAL_DEBUG return OF; }
"const"  { YYLVAL_DEBUG return CONST;}
"program" { YYLVAL_DEBUG return PROGRAM; }
"function" { YYLVAL_DEBUG return FUNCTION; }
"array"  { YYLVAL_DEBUG return ARRAY; }
"procedure" { YYLVAL_DEBUG return PROCEDURE;}
"type"   { YYLVAL_DEBUG return TYPE;}
"record" { YYLVAL_DEBUG return RECORD;}
"var"    { YYLVAL_DEBUG return VAR;}
[0-9]+   { YYLVAL_DEBUG  return INTEGER; }
"."      { YYLVAL_DEBUG return DOT; }
"write"|"writeln" {YYLVAL_DEBUG return SYS_PROC; }
"false"|"maxint"|"true"   { YYLVAL_DEBUG return SYS_CON; }
"abs"|"chr"|"ord"|"pred"|"sqr"|"succ"    { YYLVAL_DEBUG return SYS_FUNCT; }
"boolean"|"char"|"integer"|"real"|"longint"    {YYLVAL_DEBUG return SYS_TYPE;}
([_a-zA-Z])([_a-zA-Z0-9])* { yylval.debug = strdup(yytext);return IDD; }
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "pascal.tab.h"
#define YYLVAL_DEBUG yylval.debug = strdup(yytext); 
%}
%%
"="      { YYLVAL_DEBUG return EQUAL; }
"<"      { YYLVAL_DEBUG return LT; }
"<="     { YYLVAL_DEBUG return LE; }
">"      { YYLVAL_DEBUG return GT; }
">="     { YYLVAL_DEBUG return GE; }
"<>"     { YYLVAL_DEBUG return UNEQUAL; }
"+"      { YYLVAL_DEBUG return PLUS; }
"-"      { YYLVAL_DEBUG return MINUS; }
"*"      { YYLVAL_DEBUG return MUL; }
"/"      { YYLVAL_DEBUG return DIV; }
")"      { YYLVAL_DEBUG return RP; }
"("      { YYLVAL_DEBUG return LP; }
"["		 { YYLVAL_DEBUG return LB; }
"]"      { YYLVAL_DEBUG return RB; }
":="     { YYLVAL_DEBUG return ASSIGN; }
";"      { YYLVAL_DEBUG return SEMI; }
","		 { YYLVAL_DEBUG return COMMA; }
":"		 { YYLVAL_DEBUG return COLON; }
"begin"  { YYLVAL_DEBUG return BEGINN; }
"case"   { YYLVAL_DEBUG return CASE; }
"for"    { YYLVAL_DEBUG return FOR; }
"goto"   { YYLVAL_DEBUG return GOTO; }
"mod"    { YYLVAL_DEBUG return MOD; }
"and"    { YYLVAL_DEBUG return AND; }
"or"     { YYLVAL_DEBUG return OR; }
"read"   { YYLVAL_DEBUG return READ; }
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
"Program" { YYLVAL_DEBUG return PROGRAM; }
"function" { YYLVAL_DEBUG return FUNCTION; }
"array"  { YYLVAL_DEBUG return ARRAY; }
"procedure" { YYLVAL_DEBUG return PROCEDURE;}
"type"   { YYLVAL_DEBUG return TYPE;}
"record" { YYLVAL_DEBUG return RECORD;}
"var"    { YYLVAL_DEBUG return VAR;}
[0-9]+   { YYLVAL_DEBUG  return INTEGER; }
"."      { YYLVAL_DEBUG return DOT; }
"false" | "maxint" | "true"   { return SYS_CON; }
"abs" | "chr" | "ord" | "pred" | "sqr" | "succ"    { return SYS_FUNCT; }
"write" | "writeln"    { return SYS_PROC; }
"boolean"|"char"|"integer"|"real"    {return SYS_TYPE;}
([_a-zA-Z])([_a-zA-Z0-9])* { yylval.debug = strdup(yytext); return ID; }
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

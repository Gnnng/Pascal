%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "pascal.tab.h"

%}
%%
"="      { return EQUAL; }
"<"      { return LT; }
"<="     { return LE; }
">"      { return GT; }
">="     { return GE; }
"<>"     { return UNEQUAL; }
"+"      { return PLUS; }
"-"      { return MINUS; }
"*"      { return MUL; }
"/"      { return DIV; }
")"      { return RP; }
"("      { return LP; }
"["		 { return LB; }
"]"      { return RB; }
":="     { return ASSIGN; }
";"      { return SEMI; }
","		 { return COMMA; }
":"		 { return COLON; }
"begin"  { return BEGIN; }
"case"   { return CASE; }
"for"    { return FOR; }
"goto"   { return GOTO; }
"mod"    { return MOD; }
"and"    { return AND; }
"or"     { return OR; }
"read"   { return read; }
"repeat" { return REPEAT; }
"until"  { return UNTIL; }
"if"     { return IF; }
"then"   { return THEN; }
"else"   { return ELSE; }
"while"  { return WHILE; }
"do"     { return DO; }
"downto" { return DOWNTO; } 
"to"     { return TO; }
"of"     { return OF; }
"Program" { return PROGRAM; }
[0-9]+   { yylval = atoi(yytext); return INTEGER; }
"."      { return DOT; }
"false" | "maxint" | "true"   { return SYS_CON; }
"abs" | "chr" | "ord" | "pred" | "sqr" | "succ"    { return SYS_FUNCT; }
"write" | "writeln"    { return SYS_PROC; }
"boolean"|"char"|"integer"|"real"    {return SYS_TYPE;}
([_a-zA-Z])([_a-zA-Z0-9])* { return ID; }
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
#include "pascal.tab.h"

%}
%%
"="      { yylval.debug = strdup(yytext); return EQUAL; }
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
":="     { yylval.debug = strdup(yytext); return ASSIGN; }
";"      { yylval.debug = strdup(yytext); return SEMI; }
","		 { yylval.debug = strdup(yytext); return COMMA; }
":"		 { yylval.debug = strdup(yytext); return COLON; }
"begin"  { yylval.debug = strdup(yytext); return BEGINN; }
"case"   { yylval.debug = strdup(yytext); return CASE; }
"for"    { return FOR; }
"goto"   { return GOTO; }
"mod"    { return MOD; }
"and"    { return AND; }
"or"     { return OR; }
"read"   { return READ; }
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
"const"  { yylval.debug = strdup(yytext); return CONST;}
"Program" { yylval.debug = strdup(yytext); return PROGRAM; }
[0-9]+   { yylval.debug = strdup(yytext);  return INTEGER; }
"."      { yylval.debug = strdup(yytext); return DOT; }
"false" | "maxint" | "true"   { return SYS_CON; }
"abs" | "chr" | "ord" | "pred" | "sqr" | "succ"    { return SYS_FUNCT; }
"write" | "writeln"    { return SYS_PROC; }
"boolean"|"char"|"integer"|"real"    {return SYS_TYPE;}
([_a-zA-Z])([_a-zA-Z0-9])* { yylval.debug = strdup(yytext); return ID; }
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ast.h"
#include "utils.h"

#include "parser.hpp"
#include "ccalc.h"

#define YY_INPUT(buf,result,max_size)  {\
    result = GetNextChar(buf, max_size); \
    if (  result <= 0  ) \
      result = YY_NULL; \
    }
#define YYLVAL_DEBUG yylval.debug = strdup(yytext); 
%}
%%
"="      { BeginToken(yytext);YYLVAL_DEBUG return EQUAL; }
"<"      { BeginToken(yytext);YYLVAL_DEBUG return LTHAN; }
"<="     { BeginToken(yytext);YYLVAL_DEBUG return LEQU; }
">"      { BeginToken(yytext);YYLVAL_DEBUG return GT; }
">="     { BeginToken(yytext);YYLVAL_DEBUG return GE; }
"<>"     { BeginToken(yytext);YYLVAL_DEBUG return UNEQUAL; }
"+"      { BeginToken(yytext);YYLVAL_DEBUG return PLUS; }
"-"      { BeginToken(yytext);YYLVAL_DEBUG return MINUS; }
"*"      { BeginToken(yytext);YYLVAL_DEBUG return MUL; }
"/"|"div"      { BeginToken(yytext);YYLVAL_DEBUG return DIV; }		
")"      { BeginToken(yytext);YYLVAL_DEBUG return RIGHTP; }
"("      { BeginToken(yytext);YYLVAL_DEBUG return LEFTP; }
"["		 { BeginToken(yytext);YYLVAL_DEBUG return LB; }
"]"      { BeginToken(yytext);YYLVAL_DEBUG return RB; }
":="     { BeginToken(yytext);YYLVAL_DEBUG return ASSIGN; }
";"      { BeginToken(yytext);YYLVAL_DEBUG return SEMI; }
","		 { BeginToken(yytext);YYLVAL_DEBUG return COMMA; }
":"		 { BeginToken(yytext);YYLVAL_DEBUG return COLON; }
"begin"  { BeginToken(yytext);YYLVAL_DEBUG return BEGINN; }
"end"	 { BeginToken(yytext);YYLVAL_DEBUG return END; }
"case"   { BeginToken(yytext);YYLVAL_DEBUG return CASE; }
"for"    { BeginToken(yytext);YYLVAL_DEBUG return FOR; }
"goto"   { BeginToken(yytext);YYLVAL_DEBUG return GOTO; }
"mod"    { BeginToken(yytext);YYLVAL_DEBUG return MOD; }
"and"    { BeginToken(yytext);YYLVAL_DEBUG return AND; }
"or"     { BeginToken(yytext);YYLVAL_DEBUG return OR; }
"read"|"readln"   { BeginToken(yytext);YYLVAL_DEBUG return READ; }
"repeat" { BeginToken(yytext);YYLVAL_DEBUG return REPEAT; }
"until"  { BeginToken(yytext);YYLVAL_DEBUG return UNTIL; }
"if"     { BeginToken(yytext);YYLVAL_DEBUG return IF; }
"then"   { BeginToken(yytext);YYLVAL_DEBUG return THEN; }
"else"   { BeginToken(yytext);YYLVAL_DEBUG return ELSE; }
"while"  { BeginToken(yytext);YYLVAL_DEBUG return WHILE; }
"do"     { BeginToken(yytext);YYLVAL_DEBUG return DO; }
"downto" { BeginToken(yytext);YYLVAL_DEBUG return DOWNTO; } 
"to"     { BeginToken(yytext);YYLVAL_DEBUG return TO; }
"of"     { BeginToken(yytext);YYLVAL_DEBUG return OF; }
"const"  { BeginToken(yytext);YYLVAL_DEBUG return CONST;}
"program" { BeginToken(yytext);YYLVAL_DEBUG return PROGRAM; }
"function" { BeginToken(yytext);YYLVAL_DEBUG return FUNCTION; }
"array"  { BeginToken(yytext);YYLVAL_DEBUG return ARRAY; }
"procedure" { BeginToken(yytext);YYLVAL_DEBUG return PROCEDURE;}
"type"   { BeginToken(yytext);YYLVAL_DEBUG return TYPE;}
"record" { BeginToken(yytext);YYLVAL_DEBUG return RECORD;}
"var"    { BeginToken(yytext);YYLVAL_DEBUG return VAR;}
[0-9]+   { BeginToken(yytext);YYLVAL_DEBUG  return INTEGER; }
"."      { BeginToken(yytext);YYLVAL_DEBUG return DOT; }
"write"|"writeln" {BeginToken(yytext);YYLVAL_DEBUG return SYS_PROC; }
"false"|"maxint"|"true"   { BeginToken(yytext);YYLVAL_DEBUG return SYS_CON; }
"abs"|"chr"|"ord"|"pred"|"sqr"|"succ"    { BeginToken(yytext);YYLVAL_DEBUG return SYS_FUNCT; }
"boolean"|"char"|"integer"|"real"|"longint"    {BeginToken(yytext);YYLVAL_DEBUG return SYS_TYPE;}
([_a-zA-Z])([_a-zA-Z0-9])* { BeginToken(yytext);yylval.debug = strdup(yytext);return IDD; }

[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

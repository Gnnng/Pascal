%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "utils.h"
<<<<<<< HEAD:src/pascal.l
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
=======
#include "ccalc.h"
#include "pascal.tab.h"
#define YY_INPUT(buf,result,max_size)  {\
    result = GetNextChar(buf, max_size); \
    if (  result <= 0  ) \
      result = YY_NULL; \
    }
#define YYLVAL_DEBUG yylval.debug = strdup(yytext); 
%}
%%
"="      { BeginToken(yytext);YYLVAL_DEBUG return EQUAL; }
"<"      { BeginToken(yytext);YYLVAL_DEBUG return LT; }
"<="     { BeginToken(yytext);YYLVAL_DEBUG return LE; }
">"      { BeginToken(yytext);YYLVAL_DEBUG return GT; }
">="     { BeginToken(yytext);YYLVAL_DEBUG return GE; }
"<>"     { BeginToken(yytext);YYLVAL_DEBUG return UNEQUAL; }
"+"      { BeginToken(yytext);YYLVAL_DEBUG return PLUS; }
"-"      { BeginToken(yytext);YYLVAL_DEBUG return MINUS; }
"*"      { BeginToken(yytext);YYLVAL_DEBUG return MUL; }
"/"|"div"      { BeginToken(yytext);YYLVAL_DEBUG return DIV; }		
")"      { BeginToken(yytext);YYLVAL_DEBUG return RP; }
"("      { BeginToken(yytext);YYLVAL_DEBUG return LP; }
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
([_a-zA-Z])([_a-zA-Z0-9])* { BeginToken(yytext);yylval.debug = strdup(yytext);return ID; }
>>>>>>> 7ed3f78d977d9aaceee26e18c0de26b6f50789ba:pascal.l
[ \n\t]+
.		{ printf("Invalid character\n");} 		
%%

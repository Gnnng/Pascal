%{
    #include <stdio.h>
    #include <y.tab.h>
    extern int yylval;
%}
%%
"="      { return EQUAL; }
"<"      { return LT; }
"<="     { return LE; }
">"      { return GT; }
">="     { return GE; }
"+"      { return PLUS; }
"-"      { return MINUS; }
"*"      { return MULT; }
"/"      { return DIV; }
")"      { return RP; }
"("      { return LP; }
":="     { return ASSIGN; }
";"      { return COLON; }
"if"     { return IF; }
"then"   { return THEN; }
"else"   { return ELSE; }
"while"  { return WHILE; }
"do"     { return DO; }
[0-9]+   { yylval = atoi(yytext); return NUMBER; }
[a-z]    { yylval = yytext[0] - 'a'; return NAME; }
"●"      { return DOT; }
"false" || "maxint" || "true"   { return SYS_CON; }
"abs" || "chr" || "ord" || "pred" || "sqr" || "succ"    { return SYS_FUNCT; }
"write" || "writeln"    { return SYS_PROC; }
"boolean"||"char"||"integer"||"real"    {return SYS_TYPE;}
[a-z]    { yylval = yytext[0] - 'a'; return NAME; } 
.        { yyerror("illegal token"); }
%%

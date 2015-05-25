#ifndef __PASCAL_H__
#define __PASCAL_H__

extern int yylex();
// extern int yyparse();
extern int yylineno;
extern char *yytext;
extern int yylval;

void yyerror(char *s, ...);

#endif
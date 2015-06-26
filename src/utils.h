#ifndef __PASCAL_H__
#define __PASCAL_H__

extern int yylex();
// extern int yyparse();
extern int yylineno;
extern char *yytext;

void yyerror(char *s, ...);

typedef struct ast_struct ast_tree;
typedef ast_tree ast_node;

struct ast_struct {
	ast_node** ch;		// children
	char* debug;		// debug info
	int val;

};

void ast_travel(ast_node* node);
ast_node* ast_dbg(char* debug);
ast_node* ast_newNode1(ast_node* c1);
ast_node* ast_newNode2(ast_node* c1, ast_node* c2);
ast_node* ast_newNode3(ast_node* c1, ast_node* c2, ast_node* c3);
ast_node* ast_newNode4(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4);
ast_node* ast_newNode5(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5);
ast_node* ast_newNode6(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6);
ast_node* ast_newNode7(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7);
ast_node* ast_newNode8(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7, ast_node* c8);

#endif
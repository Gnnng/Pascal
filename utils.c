#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void yyerror(char *s, ...) {
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "error at: %s\n", yytext);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}


ast_node* ast_dbg(char* debug) {
	ast_node* node = calloc(1, sizeof(ast_node));
	node->debug = debug;
	return node;
}

ast_node* ast_newNode1(ast_node* c1) {
    ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = malloc(sizeof(ast_node*) * 1);
	node->ch[0] = c1;
	return node;
}

ast_node* ast_newNode2(ast_node* c1, ast_node* c2) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = malloc(sizeof(ast_node*) * 2);
	node->ch[0] = c1;    
	node->ch[1] = c2;
	return node;
}

ast_node* ast_newNode3(ast_node* c1, ast_node* c2, ast_node* c3) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = malloc(sizeof(ast_node*) * 3);
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	return node;
}

ast_node* ast_newNode4(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = malloc(sizeof(ast_node*) * 4);
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	return node;
}

ast_node* ast_newNode5(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = malloc(sizeof(ast_node*) * 5);
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	return node;
}


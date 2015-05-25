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

int count = 0;

void ast_travel(ast_node* node) {
	if (node->debug)
		// printf("%s ", node->debug);
		printf("%d %s \n", count++, node->debug);
	else
		printf("%d \n", count++);
	for(ast_node** ch = node->ch; *ch; ch++) {
		ast_travel(*ch);
	}
}

ast_node* ast_dbg(char* debug) {
	ast_node* node = calloc(1, sizeof(ast_node));
	node->debug = debug;

	node->ch = calloc(1, sizeof(ast_node*));
	return node;
}

ast_node* ast_newNode1(ast_node* c1) {
    ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = calloc(2, sizeof(ast_node*));
	node->ch[0] = c1;
	return node;
}

ast_node* ast_newNode2(ast_node* c1, ast_node* c2) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = calloc(3, sizeof(ast_node*));
	node->ch[0] = c1;    
	node->ch[1] = c2;
	return node;
}

ast_node* ast_newNode3(ast_node* c1, ast_node* c2, ast_node* c3) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = calloc(4, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	return node;
}

ast_node* ast_newNode4(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = calloc(5, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	return node;
}

ast_node* ast_newNode5(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5) {
	ast_node* node = calloc(1, sizeof(ast_node));

    node->ch = calloc(6, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	return node;
}


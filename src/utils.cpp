#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void yyerror(char *s, ...) {
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "error at: %s\n", yytext);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

int count = 0;

const char* tailStr = "└── ";
const char* branchStr = "├── ";
const char* ch_tailStr = "    ";
const char* ch_branchStr = "|   ";

void ast_print(ast_node* node, char* prefix, int tail) {
	char* new_prefix = (char *)malloc(sizeof(char) * (strlen(prefix) + 4 + 1));
	strcpy(new_prefix, prefix);
	if (tail) 
		strcat(new_prefix, tailStr);
	else
		strcat(new_prefix, branchStr);
	printf("%s %s\n", new_prefix, node->debug);
	char* ch_prefix = (char *)malloc(sizeof(char) * (strlen(prefix) + 4 + 1));
	strcpy(ch_prefix, prefix);
	if (tail)
		strcat(ch_prefix, ch_tailStr);
	else
		strcat(ch_prefix, ch_branchStr);
	ast_node** ch;
	for(ch = node->ch; *ch; ch++) {
		if ((*(ch + 1)) == NULL)
			ast_print(*ch, ch_prefix, 1);
		else
			ast_print(*ch, ch_prefix, 0);
	}
}

void ast_travel(ast_node* node) {
	char* ch_prefix = (char *)malloc(sizeof(char) * (4 + 1));
	strcpy(ch_prefix, "");
	strcat(ch_prefix, ch_tailStr);
	printf("%s\n", node->debug);
	ast_node** ch;
	for(ch = node->ch; *ch; ch++) {
		if ((*(ch + 1)) == NULL)
			ast_print(*ch, ch_prefix, 1);
		else
			ast_print(*ch, ch_prefix, 0);
	}
}

ast_node* ast_dbg(char* debug) {
	// printf("new %s\n",debug);
	int len = strlen(debug);
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));
	node->debug = (char *)calloc(len + 3, sizeof(char));
	node->debug[0] = '\"';
	strncpy(node->debug + 1, debug, len);
	node->debug[1 + len] = '\"';
	node->debug[2 + len] = '\0';
	// node->debug = debug;
	node->ch = (ast_node **)calloc(1, sizeof(ast_node*));
	return node;
}

ast_node* ast_newNode1(ast_node* c1) {
    ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(2, sizeof(ast_node*));
	node->ch[0] = c1;
	return node;
}

ast_node* ast_newNode2(ast_node* c1, ast_node* c2) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(3, sizeof(ast_node*));
	node->ch[0] = c1;    
	node->ch[1] = c2;
	return node;
}

ast_node* ast_newNode3(ast_node* c1, ast_node* c2, ast_node* c3) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(4, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	return node;
}

ast_node* ast_newNode4(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(5, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	return node;
}

ast_node* ast_newNode5(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(6, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	return node;
}

ast_node* ast_newNode6(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(7, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	node->ch[5] = c6;
	return node;
}

ast_node* ast_newNode7(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(8, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	node->ch[5] = c6;
	node->ch[6] = c7;
	return node;
}

ast_node* ast_newNode8(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7, ast_node* c8) {
	ast_node* node = (ast_node *)calloc(1, sizeof(ast_node));

    node->ch = (ast_node **)calloc(9, sizeof(ast_node*));
	node->ch[0] = c1;
	node->ch[1] = c2;
	node->ch[2] = c3;
	node->ch[3] = c4;
	node->ch[4] = c5;
	node->ch[5] = c6;
	node->ch[6] = c7;
	node->ch[7] = c8;
	return node;
}




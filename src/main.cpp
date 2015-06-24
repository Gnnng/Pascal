#include <iostream>

#include "ast.h"
#include "CodeGenContext.h"
#include "parser.hpp"

using namespace std;

extern int yyparse();
extern ast::Program* ast_root;

int main(int argc, char** argv) {
	yyparse();
	cout << ast_root << endl;

	InitializeNativeTarget();
	CodeGenContext context;
	//createCoreFunctions(context);
	context.generateCode(*ast_root);
	context.runCode();

	return 0;
}
#include <iostream>
#include <stdexcept>

#include "ast.h"
#include "CodeGenContext.h"
#include "parser.hpp"
#include "ccalc.h"

using namespace std;

extern int yyparse();
extern ast::Program* ast_root;

std::string red(const std::string& str) {
	string red_b = "\033[1;31m";
	string red_e = "\033[0m";
	return red_b + str + red_e;
}
std::string green(const std::string& str) {
	string red_b = "\033[1;32m";
	string red_e = "\033[0m";
	return red_b + str + red_e;
}

int main(int argc, char** argv) {
	init_buffer();
	yyparse();
	extern int parseError;
	if (parseError) return 1;
	cout << green("syntax check success!") << endl;
	cout << ast_root << endl;

	InitializeNativeTarget();
	CodeGenContext context;
	//createCoreFunctions(context);
	try {
		context.generateCode(*ast_root);
		context.runCode();
	} catch (const std::domain_error &de) {
		cout << red(de.what()) << endl;		
	} catch (...) {
		cout << "other uncaught error" << endl;
	}
	
	return 0;
}
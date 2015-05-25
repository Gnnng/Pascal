NAME=pascal

all:
	bison -d pascal.y
	flex pascal.l
	gcc -o ${NAME} utils.c ${NAME}.tab.c lex.yy.c -ll -g

NAME=pascal

all:
	bison -d ${NAME}.y
	flex pascal.l
	gcc -o ${NAME} utils.c ${NAME}.tab.c lex.yy.c ccalc.c -ll -g

# make debug - check the bison output report
debug:
	bison -d ${NAME}.y -v

clean:
	-rm ${NAME}.output

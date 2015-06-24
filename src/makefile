NAME = pascal

LLVM_CONFIG = /usr/local/opt/llvm/bin/llvm-config
FLAGS = `$(LLVM_CONFIG) --cxxflags --ldflags --libs --system-libs` 
OBJS = parser.o tokenizer.o ast.o utils.o

all: $(NAME)

parser.o: ${NAME}.y
	bison -d -o parser.cpp ${NAME}.y
	g++ -c parser.cpp -o parser.o $(FLAGS)

tokenizer.o: ${NAME}.l
	flex -o tokenizer.cpp ${NAME}.l
	g++ -c tokenizer.cpp -o tokenizer.o $(FLAGS)

ast.o: ast.h ast.cpp
	g++ -c ast.cpp -o ast.o $(FLAGS)

utils.o: utils.h utils.c
	g++ -c utils.c -o utils.o $(FLAGS)

$(NAME): $(OBJS)
	g++ $(OBJS) -o pascal $(FLAGS)

# make debug - check the bison output report
debug:
	bison -d -o parser.cpp ${NAME}.y -v

clean:
	-rm parser.output *.o parser.cpp parser.hpp tokenizer.cpp

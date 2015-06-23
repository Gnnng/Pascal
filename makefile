NAME=pascal

LLVM_CONFIG = /usr/local/opt/llvm/bin/llvm-config
FLAGS = `$(LLVM_CONFIG) --cxxflags --ldflags --libs --system-libs` 

all:
	bison -d -o src/parser.cpp src/${NAME}.y
	flex -o src/tokenizer.cpp src/${NAME}.l
	g++ -o ${NAME} src/utils.c src/parser.cpp src/tokenizer.cpp -ll -g $(FLAGS)

# make debug - check the bison output report
debug:
	bison -d -o src/parser.cpp src/${NAME}.y -v

clean:
	-rm src/parser.output

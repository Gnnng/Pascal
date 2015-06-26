NAME = pascal

LLVM_CONFIG = /usr/local/opt/llvm/bin/llvm-config

NO_WARNING =  -Wno-return-type \
	-Wno-c++11-compat-deprecated-writable-strings \
	-Wno-deprecated-register \

CXXFLAGS = `$(LLVM_CONFIG) --cppflags` -std=c++11 $(NO_WARNING)
LDFLAGS = `$(LLVM_CONFIG) --ldflags`
LIBS = `$(LLVM_CONFIG) --libs --system-libs`

# FLAGS = `$(LLVM_CONFIG) --cxxflags --ldflags --libs --system-libs` 
OBJS = parser.o tokenizer.o ast.o utils.o main.o CodeGenContext.o ccalc.o

all: $(NAME)

parser.cpp: ${NAME}.y
	bison -d -o parser.cpp ${NAME}.y

parser.hpp: parser.cpp

tokenizer.cpp: ${NAME}.l
	flex -o tokenizer.cpp ${NAME}.l

%.o: %.cpp %.h
	@g++ -c $(CXXFLAGS) -g -o $@ $< 


$(NAME): $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

# make debug - check the bison output report
debug:
	bison -d -o parser.cpp ${NAME}.y -v

clean:
	@rm -f parser.output *.o parser.cpp parser.hpp tokenizer.cpp

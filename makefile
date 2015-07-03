SRC_DIR = src
LLC = /usr/local/bin/llc-3.5

all: compiler
	 make ll llvm.pas

compiler:
	$(MAKE) -C $(SRC_DIR) -j
	mv $(SRC_DIR)/pascal .

ll:
	./pascal < test/$(filter-out ll asm,$(MAKECMDGOALS)) \
	2> $(basename $(filter-out ll asm,$(MAKECMDGOALS))).ll

asm: ll
	$(LLC) -march=x86-64 $(basename $(filter-out asm,$(MAKECMDGOALS))).ll

gen:
	clang $(basename $(filter-out gen,$(MAKECMDGOALS))).s -o $(basename $(filter-out gen,$(MAKECMDGOALS)))

%:
	@:

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(RM) *.ll *.s

clean-all: clean
	$(RM) pascal
	

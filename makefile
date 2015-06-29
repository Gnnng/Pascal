SRC_DIR = src
LLC = /usr/local/opt/llvm/bin/llc
all: compiler
	 make ll llvm.pas

compiler:
	$(MAKE) -C $(SRC_DIR)
	mv $(SRC_DIR)/pascal .

ll:
	./pascal < test/$(filter-out ll asm,$(MAKECMDGOALS)) 2> $(basename $(filter-out ll asm,$(MAKECMDGOALS))).ll

asm: ll
	$(LLC) -march=x86-64 $(basename $(filter-out asm,$(MAKECMDGOALS))).ll

gen:
	clang *.s -o $(basename $(filter-out gen,$(MAKECMDGOALS)))


%:
	@:

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(RM) *.ll *.s

clean-all: clean
	$(RM) pascal
	

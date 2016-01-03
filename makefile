SRC_DIR = src
LLC = /usr/local/bin/llc-3.5

all: compiler
	 make ll llvm.pas

# Build the pascal compiler using the subdir makefile
compiler:
	$(MAKE) -C $(SRC_DIR) -j
	mv $(SRC_DIR)/pascal .

# Use our pascal compiler to compile a test file in `test` directory
# This will generate an IR file in the root directory
ll:
	./pascal < test/$(filter-out ll asm,$(MAKECMDGOALS)) \
	2> $(basename $(filter-out ll asm,$(MAKECMDGOALS))).ll

# Use llc to direct execute an IR file
asm: ll
	$(LLC) -march=x86-64 $(basename $(filter-out asm,$(MAKECMDGOALS))).ll

# Generate binary from .s file
gen:
	clang $(basename $(filter-out gen,$(MAKECMDGOALS))).s -o $(basename $(filter-out gen,$(MAKECMDGOALS)))

%:
	@:

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(RM) *.ll *.s

clean-all: clean
	$(RM) pascal
	

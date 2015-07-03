SRC_DIR = src
LLC = /usr/local/bin/llc-3.5

all: compiler
	 make ll test2.pas
	 make ll test3.pas
	 make ll test4.pas
#	 make ll test5.pas
	 make ll test6.pas
	 make ll test7.pas


compiler:
	$(MAKE) -C $(SRC_DIR) -j
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
	

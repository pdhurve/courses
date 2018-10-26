CODE_DIR = lib

.PHONY: lib

compiler: lex.yy.o y.tab.o ass5_15CS10031_translator.o ass5_15CS10031_target_translator.o
	g++ lex.yy.o y.tab.o ass5_15CS10031_translator.o \
	ass5_15CS10031_target_translator.o -lfl -o compiler \
	

ass5_15CS10031_target_translator.o: ass5_15CS10031_target_translator.cxx
	g++ -c ass5_15CS10031_target_translator.cxx

ass5_15CS10031_translator.o: ass5_15CS10031_translator.cxx ass5_15CS10031_translator.h
	g++ -c ass5_15CS10031_translator.h
	g++ -c ass5_15CS10031_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass5_15CS10031.l y.tab.h ass5_15CS10031_translator.h
	flex ass5_15CS10031.l

y.tab.c: ass5_15CS10031.y
	yacc -dtv ass5_15CS10031.y -W

y.tab.h: ass5_15CS10031.y
	yacc -dtv ass5_15CS10031.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass5_15CS10031_translator.o y.output compiler ass5_15CS10031_target_translator.o

cleanLib:
	$(MAKE) -C $(CODE_DIR) clean

test: 
	./compiler testBubbleSort.c

asm:
	./compiler -s test4.s test4.c > test4.log
	./compiler -s test1.s test1.c > test1.log
	./compiler -s test2.s test2.c > test2.log
	./compiler -s test3.s test3.c > test3.log
	./compiler -s testBubbleSort.s testBubbleSort.c > testBubbleSort.log

lib:
	$(MAKE) -C $(CODE_DIR)

a.out: lex.yy.o y.tab.o ass4_15CS10031_translator.o
	g++ lex.yy.o y.tab.o ass4_15CS10031_translator.o -lfl

ass4_15CS10031_translator.o: ass4_15CS10031_translator.cxx ass4_15CS10031_translator.h
	g++ -c ass4_15CS10031_translator.h
	g++ -c ass4_15CS10031_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass4_15CS10031.l y.tab.h ass4_15CS10031_translator.h
	flex ass4_15CS10031.l

y.tab.c: ass4_15CS10031.y
	yacc -dtv ass4_15CS10031.y -W

y.tab.h: ass4_15CS10031.y
	yacc -dtv ass4_15CS10031.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass4_15CS10031_translator.o y.output a.out *.gch

test: 
	./a.out < ass4_15CS10031_test1.mm > ass4_15CS10031_quads1.out
	./a.out < ass4_15CS10031_test2.mm > ass4_15CS10031_quads2.out
	./a.out < ass4_15CS10031_test3.mm > ass4_15CS10031_quads3.out
	./a.out < ass4_15CS10031_test4.mm > ass4_15CS10031_quads4.out
	
	


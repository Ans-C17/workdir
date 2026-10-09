.SUFFIXES:

all: exprtree label-translator

exprtree: exprtree.tab.c lex.yy.c exprtree.c codegen.c
	gcc exprtree.tab.c lex.yy.c exprtree.c codegen.c -o exprtree

label-translator: label-translator.c
	gcc label-translator.c -o label-translator

exprtree.tab.c exprtree.tab.h: exprtree.y
	bison -d exprtree.y

lex.yy.c: exprtree.l exprtree.tab.h
	flex exprtree.l

clean:
	rm -f exprtree exprtree.tab.c exprtree.tab.h lex.yy.c label-translator
.SUFFIXES:

# Build the compiler front end/code generator and the separate label translator.
all: exprtree label-translator

# Bison creates the parser; Flex creates the lexer; the C files provide tables and code generation.
exprtree: exprtree.tab.c lex.yy.c exprtree.c codegen.c
	gcc exprtree.tab.c lex.yy.c exprtree.c codegen.c -o exprtree

label-translator: label-translator.c
	gcc label-translator.c -o label-translator

# Generate parser and token header from the grammar.
exprtree.tab.c exprtree.tab.h: exprtree.y
	bison -d exprtree.y

# Generate the scanner after Bison has produced its token header.
lex.yy.c: exprtree.l exprtree.tab.h
	flex exprtree.l

clean:
	rm -f exprtree exprtree.tab.c exprtree.tab.h lex.yy.c label-translator exprtree.output

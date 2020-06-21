#Makefile para la compilacion del proyecto Compiladores

all:
	flex lexer.l
	byacc -d parser.y
	gcc lex.yy.c parser.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c main.c -o exe
exec:
	./exe
clean:
	rm -rf exe

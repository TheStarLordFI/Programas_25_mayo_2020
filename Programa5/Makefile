#Makefile para la compilacion del proyecto Compiladores

lexer:
	flex lexer.l
parser:
	byacc -d parser.y
allC:
	gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_direcciones.c tabla_cadenas.c -o exe
all:
	flex lexer.l
	bison -d parser.y
	gcc lex.yy.c parser.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_direcciones.c tabla_cadenas.c main.c -o exe
exec:
	./exe
clean:
	rm -rf exe
	rm -rf lex.yy.c 
	rm -rf y.tab.c
	rm -rf y.tab.h

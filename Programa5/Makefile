#Makefile para la compilacion del proyecto Compiladores

lexer:
	flex lexer.l
parser:
	byacc -d parser.y
allC:
	gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_direcciones.c tabla_cadenas.c main.c -o exe
all:
	flex lexer.l
	byacc -d parser.y
	gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_direcciones.c tabla_cadenas.c main.c -o exe
parserT:
	byacc -d parser_pruebas.y
prueba:
	flex lexer.l
	byacc -d -v parser_pruebas.y
	gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c pila_direcciones.c tabla_cadenas.c main.c -o prueba
test:
	./prueba entrada
exec2:
	./exe
exec:
	./exe entrada
clean:
	rm -rf exe
	rm -rf prueba
	rm -rf lex.yy.c 
	rm -rf y.tab.c
	rm -rf y.tab.h

# ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "data.h"

void append sym (SYMTAB ∗t,SYM s) ; //Agrega a l f i n a l de la tabla un nuevo simbolo
void clear sym tab (SYMTAB ∗t) ; // Deja vacia la tabla

SYMTAB pop_st (SSTACK ∗s) ; // Ejecuta un pop sobre la p i la de tablas de simbolos
void push_st (SSTACK ∗s,SYMTAB ∗st) ; // Ing resa una tabla a la p i la de tablas de simbolos
SSTACK *init_sym_tab_stack(); // Reserva memoria para la p i la
SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de simbolos vacia
SYM ∗init_sym (); // Reserva memoria para un simbolo vacio

void finish_sym_tab_stack(SSTACK ∗s); // Libe ra la memoria para la p i la
void finish_sym_tab(SYMTAB ∗st); // Libe ra memoria para una tabla de simbolos
void finis_sym (SYM ∗s); // l ibe ra memoria para un simbolo vacio
void print_tab (SYMTAB ∗t); // Imprime en pantalla la tabla de simbolos

#endif

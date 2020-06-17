#ifndef TYPTAB_H
#define TYPTAB_H
#include "data. h"
void append_type ( TYPTAB ∗tt, SYM t); //Agrega a l f i n a l de la tabla un nuevo t ipo
void clear_type_tab ( TYPTAB ∗tt); // Deja vacia la tabla
SYMTAB pop_st ( TSTACK ∗s); // Ejecuta un pop sobre la p i la de tablas de t ipo s
void push_st ( TSTACK ∗s , TYPTAB ∗tt); // Ing resa una tabla a la p i la de tablas de t ipo s
TSTACK ∗init_type_tab_stack(); // Reserva memoria para la p i la
TYPTAB ∗init_type tab(); // Reserva memoria para una tabla de t ipo s e i n se r ta l o s t ipo s na tivos
TYP ∗init_type(); // Reserva memoria para un t ipo
void finish_sym_stack(SSTACK ∗s); // Libe ra la memoria para la p i la
void finish_sym (SYMTAB ∗st) ; // Libe ra memoria para una tabla de t ipo s
void finis_sym(SYM ∗s); // l ibe ra memoria para un t ipo
void print_tab (SYMTAB ∗t); // Imprime en pantalla la tabla de t ipo s
#endif

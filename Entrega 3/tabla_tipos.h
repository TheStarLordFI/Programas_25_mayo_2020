#ifndef TYPTAB_H
#define TYPTAB_H
#include <stdbool.h>
#include "data.h"
void append_type(TYPTAB *tt,TYP *t); //*Agrega a l f i n a l de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt); //*Deja vacia la tabla

TYPTAB pop_st(TSTACK *s); //*Ejecuta un pop sobre la pila de tablas de tipos
void push_st(TSTACK *s,TYPTAB *tt); //* Ing resa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); //*Reserva memoria para la pila
TYPTAB *init_type_tab(TYPTAB *tabTipos); //*Reserva memoria para una tabla de tipos e inserta los tipos nativos
TYP *init_type(); // Reserva memoria para un tipo

void init_type_base();
TYPTAB *append_natives_types(TYPTAB *tT);
TYP  *search_type(TYPTAB *tabTipos, int id);

void finish_type_tab_stack(TSTACK *s); //*Libera la memoria para la pila
void finish_type_tab(TYPTAB *st); //*Libera memoria para una tabla de tipos
void finish_type(TYP *s); //*libera memoria para un tipo

int getTam(TYPTAB *t , int id);//*Retorna el tam de un tipo
TB *getTipoBase(TYPTAB *t , int id); //*retorna el tipo base
char *getNombre( TYPTAB *t , int id ) ; //*retorna el nombre de un tipo tambien lo puede cambiar por un entero
void print_tab(TYPTAB *t ); //*Imprime en pantalla la tabla de tipos
#endif

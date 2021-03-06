#ifndef TYPTAB_H
#define TYPTAB_H
//#include <stdbool.h>
#include "data.h"
int append_type(TYPTAB *tt,TYP *t); //*Agrega a l f i n a l de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt); //*Deja vacia la tabla

TYPTAB *pop_tt(TSTACK *s); //*Ejecuta un pop sobre la pila de tablas de tipos
void push_tt(TSTACK *s,TYPTAB *tt); //* Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); //*Reserva memoria para la pila
TYPTAB *init_type_tab(TYPTAB *tabTipos); //*Reserva memoria para una tabla de tipos e inserta los tipos nativos
TYP *init_type(); // Reserva memoria para un tipo

TB *init_type_base();
TYPTAB *append_natives_types(TYPTAB *tT);
TYP  *search_type(TYPTAB *tabTipos, int id);

void finish_type_tab_stack(TSTACK *s); //*Libera la memoria para la pila
void finish_type_tab(TYPTAB *st); //*Libera memoria para una tabla de tipos
void finish_type(TYP *s); //*libera memoria para un tipo

int getTam(TYPTAB *t , int id);//*Retorna el tam de un tipo
int getTipoBase(TYPTAB *t , int id); //*retorna el tipo base
char *getNombre( TYPTAB *t , int id ) ; //*retorna el nombre de un tipo tambien lo puede cambiar por un entero
void print_tab_type(TYPTAB *t ); //*Imprime en pantalla la tabla de tipos
TYPTAB *getTopType(TSTACK *pilaTT);//Retorna el tope de la pila de tipos


TYP *set_typ(TYP *type, char *nombre, int idTipo, int tam, TYPTAB *tabTipos);
TYP *set_typ_struct(TYP *type, char *nombre, int idTipoB, TYPTAB *tabTipos,SYMTAB *tabSym);
int getTamStruct(TYPTAB *tabTipos, SYMTAB *tabSym, int idTipoB);
SYMTAB *get_TS_asoc(TYPTAB *tt, int id);
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_Tipos.h"

/*
* Función: crearTablaTipos
* Descripción: Crea la lista de las tablas de tipos
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/
void push_st ( TSTACK ∗s , TYPTAB ∗tt);{
  TYPTAB *tt;
  tt =(TYPTAB *)malloc(sizeof(tt));
  strcpy(tt->nombreTabla, nombre);
  tt->elementosLista = 0;
  tt->head = NULL;
  tt->tail = NULL;
  return tt;
}

/*
* Función: void append_type ( TYPTAB ∗tt, SYM t);
* Descripción: Agrega al final de la tabla un nuevo tipo
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/

void append_type(TYPTAB ∗tt, SYM *t);
  int insertado = -1;
  if(tt->head == NULL){
	tt->head = t;
	tt->tail = t;
	insertado = 1;
  } else {
	(tt->tail)->sig= t;
	tt->tail= t;
	insertado = 1;
  }
  if (tt->elementosLista <= 4 ){
	tt->elementosLista++;
	return tt->elementosLista;
  }
  else if (insertado == 1){
	tt->elementosLista++;
	//printf("Tabla de tipos: tipo insertado correctamente \n");
	printf("\nInsertando en tabla de tipos:");
	imprimeTT(*tt);
	return tt->elementosLista-1;
  } else {
	printf("Tabla de tipos: ERROR! no se inserto el tipo\n");
	return insertado;
  }
}


/*
* Función: clear_type_tab
* Descripción: Deja la tabla de tipos vacía
* Autor: Mendez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/
void clear_type_tab(TYPTAB *tt){
   tipo *aux,*otro;
   aux=tt->head;
	while(aux != NULL){
  	otro = aux;
  	aux= otro -> sig;
  	borrarTipo(tt, otro);
   }
   printf("Tabla de Tipos: Se ha borrado toda la lista\n");
}


/*
* Función: void print_tab (SYMTAB ∗t);
* Descripción: imprime en pantalla la tabla de tipos
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/
void print_tab (SYMTAB ∗t);{
  tipo *tipoDato;
  tipoDato=t.head;
  printf("\n==========================================\n");
  printf("|   	TABLA  DE  TIPOS %s      	|\n", t.nombreTabla);
  printf("==========================================\n");
  printf("|  ID  |  TIPO  |  TAM  | #ELEM | T_BASE |\n");
  printf("==========================================\n");
  while(tipoDato!=NULL){
	if (tipoDato->tb->esEstructura == false)
  	printf("|%i\t|%s\t|%i\t|%i\t|%i\t|\n",tipoDato->id,tipoDato->nombreTipo,tipoDato->tamBytes,tipoDato->elementos,tipoDato->tb->tipoSimple);
	tipoDato=tipoDato->sig;
  }
  printf("=========================================\n");
}

/*
* Función: getTipoBase
* Descripción: Retorna el tipo base
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/

TB *getTipoBase (TYPTAB ∗t , int id){
  tipo *tipoDato = buscarTipo(t, id);
  return tipoDato ? tipoDato->tb : NULL;
}

/*
* Función: init_type_tab
* Descripción: Reserva memoria para una tabla de tipos e inserta los tipos nativos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
TYPTAB ∗init_type_tab(TYPTAB *t){
  int i, aux;
  SYM *tipoAux;
  char arrTiposNativos[7][5] = {"ent", "real", "car", "sin", "dreal"};
  int tamBytesNativos[5] = {4, 4, 1, 0, 8};
  for(i=0; i<5; i++){
    tipoAux = crearTipo();
    tipoAux->id = t->elementosLista;
    strcpy(tipoAux->nombreTipo, &arrTiposNativos[i][0]);
    tipoAux->tamBytes = tamBytesNativos[i];
    tipoAux->elementos = 0;
    tipoAux->tb->tipoSimple = -1;
    aux = insertarTipo(t, tipoAux);
  }
  imprimeTT(*t);
  return t;
}

/*
* Función: getNombre
* Descripción: Retorna el nombre del tipo, en caso de no encontrar NULL
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
char *getNombre(tablaTipos *t,int id){
  tipo *tipoDato = buscarTipo(t, id);
  return tipoDato ? tipoDato->nombreTipo : NULL;
}
/*
* Función: getTam
* Descripción: Retorna el numero de bytes de un tipo
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
int getTam(tablaTipos *t,int id){
  tipo * tipoDato = buscarTipo(t, id);
  return tipoDato ? tipoDato->tamBytes : -1;
}

TB getTipoBase (TYPTAB ∗t,int id){
  tipo  *tipoDato;
  tipoDato = t->head;
    while(tipoDato!=NULL){
        if (tipoDato->id == id)
            return tipoDato;
        tipoDato = tipoDato->sig;
    }
    printf ("Tabla de tipos: ERROR! El id %d no existe \n", id);
    return NULL;
}

/*
* Función: init_type_tab_stack
* Descripción: Reserva memoria para la pila
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
TSTACK ∗init_type_tab_stack()
{
  char *str;
  str = (char *) malloc(15);
  return NULL;
}

/*
* Función: popst
* Descripción: Ejecuta un pop sobre la pila de tablas de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
SYMTAB popst (TSTACK ∗s){
  tablaTipos *popListaTTipos(pilaTTipos *pilaTT){
  tablaTipos *tabTipos;
  tabTipos=pilaTT->tope;
  pilaTT->tope=tabTipos->sig;
  pilaTT->elementosPila--;
  printf("Pila de Tipos: Se ha sacado una tabla de tipos\n");
  return tabTipos;
}
/*
* Función: crearTipo
* Descripción: Crea una nueva tabla de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
tipo *crearTipo(){
    tipo *nuevoTipo;
    nuevoTipo = (tipo *)malloc(sizeof(tipo));
    nuevoTipo->sig = NULL;
    nuevoTipo->tb = crearTipoBase();
return nuevoTipo;
}

/*
* Función: finish_sym_tab_stack
* Descripción: Libera memoria para la pila
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finish_sym_tab_stack(SSTACK ∗s){
  free(s);
}

/*
* Función: finish_sym_tab
* Descripción: Libera memoria para una tabla de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finish_sym_tab(SYMTAB ∗st){
  free(st);
}

/*
* Función: finish_sym_tab
* Descripción: Libera memoria para un tipo
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finis_sym (SYM ∗S ){
  free(S);
}

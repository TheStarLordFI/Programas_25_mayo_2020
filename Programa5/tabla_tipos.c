#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_tipos.h"

/*
* Función: crearTablaTipos
* Descripción: Crea la lista de las tablas de tipos
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/
void push_tt( TSTACK *s , TYPTAB *tt){
   tt->next = s->top;
   s->top = tt;
   printf("Pila de Tipos: Se ha insertado una tabla de tipos\n");
}

/*
* Función: void append_type ( TYPTAB ∗tt, SYM t);
* Descripción: Agrega al final de la tabla un nuevo tipo
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/

int append_type(TYPTAB *tt, TYP *t){
  int insertado = -1;
  printf("append_type\n");
  if(tt->head == NULL){
    tt->head = t;
    tt->tail = t;
    insertado = 1;
    printf("append_type_1\n");
    //imprimeTT(*tabTipos);
  } else {
    (tt->tail)->next=t;
    tt->tail=t;
    insertado = 1;
  }
  if (tt->num <= 4 ){
    tt->num++;
    return tt->num;
  }
  else if (insertado == 1){
    tt->num++;
    printf("\nInsertando en tabla de tipos:");
    print_tab_type(tt);
    return tt->num-1;
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
   TYP *aux,*otro;
   aux=tt->head;
	while(aux != NULL){
  	otro = aux;
  	aux= otro->next;
  	finish_type_tab(tt);
   }
   printf("Tabla de Tipos: Se ha borrado toda la lista\n");
}


/*
* Función: void print_tab (SYMTAB ∗t);
* Descripción: imprime en pantalla la tabla de tipos
* Autor: Méndez Cabrera Ana Belem
* Fecha de creación: 31 Mayo 2020
*/
void print_tab_type(TYPTAB *t){
  TYP *tipoDato;
  tipoDato=t->head;
  printf("\n------------------------------------------\n");
  printf("|            	TABLA  DE  TIPOS            	|\n");
  printf("--------------------------------------------\n");
  printf(" |   ID   |   TIPO   |   TAM   |   T_BASE   | \n");
  printf("--------------------------------------------\n");
  while(tipoDato!=NULL){
    if (tipoDato->tb->is_est == 0 || tipoDato->tb->is_est == -1){
      printf(" |%i\t|%s\t|%i\t|-\t|\n",tipoDato->id,tipoDato->nombre,tipoDato->tam);
    }else{
      printf(" |%i\t|%s\t|%i\t|%i\t|\n",tipoDato->id,tipoDato->nombre,tipoDato->tam,tipoDato->tb->tipo.tipo);
    }
    tipoDato=tipoDato->next;
  }
  printf("-------------------------------------------\n");
}

/*
* Función: getTipoBase
* Descripción: Retorna el tipo base
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/

TB *getTipoBase(TYPTAB *t , int id){
  TYP *tipoDato = search_type(t, id);
  return tipoDato ? tipoDato->tb : NULL;
}

/*
* Función: init_type_tab
* Descripción: Reserva memoria para una tabla de tipos e inserta los tipos nativos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
TYPTAB *init_type_tab(TYPTAB *tabTipos){
  tabTipos=(TYPTAB *)malloc(sizeof(TYPTAB));
  tabTipos->num = 0;
  tabTipos->head = NULL;
  tabTipos->tail = NULL;
  tabTipos = append_natives_types(tabTipos);
  return tabTipos;
}

/*
* Función: append_natives_types
* Descripción: llena la tabla de tipos con todos los tipos nativos del lenguaje
* Autor: Osmar Juarez Aguilar
* Fecha de creación: 31 de mayo 2020
*/
TYPTAB *append_natives_types(TYPTAB *tabTipos){
  printf("Agregando tipos nativos\n");
  int i;
  int aux=0;
  TB *tipoB = (TB *)malloc(sizeof(TB));
  char arrTiposNativos[7][5] = {"ent", "real", "car", "sin", "dreal"};
  int tamBytesNativos[5] = {4, 4, 1, 0, 8};
  TYP *tipoAux;

  for(i=0; i<5; i++){
    tipoAux=(TYP *)malloc(sizeof(TYP));
    //tipoB = init_type_base(tipoB);
    tipoAux->id = tabTipos->num;
    //printf("%d\n", tipoAux->id);
    strcpy(tipoAux->nombre, &arrTiposNativos[i][0]);
    //printf("%s\n", tipoAux->nombre);
    tipoAux->tam = tamBytesNativos[i];
    tipoAux->tb = tipoB;
    tipoAux->tb->tipo.tipo= -1; //significa que es un tipo de base nativo
    aux = append_type(tabTipos,tipoAux);
    if(aux!=-1){
      printf("Tipo nativo agregado\n");
    }else{
      printf("ERROR => Tipo nativo NO agregado\n");
    }
  }
  return tabTipos;
}

/*
* Función: init_type
* Descripción: Crea un nuevo tipo 
* Autor: Osmar Juarez Aguilar
* Fecha de creación: 31 de mayo 2020
*/
TYP *init_type(){
    TYP *nuevoTipo;
    nuevoTipo = (TYP *)malloc(sizeof(TYP));
    nuevoTipo->next = NULL;
    nuevoTipo->tb = NULL;
    //printf("Se ha creado un tipo\n");
return nuevoTipo;
}

/*
* Función: init_type_base
* Descripción: Crea un nuevo tipo 
* Autor: Osmar Juarez Aguilar
* Fecha de creación: 31 de mayo 2020
*/
void init_type_base(){
  TB *tipoB;
  tipoB = (TB *)malloc(sizeof(TB));
  tipoB->is_est = -1;
  tipoB->tipo.tipo = -2; // significa que aún no sabemos que tipo de base tiene
  tipoB->tipo.est = NULL;
  //printf("Se ha creado un tipo base\n");
  //return tipoB;
}

/*
* Función: getNombre
* Descripción: Retorna el nombre del tipo, en caso de no encontrar NULL
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
char *getNombre(TYPTAB *t,int id){
  TYP *tipoDato = search_type(t, id);
  return tipoDato ? tipoDato->nombre : NULL;
}


/*
* Función: search_type
* Descripción: Busca un tipo mediante su id y lo retorna
* Autor: Osmar Juarez Aguilar
* Fecha de creación: 31 de mayo 2020
*/
TYP  *search_type(TYPTAB *tabTipos, int id){
  TYP  *tipoDato;
  tipoDato = tabTipos->head;
    while(tipoDato!=NULL){
        if (tipoDato->id == id)
            return tipoDato;
        tipoDato = tipoDato->next;
    }
    printf ("Tabla de tipos: ERROR! El id %d no existe \n", id);
    return NULL;
}

/*
* Función: getTam
* Descripción: Retorna el numero de bytes de un tipo
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
int getTam(TYPTAB *t,int id){
  TYP *tipoDato = search_type(t, id);
  return tipoDato ? tipoDato->tam : -1;
}

/*
* Función: init_type_tab_stack
* Descripción: Reserva memoria para la pila
* Autor: Rodríguez Sánchez José Andrés
* Modifico: Osmar Juarez Aguilar
* Fecha de creación: 31 Mayo 2020
*/
TSTACK *init_type_tab_stack(){
  printf("Creando la pila de tabla de tipos\n");
  TSTACK *pila ;
  pila=(TSTACK*)malloc(sizeof(TSTACK));
  pila->top = NULL;
  pila->tail = NULL;
  return pila;
}

/*
* Función: popst
* Descripción: Ejecuta un pop sobre la pila de tablas de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
TYPTAB *pop_tt(TSTACK *s){
  TYPTAB *tabTipos;
  tabTipos=s->top;
  s->top=tabTipos->next;
  //s->elementosPila--;
  printf("Pila de Tipos: Se ha sacado una tabla de tipos\n");
  return tabTipos;
}

/*
* Función: finish_sym_tab_stack
* Descripción: Libera memoria para la pila
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finish_type_tab_stack(TSTACK *s){
  free(s);
}

/*
* Función: finish_sym_tab
* Descripción: Libera memoria para una tabla de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finish_type_tab(TYPTAB *st){
  free(st);
}

/*
* Función: finish_sym_tab
* Descripción: Libera memoria para un tipo
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
void finish_type(TYP *S ){
  free(S);
}

TYP *set_typ(TYP *type, char *nombre, int idTipo, TYPTAB *tabTipos){
  TYP *aux;
  int intAux;
  type->id = tabTipos->num;
  strcpy(type->nombre, nombre);
  if( type->tb->is_est == 0){ //si es un tipo simple
    aux = search_type(tabTipos, idTipo);
    if (aux != NULL ) //significa que sí encontró ese tipo de dato
      type->tb->tipo.tipo= aux->id;
    else
     printf("Tabla de Tipos: ERROR! No se pudo insertar el tipo %s, no existe el tipo base %i \n", nombre, idTipo);
  }
  else {
    /* En caso de que sea estructura */
  }
  aux = search_type(tabTipos, idTipo);
  type->tam = getTam(tabTipos, type->id);
  return type;
}

/*
* Función: getTopType
* Descripción: Retorna la cima de la pila de tipos
* Autor: Osmar Juarez Aguilar
* Fecha de creación: 12 de junio 2020
*/
TYPTAB *getTopType(TSTACK *pilaTT){
  return pilaTT->top;
}
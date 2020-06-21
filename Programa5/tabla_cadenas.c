#include <stdlib.h>
#include <stdio.h>
#include "tabla_cadenas.h"

/*
* Función: crearCadena
* Descripción: Crea una nueva cadena con el valor especificado
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 16 de junio
*/
CAD *crearCadena(char *cadena){
  CAD *cad;
  cad = (CAD *)malloc(sizeof(CAD));
  cad->valor = cadena;
  cad->sig = NULL;
  return cad;
}

/*
* Función: crearTablaCadenas
* Descripción: Crea una tabla que alamacenará las cadena
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 16 de junio
*/
CADTAB *crearTablaCadenas(){
  CADTAB *tc;
  tc = (CADTAB*)malloc(sizeof(CADTAB));
  tc->elementos = 0;
  tc->head = NULL;
  tc->tail = NULL;
  printf("Se he creado una Tabla de Cadenas\n");
  return tc;
}

/*
* Función: insertarCadena
* Descripción: Inserta al final de la tabla de cadenas e incrementa el número de
*   elementos
* Autor: Osmar Juarez Aguilar, Morales Garcia Luis
* Fecha de creación: 16 de junio
*/
void insertarCadena(CADTAB *tabCadenas,CAD *cadena){
  if(tabCadenas->head == NULL){
    tabCadenas->head = cadena;
    tabCadenas->tail = cadena;
    tabCadenas->elementos++;
  }
  else {
    (tabCadenas->tail)->sig = cadena;
    tabCadenas->tail = cadena;
    tabCadenas->elementos++;
  }
  return;
}

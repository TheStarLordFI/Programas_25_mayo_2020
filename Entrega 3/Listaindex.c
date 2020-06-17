#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaIndex.h"
int contadorLabel=0;
int contadorIndices=0;
/*
* Función: crearIndex
* Descripción: Crea una nueva indice con el valor especificado
* Autor: 
* Fecha de creación:
*/
myIndex *crearIndex(){
  myIndex *indi;
  contadorIndices++;
  indi = (myIndex *)malloc(sizeof(myIndex));
  indi->valorMyIndex =contadorIndices;
  indi->sig = NULL;
  return indi;
}

/*
* Función: crearTablaCadenas
* Descripción: Crea una tabla que alamacenará las indice
*/
listIndex *crearListIndex(){
  listIndex *listIndice;
  listIndice = (listIndex*)malloc(sizeof(listIndex));
  listIndice->elementos = 0;
  listIndice->head = NULL;
  listIndice->tail = NULL;
  return listIndice;
}

/*
* Función: insertarCadena
* Descripción: Inserta al final de la tabla de myIndex e incrementa el número de
*   elementos
*/
void insertarIndex(listIndex *listIndice, myIndex *indice){
  if(listIndice->head == NULL){
	listIndice->head = indice;
	listIndice->tail = indice;
	listIndice->elementos++;
   /* indice->valorMyIndex = listIndice->elementos;
	printf("valor de indice %d\n",indice->valorMyIndex);*/
  }
  else {
	(listIndice->tail)->sig = indice;
	listIndice->tail = indice;
	listIndice->elementos++;
	/*indice->valorMyIndex = listIndice->elementos;
 	printf("valor de indice %d\n",indice->valorMyIndex);*/
  }
}

char *crearLabel(){
  contadorLabel++;
  char *etiqueta=(char*)malloc(sizeof(char));
  char *tmp=(char*)malloc(sizeof(char));
  strcpy(etiqueta, "L");
  sprintf(tmp, "%i", contadorLabel);
  strcat(etiqueta, tmp);
  return etiqueta;
}

listIndex *combinar(listIndex *lista1, listIndex *lista2){
  listIndex *lista3;
   lista3 = crearListIndex();
   if (lista1 == NULL && lista2 == NULL )
   {
 	return lista3;
   }
  else if(lista1 == NULL )
  {
 	lista3->head = lista2->head;
 	lista3->tail = lista2->tail;

  }
  else if (lista2 == NULL)
  {
	lista3->head = lista1->head;
	lista3->tail = lista1->tail;
  }
  else if ((lista2->head != NULL && lista2->tail!= NULL) && (lista1->head != NULL && lista1->tail!= NULL) ){
  lista3->head = lista1->head;
  lista3->tail = lista1->tail;
  lista3->tail->sig = lista2->head;
  lista3->tail = lista2->tail;
 }
  return lista3;
}

/*Fecha: 29/mayo/2020*/
/*Autores: Ana Belem Méndez Cabrera*/
/*Descripción: Creación de pila,elimina,push, revisar la cima de la  pila*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaTSimbolos.h"
#include "tablaSimbolos.h"

/* Función: crearpilaTSimbolos
* Descripción: Construye/crea la pila*/
pilaTSimbolos *crearPilaTSimbolos()
{
  printf("Creando la pila de tabla de simbolos\n");
  pilaTSimbolos *pilaS;
  pilaS=(pilaTSimbolos*)malloc(sizeof(pilaTSimbolos));
  pilaS->tope=NULL;
  pilaS->elementosPila = 0;
  return pilaS;
}

/* Función: borrarpilaTSimbolos
* Descripción: Elimina de la pila*/
void borrarPilaTSimbolos(pilaTSimbolos *pilaTS){
  printf("Pila de Simbolos: Borrando toda la pila\n");
  tablaSimbolos *tabSimbolos,* listaAux;
  tabSimbolos = pilaTS->tope;
  while(tabSimbolos->sig != NULL)
  {
	listaAux = tabSimbolos;
	tabSimbolos = tabSimbolos->sig;
	free(listaAux);
  }
  free(pilaTS);
}

/* Función: pushListaTS
* Descripción:Realizala acción de Insertar en la pila*/
void pushListaTS(tablaSimbolos *tabSimbolos, pilaTSimbolos *pilaTS){
   tabSimbolos->sig = pilaTS->tope;
   pilaTS->tope = tabSimbolos;
   pilaTS->elementosPila++;
  printf("Pila de Simbolos: Se ha insertado una tabla de simbolos\n");
}

void imprimePS(pilaTSimbolos pila){
	tablaSimbolos *q;
	q=pila.tope;
	if (pila.tope!=NULL){
  	printf("\n=========================================\n");
  	printf("|     	PILA TABLA DE SIMBOLOS    	|\n");
  	printf("=========================================\n");
  	while(q!=NULL){
    	imprimeTS(*q);
    	q=q->sig;
  	}
  	printf("=========================================\n");
	}
	else
 	printf("No hay datos en la pila...");
	printf("\n");
}

/* Función: getCima
* Descripción:Revisa si la pila se encuentra vacía*/
tablaSimbolos *getCima(pilaTSimbolos *pilaTS){
  return pilaTS->tope;
}

/* Función: pushListaTS
* Descripción:Realiza push a la lista
*/
tablaSimbolos *popListaTS(pilaTSimbolos *pilaTS){
  tablaSimbolos *tabSimbolos;
  tabSimbolos=pilaTS->tope;
  pilaTS->tope=tabSimbolos->sig;
  pilaTS->elementosPila--;
  printf("Pila de Simbolos: Se ha sacado una tabla de simbolos\n");
  return tabSimbolos;
}

/*Realiza acción con aquellas funciones que tienen argumentos*/
void obtieneArgs(simbolo *simbol, pilaTSimbolos *pilaTS, tablaSimbolos *tabSimbolos){
  simbolo *simbolAux;
  char cadenaArgs;
  if (pilaTS->tope != tabSimbolos){ /*Aquí se muestra si existen argumentos*/
	simbolAux = tabSimbolos->head;
	while(simbolAux != NULL){
  	if(strcmp(simbolAux->tipoVar, "param")){
  	        }
	}
  }

}

/*Fondo de pila*/
tablaSimbolos *obtieneFondo(pilaTSimbolos *pila){
  tablaSimbolos *tabSimbolos;
  tabSimbolos = pila->tope;
  if (pila->tope != NULL){
	while(tabSimbolos->sig != NULL)
  	tabSimbolos = tabSimbolos->sig;
   return tabSimbolos;
  }
  else{
	printf("Pila Tabla Simbolos: No hay datos en la pila");
	return NULL;
  }
}

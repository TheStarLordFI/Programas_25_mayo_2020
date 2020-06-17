#ifndef PILATSIMBOLOS_H_INCLUDED
#define PILATSIMBOLOS_H_INCLUDED
#include "tablaSimbolos.h"

typedef struct _pilaTSimbolos pilaTSimbolos;
struct _pilaTSimbolos{
  tablaSimbolos *tope;
  int elementosPila;
};


pilaTSimbolos *crearPilaTSimbolos();
void imprimePS(pilaTSimbolos pila);
void borrarPilaTSimbolos(pilaTSimbolos *pilaTS);
void pushListaTS(tablaSimbolos *tabSimbolos, pilaTSimbolos *pilaTS);
tablaSimbolos *getCima(pilaTSimbolos *pilaTS);
tablaSimbolos *popListaTS(pilaTSimbolos *pilaTS);
tablaSimbolos *obtieneFondo(pilaTSimbolos *pila);
#endif

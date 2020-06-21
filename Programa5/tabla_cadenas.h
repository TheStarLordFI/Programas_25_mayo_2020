#ifndef TABLACADENAS_H_INCLUDED
#define TABLACADENAS_H_INCLUDED

typedef struct tablaCadenas CADTAB;
typedef struct cadenas CAD;

struct cadenas{
  char *valor;
  CAD *sig;
};


struct tablaCadenas{
  int elementos;
  CAD *head;
  CAD *tail;
};

CAD *crearCadena(char *cadena);
CADTAB *crearTablaCadenas();
void insertarCadena(CADTAB *tabCadenas, CAD *cadena);

#endif

#typedef struct arg ARG;

struct args{
    int arg;
    ARG next;
    };

typedef struct args{
    ARG ∗head;
    ARG ∗tail ;
    int num; // numero de elementos en la lista
    };

typedef struct sym SYM;

struct sym{
    int dir ; //direccion para la variable
    int tipo ; // tipo como indice a la tabla de tipos
    char id [33]; // identificador
    ARGS ∗args; // Lista de argumentos
    int num; // numero de argumentos
    int var; // tipo de variable
    SYM ∗next; // apuntador al siguiente simbolo
    };

typedef struct sym tab SYMTAB;
struct sym tab{
    SYM ∗head;
    SYM ∗tail ;
    int num; //Numero de elementos en la tabla
    SYMTAB ∗next; // apuntador a la tabla siguiente
    };

typedef struct sym stack{
    SYMTAB ∗top;
    SYMTAB ∗tail;
    }SSTACK;

typedef struct tipobase{
    int is est ; //1: si es estructura 0: si es tipo simple −1:si no tiene tipo base
    union{
        SYMTAB ∗est ;
        int tipo ;
        } tipo ;
    }TB;

typedef struct type TYP;

struct type{
    int id ;
    char nombre[12];
    TB tb;
    int tam;
    TYP ∗next; //apuntador al siguiente tipo en la tabla de tipos
    };

/*
* Estructura: pilaTTipos
* Descripción: Estructura creata para la pila de tipos
* Autor: Rodríguez Sánchez José Andrés
* Fecha de creación: 31 Mayo 2020
*/
typedef struct _pilaTTipos pilaTTipos;
  struct _pilaTTipos{
    tab *tope;
    int elementosPila;
  };


typedef struct type tab TYPTAB;

struct type tab{
    TYP ∗head;
    TYP ∗tail ;
    int num; //Contador de elementos en la tabla
    TYPTAB ∗next; //apuntador a la tabla siguiente
};

typedef struct typ stack{
    TYPTAB ∗top;
    TYPTAB ∗tail ;
}TSTACK;

tipo *crearTipo();
tipoBase *crearTipoBase();

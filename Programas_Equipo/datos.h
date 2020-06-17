typedef struct arg ARG;
struct args{
int arg ;
ARG next;
};

typedef struct args{
ARG ∗head;
ARG ∗tail ;
int num; // numero de elementos en la l i s t a
};

typedef struct sym SYM;

struct sym{
int dir; // direccion para la va riable
int tipo; // tipo como indice a la tabla de t ipo s
char id [33] ; // iden t i f icado r
ARGS ∗args; // L i s t a de argumentos
int num; // numero de argumentos
int var; // t ipo de va riable
SYM ∗next; // apuntador a l s igu ien te simbolo
};

typedef struct sym_tab SYMTAB;

struct sym tab{
SYM ∗head;
SYM ∗ tail ;
int num; //Numero de elementos en la tabla
SYMTAB ∗next; // apuntador a la tabla s igu ien te
};

typedef struct sym stack{
  SYMTAB ∗top ;
  SYMTAB ∗tail;
}SSTACK;

typedef struct tipobase{
  int is_est; // 1: s i es e s t ruc tu ra 0: s i es t ipo simple −1: s i no tiene t ipo base
  union{
    SYMTAB ∗est ;
    int tipo ;
  }tipo;
}TB;
typedef struct type TYP ;
struct type{
  int id;
  char nombre [12] ;
  TB tb;
  int tam;
  TYP ∗next; //apuntador a l s igu ien te t ipo en la tabla de t ipo s
};

typedef struct type_tab TYPTAB;

struct type tab{
  TYP ∗head;
  TYP ∗tail;
  int num; //Contador de elementos en la tabla
  TYPTAB ∗next; //apuntador a la tabla s igu ien te
};
typedef struct typ_stack{
  TYPTAB ∗top;
  TYPTAB ∗tail;
}TSTACK;

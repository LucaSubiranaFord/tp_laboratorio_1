#include "ArrayList.h"

typedef struct
{
    char nombre[20];
    int id;
    char apellido[20];
    char isEmpty[10];
}eLista;

typedef struct
{
    char tarea[20];
    int prioridad;
    int tiempo;
}eTexto;

parseData(FILE*, ArrayList*,ArrayList*);
dividirLista(ArrayList*,ArrayList*,ArrayList*);
eLista* constructorDefecto();
int ordenar(eTexto*, eTexto*);
int ordenarAlfabeticamente(eTexto*, eTexto*);

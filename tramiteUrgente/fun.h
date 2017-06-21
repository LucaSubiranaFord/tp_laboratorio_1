#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    int tramite; // 0 REGULAR -- 1 URGENTE
    char nombre[50], apellido[50], apeNombre[200];
    int dni, turno;
}ePersona;

int ordenarPorNombre(ArrayList*);
mostrarPersona(int, ArrayList*);
proximoCliente(ArrayList*, ArrayList*);
tramiteUrgente(ArrayList*);
tramiteRegular(ArrayList*);
ePersona* newPersona(void);
listar(ArrayList*);

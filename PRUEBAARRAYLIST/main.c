#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "f.h"



int main()
{
    ArrayList* lista;
    lista = al_newArrayList();
    ePersona* persona;
    persona = (ePersona*) malloc(sizeof(ePersona));

    FILE* arch;
    int i;

    parseLista(lista,arch);

      for(i=0;i<al_len(lista);i++)
    {

        persona = al_get(lista,i);
        printf("%s --- %s --- %s ---%d\n", persona->nombre, persona->apellido, persona->isEmpty, persona->numero);
    }


    return 0;
}


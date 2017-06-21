#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "f.h"


parseLista(ArrayList* lista, FILE* arch)
{
    ePersona* aux;
    int i;
    char nombre[50], apellido[50], num[50],isEmpty[50];

    arch = fopen("data.csv", "r");

    fscanf(arch,"%[^,],%[^,],%[^,],%[^\n]\n",num, nombre, apellido, isEmpty);

    while(!feof(arch))
    {
        fscanf(arch,"%[^,],%[^,],%[^,],%[^\n]\n",num, nombre, apellido, isEmpty);
        aux = (ePersona*) malloc(sizeof(ePersona));
        strcpy(aux->nombre,nombre);
        strcpy(aux->apellido,apellido);
        aux->numero = atoi(num);
        strcpy(aux->isEmpty, isEmpty);

        al_add(lista,aux);
    }

    fclose(lista);
}



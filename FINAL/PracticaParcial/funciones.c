#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

dividirLista(ArrayList* lista, ArrayList* lista1, ArrayList* lista2)
{
    eLista* aux;
    int i;

    for(i=0;i<al_len(lista);i++)
    {
        aux = constructorDefecto();
        aux = al_get(lista,i);

        if( strcmp(aux->isEmpty,"true") == 0 )
        {
            al_add(lista1,aux);
        }else
        {
            al_add(lista2,aux);
        }
    }

     for(i=0;i<al_len(lista1);i++)
    {
        aux = al_get(lista1,i);
        printf("%d -- %s -- %s -- %s\n",aux->id, aux->nombre, aux->apellido, aux->isEmpty);
    }

    for(i=0;i<al_len(lista2);i++)
    {
        aux = al_get(lista2,i);
        printf("%d -- %s -- %s -- %s\n",aux->id, aux->nombre, aux->apellido, aux->isEmpty);
    }
}


eLista* constructorDefecto()
{
    eTexto* aux;
    aux = (eTexto*) malloc(sizeof(eTexto));
    return aux;
}


parseData(FILE* archivo, ArrayList* lista, ArrayList* listaTexto)
{
    archivo = fopen("texto.csv", "r");
    int i;
    eTexto* aux;
    char tarea[20], prioridad[20], tiempo[20];
    fscanf(archivo, "%[^,],%[^,],%[^\n]\n",tarea, prioridad, tiempo);

    while(!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^\n]\n",tarea, prioridad, tiempo);
        aux = constructorDefecto();

        aux->tiempo = atoi(tiempo);
        aux->prioridad = atoi(prioridad);
        strcpy(aux->tarea, tarea);

        al_add(lista, aux);

    }
    fclose(archivo);


    for(i=0;i<al_len(lista);i++)
    {
        aux = al_get(lista,i);
        printf("-- %s -- %d -- %d\n",aux->tarea, aux->prioridad, aux->tiempo);
    }

}


int ordenar(eTexto* primerElemento, eTexto* segundoElemento)
{
    if(primerElemento->tiempo < segundoElemento->tiempo)
    {
        return -1;
    }else if(primerElemento->tiempo > segundoElemento->tiempo)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int ordenarAlfabeticamente(eTexto* primerElemento, eTexto* segundoElemento)
{
    if(strcmp(primerElemento,segundoElemento) < 0)
    {
        return -1;
    }else if(strcmp(primerElemento,segundoElemento) > 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

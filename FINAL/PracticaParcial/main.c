#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
     char seguir='s';
     int opcion=0;
     ArrayList* listaGeneral;
     listaGeneral = al_newArrayList();
     ArrayList* listaPrimero;
     listaPrimero = al_newArrayList();
     ArrayList* listaSegundo;
     listaSegundo = al_newArrayList();

     eTexto* aux;
     aux = constructorDefecto();
     ArrayList* listaTexto;
     listaTexto = al_newArrayList();
     FILE* archivo;


     int i,j;
    while(seguir=='s')
    {
        printf("1- PARSE LISTA\n");
        printf("2- DIVIDIR LISTAS\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            parseData(archivo, listaGeneral, listaTexto);
                break;
            case 2:
            dividirLista(listaGeneral,listaPrimero,listaSegundo);
                break;
            case 3:

    printf("//////////////\n");

            al_sort(listaGeneral,ordenarAlfabeticamente,1);

                for(i=0;i<al_len(listaGeneral);i++)
    {
        aux = al_get(listaGeneral,i);
        printf("%s\n",aux->tarea);
    }
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

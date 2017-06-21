#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"



int main()
{
    char seguir='s';
    int opcion=0;
    int aux;
    ArrayList* lista;
    eMovie* movie;

    lista = al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
               movie = agregarPelicula();
               aux = al_add(lista,movie);
               if(aux == 0)
               {
                  printf("%s -- %d\n", movie->titulo, movie->puntaje);
               }
               else
               {
                   printf("La pelicula no ha podido agregarse! \n");
               }

                break;
            case 2:
                eliminarPelicula(lista);
                break;
            case 3:
                modificarPelicula(lista);
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

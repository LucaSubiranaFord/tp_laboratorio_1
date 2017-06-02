#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    ArrayList* lista;
    eMovie* aux;
    lista = al_newArrayList();
    int i;

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
                agregarPelicula(lista);
                break;
            case 2:
                borrarPelicula(lista);
                break;
            case 3:
                modificarPelicula(lista);
               break;
               case 4:
                   generarPagina(lista);
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

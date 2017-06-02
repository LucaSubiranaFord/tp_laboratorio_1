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
    FILE* bin;

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
                system("cls");
                agregarPelicula(lista, bin);
                break;
            case 2:
                system("cls");
                borrarPelicula(lista, bin);
                break;
            case 3:
                system("cls");
                modificarPelicula(lista, bin);
               break;
               case 4:
                   system("cls");
                   generarPagina(lista);
               break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingreso una opcion incorrecta! \n");
                break;
        }
    }

    return 0;
}

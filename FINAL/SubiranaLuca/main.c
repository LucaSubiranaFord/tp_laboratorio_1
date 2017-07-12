#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir='s';
     int opcion=0;

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
                break;
            case 2:

                break;
            case 3:

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

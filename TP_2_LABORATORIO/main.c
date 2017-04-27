#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define P 20

int main()
{
    ePersona personas[P];
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarPersona(personas, P);
            break;
        case 2:
            confirmarEliminarPersona(personas, P);
            break;
        case 3:
            ordenarNombres(personas, P);
            mostrarTodos(personas, P);
            break;
        case 4:
            imprimirGraficoEdades(personas, P);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona lista[CANT];
    int i, contMenor18, contEntre19y35, contMayor35;

    inicializarEstados(lista, CANT);

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
            obtenerEspacioLibre(lista, CANT);
            agregarPersona(lista, CANT);
            break;
        case 2:
            borrarPersona(lista, CANT);
            break;
        case 3:
            ordenarLista(lista, CANT);
            mostrarLista(lista, CANT);
            break;
        case 4:

            contMenor18 = 0;
            contEntre19y35 = 0;
            contMayor35 = 0;

            for(i=0; i<CANT; i++)
            {
                if(lista[i].estado == 1)
                {


                    if(lista[i].edad < 18)
                    {
                        contMenor18++;

                    }
                    else if(lista[i].edad >19 && lista[i].edad < 35)
                    {
                        contEntre19y35++;
                    }
                    else
                    {
                        contMayor35++;
                    }
                }
            }


            imprimirGraficoEdades(contMenor18, contEntre19y35, contMayor35);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}

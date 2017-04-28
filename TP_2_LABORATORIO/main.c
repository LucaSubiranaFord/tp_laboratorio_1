#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define NUM 20


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona lista[NUM];
    int i, contMenor18, contEntre19y35, contMayor35;

    inicializarEstados(lista, NUM);

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
            obtenerEspacioLibre(lista, NUM);
            agregarPersona(lista, NUM);
            break;
        case 2:
            borrarPersona(lista, NUM);
            break;
        case 3:
            ordenarLista(lista, NUM);
            mostrarLista(lista, NUM);
            break;
        case 4:

            contMenor18 = 0;
            contEntre19y35 = 0;
            contMayor35 = 0;

            for(i=0; i<NUM; i++)
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

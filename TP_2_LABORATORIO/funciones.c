#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



imprimirGraficoEdades(int contMenor18, int contEntre19y35, int contMayor35)
{


    int i, j;
    int maxContador=0;
    int arrayContador[3] = {contMenor18, contEntre19y35, contMayor35};



    for(i=0; i<3; i++)
    {
        if(arrayContador[i] > maxContador)
        {
            maxContador = arrayContador[i];
        }

    }



    for(i=maxContador; i>0; i--)
{



        for(j=0; j<3; j++)
        {
            if(arrayContador[j] >= i)
            {
                printf("\t*");
            }
            else
            {
                printf("\t");
            }

        }

        printf("\n");
    }
    printf("\t<18\t19>35\t>35\n");


}


mostrarLista(ePersona lista[], int tam)
{
      int i;
     for(i=0; i<tam; i++)
            {
                if(lista[i].estado == 1)
                {
                    mostrarPersona(lista, i);
                }
            }
}


ordenarLista(ePersona lista[], int tam)
{
    int i, j;
    ePersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;

            }
        }

    }
}



borrarPersona(ePersona lista[], int tam)
{
    int flagConfirmarEliminar = 0;
    int i;
    int borrarDni;
    char eliminarPersona;

    printf("Ingrese el DNI de la persona que quiere eliminar: ");
    scanf("%d", &borrarDni);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1 && lista[i].dni == borrarDni)
        {
            mostrarPersona(lista, i);
            printf("\nSeguro quiere eliminar a esta persona?");
            eliminarPersona = getche();
            flagConfirmarEliminar = 1;

            if(eliminarPersona == 's')
            {
                printf("\nHa sido eliminado!");
                lista[i].estado = 0;
                break;
            }
            else
            {
                printf("\nAccion cancelada");
                break;
            }
        }

    }

    if(flagConfirmarEliminar == 0)
    {
        printf("No existe esa persona!");
    }
}



mostrarPersona(ePersona lista[], int persona)
{
    printf("Nombre: %s, Edad: %d, DNI: %d\n",lista[persona].nombre, lista[persona].edad, lista[persona].dni);
}



inicializarEstados(ePersona lista[], int tam)
{


int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = 0;
    }

    }





int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int i;
    int flag = 0;
    int espacioLibre;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            espacioLibre = i;
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        espacioLibre = -1;
    }

    return espacioLibre;
}




agregarPersona(ePersona lista[], int tam)
{
    char buffer[200];
    int espacioLibre = obtenerEspacioLibre(lista, tam);
    int i, j, auxDni;

             if(lista[espacioLibre].estado == 0 && espacioLibre != -1)
        {

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer) > 49) //VERIFICA EL TAMAÑO DEL NOMBRE INGRESADO.
            {
                printf("\nEl nombre debe contener menos de 50 caractéres!. Nuevo nombre:  ");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(lista[espacioLibre].nombre, buffer);

            printf("\nIngrese la edad de la persona: ");
            scanf("%d", &lista[espacioLibre].edad);

            printf("\nIngrese el DNI de la persona: ");
            scanf("%d", &auxDni);

            for(j=0;j<tam;j++) //VERIFICA SI EL DNI INGRESADO YA EXISTE.
            {
                while(auxDni == lista[espacioLibre].dni)
                {
                    printf("Ese DNI ya esta en uso! Ingrese uno diferente a continuacion: ");
                    scanf("%d", &auxDni);
                }

            }

            lista[espacioLibre].dni = auxDni;

            printf("\nAgregado: ");
            mostrarPersona(lista, espacioLibre);

            lista[espacioLibre].estado = 1;
        }

        if(espacioLibre == -1)
    {
        printf("\nNo hay mas espacio disponible!");
    }

    }

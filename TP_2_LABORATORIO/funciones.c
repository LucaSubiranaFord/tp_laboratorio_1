#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mostrarPersona(ePersona personas)
{
    printf("\nNombre: %s, edad: %d, dni: %d", personas.nombre, personas.edad, personas.dni);
}

restaurarEstado(ePersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado = 0;
    }
}

ordenarNombres(ePersona personas[], int tam)
{

    int i, j;
    ePersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(personas[i].nombre, personas[j].nombre) > 0)
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;

            }
        }

    }
}


agregarPersona(ePersona personas[], int tam)
{
    char buffer[200];
    int i, j, auxDni;
    char agregarOtraPersona = 's';
    int flagCapacidad = 0;
    for(i=0; i<tam; i++)
    {

             if(personas[i].estado == 0 && agregarOtraPersona == 's')
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

            strcpy(personas[i].nombre, buffer);

            printf("\nIngrese la edad de la persona: ");
            scanf("%d", &personas[i].edad);

            printf("\nIngrese el DNI de la persona: ");
            scanf("%d", &auxDni);

            for(j=0;j<tam;j++) //VERIFICA SI EL DNI INGRESADO YA EXISTE.
            {
                while(auxDni == personas[j].dni)
                {
                    printf("Ese DNI ya esta en uso! Ingrese uno diferente a continuacion: ");
                    scanf("%d", &auxDni);
                }

            }

            personas[i].dni = auxDni;

            printf("\nAgregado: ");
            mostrarPersona(personas[i]);

            personas[i].estado = 1;
            flagCapacidad = 1;

            printf("\nDesea agregar otra persona mas en este momento?(s/n)\n");
            agregarOtraPersona = getche();
        }
    }



    if(flagCapacidad == 0)
    {
        printf("\nNo hay mas espacio disponible!");
    }

        }


confirmarEliminarPersona(ePersona personas[], int tam)
{
    int flagConfirmarEliminar = 0;
    int i;
    int borrarDni;
    char eliminarPersona;

    printf("Ingrese el DNI de la persona que quiere eliminar: ");
    scanf("%d", &borrarDni);

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1 && personas[i].dni == borrarDni)
        {
            mostrarPersona(personas[i]);
            printf("\nSeguro quiere eliminar a esta persona?");
            eliminarPersona = getche();
            flagConfirmarEliminar = 1;

            if(eliminarPersona == 's')
            {
                printf("\nHa sido eliminado!");
                personas[i].estado = 0;
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

imprimirGraficoEdades(ePersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1)
        {

            if(personas[i].edad < 18)
            {
                printf("*");
            }

            if(personas[i].edad > 19 && personas[i].edad < 35)
            {
                printf("\t*\t");
            }

            if(personas[i].edad > 35)
            {
                printf("\t\t*\t\t");
            }

            printf("\n");
        }

    }

    printf("<18\t19>35\t>35");
}

mostrarTodos(ePersona personas[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
            {
                if(personas[i].estado == 1)
                {
                    mostrarPersona(personas[i]);
                }
            }
}




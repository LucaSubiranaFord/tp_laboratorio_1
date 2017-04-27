#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define P 20

typedef struct
{
    char nombre[30];
    int edad;
    int dni;
    int estado;

} ePersona;

mostrarPersona(ePersona);
restaurarEstado(ePersona[], int);
ordenarNombres(ePersona[], int);
agregarPersona(ePersona[], int);
confirmarEliminarPersona(ePersona[], int);
imprimirGraficoEdades(ePersona[], int);

int main()
{
    int borrarDni, i;
    char buffer[200];
    ePersona personas[P];
    char seguir='s';
    int opcion=0;

    restaurarEstado(personas, P);

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
            for(i=0; i<P; i++)
            {
                if(personas[i].estado == 1)
                {
                    mostrarPersona(personas[i]);
                }
            }

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
    int i;
    char agregarOtraPersona = 's';
    for(i=0; i<tam; i++)
    {

        if(personas[i].estado == 0 && agregarOtraPersona == 's')
        {

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(personas[i].nombre);

            printf("\nIngrese la edad de la persona: ");
            scanf("%d", &personas[i].edad);

            printf("\nIngrese el DNI de la persona: (solo numeros) ");
            scanf("%d", &personas[i].dni);

            printf("\nAgregado: ");
            mostrarPersona(personas[i]);

            personas[i].estado = 1;

            printf("\nDesea agregar otra persona mas en este momento?(s/n)\n");
            agregarOtraPersona = getche();
        }
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


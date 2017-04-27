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

int main()
{
    int borrarDni;
    int j;
    char buffer[200];
    ePersona personas[P];
    char seguir='s';
    int opcion=0;
    int i;


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
        for(i=0;i<P;i++)
        {
            if(personas[i].estado == 1)
            {
            mostrarPersona(personas[i]);
            }
        }

            break;
        case 4:

            for(i=0; i<P; i++)
            {
                if(personas[i].estado == 1)
                {

                    if(personas[i].edad < 18)
                    {
                        printf("p");
                    }

                    if(personas[i].edad > 19 && personas[i].edad < 35)
                    {
                        printf("\tp\t");
                    }

                    if(personas[i].edad > 35)
                    {
                        printf("\t\tp\t\t");
                    }

                    printf("\n");
                }

            }

            printf("<18\t19>35\t>35");

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
    int i;
    int borrarDni;
    char confirmar;

    printf("Ingrese el DNI de la persona que quiere eliminar: ");
            scanf("%d", &borrarDni);

    for(i=0; i<tam; i++)
            {
                if(personas[i].estado == 1 && personas[i].dni == borrarDni )
                {
                    mostrarPersona(personas[i]);
                    printf("\nSeguro desea eliminar a esta persona?(s/n)");
                    confirmar = getche();
                }

                if(personas[i].estado == 1 && confirmar == 's')
                {
                    personas[i].estado = -1;
                    printf("\nPersona eliminada.");
                    break;
                }
                else if(personas[i].estado == 1 && confirmar == 'n')
                {
                    printf("\nSe ha cancelado la operacion.");
                    break;
                }

                printf("\nEsa persona no existe!");
                break;
            }
}


#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "funciones.h"
#include  "ArrayList.h"




int menu(int limiteInf, int limiteSup)
{
    int opcion;

    system("cls");
    printf("OPERACIONES");
    opcion = recibeIntRango("\n1 - CARGAR LISTA DE TAREAS\n2 - PARTICIONAR POR PRIORIDAD\n3 - ORDENAR\n4 - RESOLVER TAREAS\n5 - GENERAR\n6 - SALIR\n\nOpcion: ","\nReingrese\n\nOpcion: ",limiteInf,limiteSup);

    return opcion;
}



Etarea *new_tarea()
{
    Etarea *tarea;
    tarea = (Etarea*)malloc(sizeof(Etarea));

    return tarea;
}


void copiar(ArrayList *plist, Etarea *tarea)
{
    FILE *ARCH;
    char descripcion[51];
    char prioridad[21];
    char tiempo[21];
    int seguir;

    ARCH = fopen("texto.csv","r");
    if(ARCH == NULL)
    {
        printf("\nError");
    }
    else
    {
        while(!(feof(ARCH)))
        {
            tarea = new_tarea();
            if(tarea!=NULL)
            {
                fscanf(ARCH,"%[^,],%[^,],%[^\n]\n", descripcion, prioridad, tiempo);
                strcpy(tarea->descripcion, descripcion);
                tarea->prioridad = atoi(prioridad);
                tarea->tiempo = atof(tiempo);
                al_add(plist, tarea);

            }
        }
        printf("\nEl archivo fue cargado con exito al arrayList. 0 para continuar ");

    }
    scanf("%d",&seguir);

}



void listar_tareas(ArrayList *pList)
{
    int i,seguir;

    for(i=0; i<pList->size; i++)
    {
        listar(pList->pElements[i]);
    }

    printf("\n\n0 para continuar ");
    scanf("%d",&seguir);
}



void listar(Etarea *tarea)
{
    printf("\nDescripcion: %s - Prioridad: %d - Tiempo: %.02f",tarea->descripcion, tarea->prioridad,tarea->tiempo);
}

/** \brief crea un array con los elementos que tiene prioridad 0
 * \param puntero al arrayList original
 * \return un puntero al nuevo array
 *
 */

ArrayList* particionar_prioridad_0(ArrayList *pList)
{
    ArrayList *arrayPrioridad0 = al_newArrayList();
    int i;
    Etarea *auxTarea;

    for(i=0; i<pList->size; i++)
    {
        auxTarea = al_get(pList,i);

        if(auxTarea->prioridad == 0)
        {
            al_add(arrayPrioridad0,auxTarea);
        }
    }
    printf("\nEl array con prioridad 0 esta compuesto por: \n");
    listar_tareas(arrayPrioridad0);
    return arrayPrioridad0;
}

/** \brief crea un array con los elementos que tiene prioridad 1
 * \param puntero al arrayList original
 * \return un puntero al nuevo array
 *
 */

ArrayList* particionar_prioridad_1(ArrayList *pList)
{
    ArrayList *arrayPrioridad1 = al_newArrayList();
    int i;
    Etarea *auxTarea;

    for(i=0; i<pList->size; i++)
    {
        auxTarea = al_get(pList,i);

        if(auxTarea->prioridad == 1)
        {
            al_add(arrayPrioridad1,auxTarea);
        }
    }

    printf("\nEl array con prioridad 1 esta compuesto por: \n");
    listar_tareas(arrayPrioridad1);
    return arrayPrioridad1;
}



int compare(Etarea* elemento1,Etarea* elemento2)
{
    if((elemento1->tiempo) > (elemento2->tiempo))
    {
        return 1;
    }
    if((elemento1->tiempo) < (elemento2->tiempo))
    {
        return -1;
    }
    return 0;
}

/** \brief ordena los dos arrays creados en el punto 2 de manera descendente
 * \param puntero al array con prioridad 0
 * \param puntero al array con prioridad 1
 * \return void
 *
 */

void ordenar(ArrayList *arrayPrioridad0, ArrayList *arrayPrioridad1)
{
    al_sort(arrayPrioridad0,compare,0);
    printf("\nEl array con prioridad 1 ordenado: \n");
    listar_tareas(arrayPrioridad0);

    al_sort(arrayPrioridad1,compare,0);
    printf("\nEl array con prioridad 2 ordenado: \n");
    listar_tareas(arrayPrioridad1);
}




void resolver_prioridad1(ArrayList *arrayPrioridad1)
{
    int i;
    Etarea *tarea = new_tarea();
    int largo1 = arrayPrioridad1->size;
    int seguir;

    al_sort(arrayPrioridad1,compare,1);
    listar_tareas(arrayPrioridad1);
    for(i=0; i<largo1; i++)
    {
        tarea = al_pop(arrayPrioridad1,0);
        printf("\nLa siguiente tarea fue eliminada - Descripcion: %s - Prioridad: %d - Tiempo: %.02f",tarea->descripcion,tarea->prioridad,tarea->tiempo);
        printf("\nPara resolver la siguiente tarea teclee 0\n");
        scanf("%d",&seguir);

    }
}


void resolver_prioridad0(ArrayList *arrayPrioridad0)
{
    int i;
    Etarea *tarea = new_tarea();
    int largo0 = arrayPrioridad0->size;
    int seguir;


    al_sort(arrayPrioridad0,compare,1);
    listar_tareas(arrayPrioridad0);
    for(i=0; i<largo0; i++)
    {
        tarea = al_pop(arrayPrioridad0,0);
        printf("\nLa siguiente tarea fue eliminada - Descripcion: %s - Prioridad: %d - Tiempo: %.02f",tarea->descripcion,tarea->prioridad,tarea->tiempo);
        printf("\nPara resolver la siguiente tarea teclee 0\n");
        scanf("%d",&seguir);

    }
}





void guardar(ArrayList *arrayPrioridad0, ArrayList *arrayPrioridad1)
{
    int i, retorno=-1;
    FILE *ARCHALTA;
    FILE *ARCHBAJA;

    ARCHALTA =fopen("pAlta.csv", "w+");
    Etarea *tarea = new_tarea();

    if(ARCHALTA == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {

        for(i=0; i<arrayPrioridad1->size; i++)
        {
            tarea = (Etarea*)al_get(arrayPrioridad1,i);
            fprintf(ARCHALTA,"%s,%d,%.02f\n",tarea->descripcion,tarea->prioridad,tarea->tiempo);
        }
    }
    fclose(ARCHALTA);

    ARCHBAJA =fopen("pBaja.csv", "w+");

    if(ARCHBAJA == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        for(i=0; i<arrayPrioridad0->size; i++)
        {
            tarea = (Etarea*)al_get(arrayPrioridad0,i);
            fprintf(ARCHBAJA,"%s,%d,%.02f\n",tarea->descripcion,tarea->prioridad,tarea->tiempo);
        }

        fclose(ARCHBAJA);
        free(tarea);

    }
}


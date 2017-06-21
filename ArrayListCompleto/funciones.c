#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"


generarPaginaWeb(ArrayList* lista)
{
    FILE* bin;
    bin = fopen("bin.dat", "wb");
}


modificarPelicula(ArrayList* lista)
{
    char buffer[200];
    int i;
    int aux=1;
    eMovie* auxM;
    auxM = (eMovie*) malloc(sizeof(eMovie));


    printf("Ingrese el titulo de la pelicula que desee modificar: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>19)
    {
        printf("El titulo de la pelicula debe contener como maximo 20 caractéres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strupr(buffer);

    for(i=0;i<al_len(lista);i++)
    {
        auxM = al_get(lista,i);

        if(strcmp(buffer,auxM->titulo)==0)
        {
            auxM = agregarPelicula();
            al_set(lista,i,auxM);
            printf("Pelicula modificada correctamente!\n");
            aux = 0;
            break;
        }
    }

    if(aux == 1)
    {
        printf("La pelicula no fue encontrada! \n");
    }


}



eliminarPelicula(ArrayList* lista)
{
    char buffer[200];
    int i;
    int aux=1;
    eMovie* auxM;
    auxM = (eMovie*) malloc(sizeof(eMovie));


    printf("Ingrese el titulo de la pelicula que desee eliminar: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>19)
    {
        printf("El titulo de la pelicula debe contener como maximo 20 caractéres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strupr(buffer);

    for(i=0;i<al_len(lista);i++)
    {
        auxM = al_get(lista,i);

        if(strcmp(buffer,auxM->titulo)==0)
        {
            al_remove(lista,i);
            printf("Pelicula eliminada correctamente!\n");
            aux = 0;
            break;
        }
    }

    if(aux == 1)
    {
        printf("La pelicula no fue encontrada! \n");
    }

}

eMovie* agregarPelicula(void)
{
    int returnAux = 0;
    eMovie* auxMovie;
    auxMovie = (eMovie*) malloc (sizeof(eMovie));
    char buffer[200];
    int aux;


        printf("Ingrese el titulo de la pelicula\n");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>19)
        {
            printf("El titulo debe contener como maximo 20 caractéres\n");
            fflush(stdin);
            gets(buffer);
        }

        strupr(buffer);

        strcpy(auxMovie->titulo,buffer);


        printf("Ingrese el genero de la pelicula\n");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>19)
        {
            printf("El genero debe contener como maximo 20 caractéres\n");
            fflush(stdin);
            gets(buffer);
        }

        strcpy(auxMovie->genero,buffer);


        printf("Ingrese la descripcion de la pelicula\n");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>49)
        {
            printf("La descripcion debe contener como maximo 50 caractéres\n");
            fflush(stdin);
            gets(buffer);
        }

        strcpy(auxMovie->descripcion,buffer);



        printf("Ingrese el link de la pelicula\n");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>49)
        {
            printf("El link debe contener como maximo 50 caractéres\n");
            fflush(stdin);
            gets(buffer);
        }

        strcpy(auxMovie->linkImagen,buffer);

        printf("Ingrese la duracion de la pelicula en minutos: \n");
        scanf("%d", &(auxMovie->duracion));

        printf("Ingrese el puntaje de la pelicula\n");
        scanf("%d",&aux);

        while(aux<0 || aux>10)
        {
            printf("El puntaje debe estar entre 0 y 10\n");
            scanf("%d",&aux);
        }


    auxMovie->puntaje = aux;






    return auxMovie;
}

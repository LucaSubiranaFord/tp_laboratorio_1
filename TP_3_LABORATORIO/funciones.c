#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

agregarPelicula(ArrayList* lista)
{
    eMovie* auxMovie;
    auxMovie = newMovie();
    char buffer[200];
    int auxPuntaje;

    printf("Titulo de la pelicula: \n");
    fflush(stdin);
    gets( buffer );

    while((strlen(buffer) > 19 ))
    {
        printf("La pelicula debe contener menos de 20 caracteres, ingrese un titulo diferente: \n");
        fflush(stdin);
        gets(buffer);
    }

    strupr(buffer);
    strcpy(auxMovie->titulo,buffer);

    printf("Ingrese el genero de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 19 ))
    {
        printf("El genero debe contener menos de 20 caracteres, ingrese uno diferente: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy( auxMovie->genero, buffer );



    printf("Ingrese la descripcion de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 49 ))
    {
        printf("La descripcion debe contener menos de 50 caracteres, ingrese una diferente: \n");
        gets(buffer);
    }

    strcpy( auxMovie->descripcion, buffer );


    printf("Ingrese la duracion de la pelicula en minutos: \n");
    scanf("%d",& ( auxMovie->duracion )  );

    printf("Ingrese el puntaje de la pelicula(0 minimo, 10 puntaje maximo): \n");
    scanf("%d", &auxPuntaje);

    while(auxPuntaje<0 || auxPuntaje>10)
    {
        printf("El puntaje debe ser entre 0 y 10!:  \n");
        scanf("%d", &auxPuntaje);
    }

    auxMovie->puntaje = auxPuntaje;



    printf("Ingrese el link con la imagen de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 49 ))
    {
        printf("El link debe contener menos de 50 caracteres, ingrese uno diferente: \n");
        fflush(stdin);
        gets(buffer);
    }


    strcpy( auxMovie->linkImagen, buffer );

    al_add(lista,auxMovie);

    printf("Pelicula añadida correctamente! \n");

}

eMovie* newMovie()
{
    eMovie* aux;
    aux = (eMovie*) malloc (sizeof(eMovie));
    return aux;
}

borrarPelicula(ArrayList* lista)
{
    int i,j;
    eMovie* aux;
    char auxNombre[20];
    int existePelicula = 0;
    int auxI;

    aux = newMovie();

    while(existePelicula == 0)
    {
        printf("Ingrese el titulo que desee eliminar: \n");
        fflush(stdin);
        gets(auxNombre);
        strupr(auxNombre);
        for(i=0; i<al_len(lista); i++)
        {
            aux = al_get(lista,i);
            if(strcmp(aux->titulo,auxNombre) == 0)
            {
                auxI = i;
                existePelicula = 1;
                break;
            }
        }

        if(existePelicula == 0)
        {
            printf("Esa pelicula no existe!\n");
        }
    }

    al_remove(lista, auxI);

}


modificarPelicula(ArrayList* lista)
{
    int existePelicula = 0;
    int auxI;
    int i;
    eMovie* auxMovie;
    auxMovie = newMovie();
    eMovie* aux;
    char buffer[200];
    int auxPuntaje;


    while(existePelicula == 0)
    {
        printf("Ingrese el titulo que desea modificar: \n");
        fflush(stdin);
        gets(buffer);
        strupr(buffer);
        for(i=0; i<al_len(lista); i++)
        {
            aux = newMovie();
            aux = al_get(lista,i);
            if(strcmp(aux->titulo,buffer) == 0)
            {
                auxI = i;
                existePelicula = 1;
                break;
            }
        }

        if(existePelicula == 0)
        {
            printf("Esa pelicula no existe!\n");
        }
    }


    printf("Titulo nuevo de la pelicula: \n");
    fflush(stdin);
    gets( buffer );
    strupr(buffer);

    while((strlen(buffer) > 19 ))
    {
        printf("La pelicula debe contener menos de 20 caracteres, ingrese un titulo diferente: \n");
        fflush(stdin);
        gets(buffer);
    }

    strupr(buffer);
    strcpy(auxMovie->titulo,buffer);

    printf("Ingrese el nuevo genero de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 19 ))
    {
        printf("El genero debe contener menos de 20 caracteres, ingrese uno diferente: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy( auxMovie->genero, buffer );



    printf("Ingrese la nueva descripcion de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 49 ))
    {
        printf("La descripcion debe contener menos de 50 caracteres, ingrese una diferente: \n");
        gets(buffer);
    }

    strcpy( auxMovie->descripcion, buffer );


    printf("Ingrese la nueva duracion de la pelicula en minutos: \n");
    scanf("%d",& ( auxMovie->duracion )  );

    printf("Ingrese el nuevo puntaje de la pelicula(0 minimo, 10 puntaje maximo): \n");
    scanf("%d", &auxPuntaje);

    while(auxPuntaje<0 || auxPuntaje>10)
    {
        printf("El puntaje debe ser entre 0 y 10!:  \n");
        scanf("%d", &auxPuntaje);
    }

    auxMovie->puntaje = auxPuntaje;



    printf("Ingrese el nuevo link con la imagen de la pelicula: \n");
    fflush(stdin);
    gets(buffer);

    while((strlen(buffer) > 49 ))
    {
        printf("El link debe contener menos de 50 caracteres, ingrese uno diferente: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy( auxMovie->linkImagen, buffer );

    al_set(lista,auxI, auxMovie);

}


generarPagina(ArrayList* lista)
{
    int i;
    eMovie* aux;
    FILE* archivo;

    archivo = fopen("Peliculas.html","wb+");

    if(archivo!=NULL)
    {
         for(i=0; i<al_len(lista); i++)
    {
        aux = newMovie();
        aux = al_get(lista,i);
        fprintf(archivo,"<article class='col-md-4 article-intro'>\
                <a href='#'>\
                <img class='img-responsive img-rounded' src='%s'\
                alt=''>\
                </a>\
                <h3>\
                <a href='#'>%s</a>\
                </h3>\
                <ul>\
                <li>Género:%s</li>\
                <li>Puntaje:%d</li>\
                <li>Duración:%d</li>\
                </ul>\
                <p>%s</p>\
                </article>",aux->linkImagen, aux->titulo, aux->genero, aux->puntaje, aux->duracion, aux->descripcion);
    }

    printf("Pagina generada correctamente! \n");
    fclose(archivo);
    }else
    {
        printf("Error al abrir el archivo \n");
    }


}


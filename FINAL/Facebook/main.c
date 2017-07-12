#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "ArrayList.h"
#include <string.h>
int main()
{
     char seguir='s';
     int opcion=0;
        ArrayList* listaPost;
        ArrayList* listaUsuarios;
        ArrayList* listaTotal;
        listaTotal = al_newArrayList();
        listaPost = al_newArrayList();
        listaUsuarios = al_newArrayList();
        FILE* archivoP;
        FILE* archivoU;
        FILE* archivo;

     int i,j;
    while(seguir=='s')
    {
        printf("1- PARSE LISTAS\n");
        printf("2- DIVIDIR LISTAS\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                parseListas(listaPost, listaUsuarios, archivoP, archivoU);
                //parseListass(listaPost, listaUsuarios, archivoP, archivoU);
                break;
            case 2:
                crearArchivo(listaUsuarios,archivo);
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

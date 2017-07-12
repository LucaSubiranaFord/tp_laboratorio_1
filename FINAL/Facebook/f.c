#include <stdio.h>
#include <stdlib.h>
#include "f.h"
#include "ArrayList.h"
#include <string.h>



crearArchivo(ArrayList* listaUsuarios, FILE* archivo)
{
    eUsuario* aux;
    int i;

    archivo = fopen("usuariosNuevo.csv", "w");
    for(i=0;i<al_len(listaUsuarios);i++)
    {
        aux = (eUsuario*) malloc (sizeof(eUsuario));
        aux = al_get(listaUsuarios, i);
        fprintf(archivo, "%d,%s,%d\n",aux->id_usuario, aux->nick, aux->popularidad);
    }

    fclose(archivo);
}

parseListas(ArrayList* listaPost, ArrayList* listaUsuarios, FILE* archivoP, FILE* archivoU)
{

    eUsuario* auxUsuario;

    archivoU = fopen("usuarios.csv", "r");
    int i;
    char id[200], nick[200], popu[200];

    fscanf(archivoU, "%[^,],%[^,],%[^\n]\n",id, nick, popu);

    while(!feof(archivoU))
    {
        fscanf(archivoU, "%[^,],%[^,],%[^\n]\n",id, nick, popu);
        auxUsuario = (eUsuario*) malloc (sizeof(eUsuario));

        auxUsuario->id_usuario = atoi(id);
        strcpy(auxUsuario->nick,nick);
        auxUsuario->popularidad = atoi(popu);

        al_add(listaUsuarios, auxUsuario);

    }
    fclose(archivoU);
}

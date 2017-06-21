#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "fun.h"

int main()
{
    int seguir = 0;
    int opcion;
    ArrayList* lista;
    ArrayList* listaAtendidos;
    listaAtendidos = al_newArrayList();
    lista = al_newArrayList();

    while(seguir == 0)
    {
        printf("1.- TRAMITE URGENTE\n");
        printf("2.- TRAMITE REGULAR\n");
        printf("3.- PROXIMO CLIENTE\n");
        printf("4.- LISTAR\n");
        printf("5.- INFORMAR\n");
        printf("6.- SALIR\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            tramiteUrgente(lista);
            break;
        case 2:
             system("cls");
            tramiteRegular(lista);
            break;
        case 3:
            system("cls");
            proximoCliente(lista, listaAtendidos);
            break;
        case 4:
            system("cls");
            listar(lista);
            break;
        case 5:
            ordenarPorNombre(lista);
            break;
        default:
            break;
        }
    }


    return 0;
}

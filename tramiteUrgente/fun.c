#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "fun.h"


int ordenarPorNombre(ArrayList* lista)
{
    ePersona* aux;
    aux = newPersona();
    ePersona* aux2;
    aux2 = newPersona();
    ePersona* aux3;
    aux3 = newPersona();
    int returnAux;
    int i,j;

    for(i=0;i<al_len(lista)-1;i++)
    {
        aux = al_get(lista,i);
        aux2 = al_get(lista,(i+1));

        if (strcmp(aux->apeNombre, aux2->apeNombre)>0)
        {
            aux3 = aux;
            al_set(lista,i,aux2);
            al_set(lista,(i+1),aux3);
            returnAux = 1;
        }
    }
    return returnAux;
}



listarAtendidos(ArrayList* listaAtendidos)
{
    ePersona* aux;
    aux = newPersona();
}

mostrarPersona(int index, ArrayList* lista)
{
    ePersona* aux;
    aux = newPersona();

    aux = al_get(lista,index);

    if(aux->tramite == 1)
    {
       printf("El proximo cliente es: %s -- %d -- TRAMITE URGENTE", aux->apeNombre, aux->dni);
    }else
    {
        printf("El proximo cliente es: %s -- %d -- TRAMITE REGULAR", aux->apeNombre, aux->dni);
    }

}

proximoCliente(ArrayList* lista, ArrayList* listaA)
{
    ePersona* aux;
    aux = newPersona();
    int menorIndice;
    int menor = 5000;
    int i;

    for(i=0;i<al_len(lista);i++)
    {
        aux = al_get(lista,i);
        if(menor > aux->turno)
        {
            menorIndice = i;
            menor = aux->turno;
        }
    }

    al_add(listaA, aux);
    mostrarPersona(menorIndice, lista);

    al_remove(lista,menorIndice);

}


tramiteUrgente(ArrayList* lista)
{
    ePersona* aux;
    aux = newPersona();
    char buffer[200];

    do{

       printf("Ingrese el nombre de la persona: \n");
        fflush(stdin);
        gets(buffer);
    }while(strlen(buffer)>49);

    strcpy(aux->nombre,buffer);

    do{
        printf("Ingrese el apellido: \n");
        fflush(stdin);
        gets(buffer);
    }while(strlen(buffer)>49);

    strcpy(aux->apellido,buffer);

    printf("Ingrese el dni: \n");
    scanf("%d", &aux->dni);

     printf("Ingrese el turno: \n");
    scanf("%d", &aux->turno);

    aux->tramite = 1;

   strcat(aux->apeNombre, aux->nombre);
   strcat(aux->apeNombre, " ");
   strcat(aux->apeNombre, aux->apellido);


   al_add(lista,aux);
}

listar(ArrayList* lista)
{
    ePersona* aux;
    aux = newPersona();
    int i;

    for(i=0;i<al_len(lista);i++)
    {
        aux = al_get(lista,i);
        if(aux->tramite == 1)
        {
            printf("%s -- %d -- TRAMITE URGENTE\n",aux->apeNombre, aux->dni);
        }else{

        printf("%s -- %d -- TRAMITE REGULAR\n",aux->apeNombre, aux->dni);
        }

    }
}

ePersona* newPersona()
{
        ePersona* aux;
        aux = (ePersona*) malloc (sizeof(ePersona));
        return aux;
}

tramiteRegular(ArrayList* lista)
{
    ePersona* aux;
    aux = newPersona();
    char buffer[200];

    do{

       printf("Ingrese el nombre de la persona: \n");
        fflush(stdin);
        gets(buffer);
    }while(strlen(buffer)>49);

    strcpy(aux->nombre,buffer);

    do{
        printf("Ingrese el apellido: \n");
        fflush(stdin);
        gets(buffer);
    }while(strlen(buffer)>49);

    strcpy(aux->apellido,buffer);

    printf("Ingrese el dni: \n");
    scanf("%d", &aux->dni);

    printf("Ingrese el turno: \n");
    scanf("%d", &aux->turno);

    aux->tramite = 0;

   strcat(aux->apeNombre, aux->nombre);
   strcat(aux->apeNombre, " ");
   strcat(aux->apeNombre, aux->apellido);


   al_add(lista,aux);


}

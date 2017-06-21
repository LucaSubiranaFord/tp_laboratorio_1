#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "ArrayList.h"

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;



eMovie* agregarPelicula(void);
eliminarPelicula(ArrayList*);
modificarPelicula(ArrayList*);
generarPaginaWeb(ArrayList*);


#endif // FUNCIONES_H_INCLUDED

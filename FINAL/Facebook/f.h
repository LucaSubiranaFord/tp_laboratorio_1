#include "ArrayList.h"

typedef struct
{
    int id_mensaje;
    char mensaje[200];
    int popularidad;
    int id_usuario;
}ePost;

typedef struct
{
    int id_usuario;
    char nick[200];
    int popularidad;
}eUsuario;


parseListas(ArrayList* listaPost, ArrayList* listaUsuarios, FILE*, FILE*);
crearArchivo(ArrayList* listaUsuarios, FILE* archivo);

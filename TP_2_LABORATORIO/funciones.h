#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);


/** \brief Agrega una persona a un array de tipo ePersona
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
agregarPersona(ePersona lista[], int tam);


/** \brief inicializa todos los estados en 0
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
inicializarEstados(ePersona lista[], int tam);


/**\brief muestra a la persona a elegir
 * \param array de tipo ePersona
 */
mostrarPersona(ePersona lista[], int persona);


/** \brief BAJA a una persona
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
borrarPersona(ePersona lista[], int tam);


/** \brief Ordena los nombres en orden alfabetico
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
ordenarLista(ePersona lista[], int tam);


/** \brief muestra a todas las personas dadas de alta
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
mostrarLista(ePersona lista[], int tam);


/** \brief Imprime un grafico de edades
 * \param contador de personas de edad menor a 18 años
 * \param contador de personas de edad entre 19 y 35 años
 * \param contador de personas de edad mayores a 35 años
 */
imprimirGraficoEdades(int, int ,int);

#endif // FUNCIONES_H_INCLUDED

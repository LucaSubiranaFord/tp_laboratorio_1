#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

} ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);


/**\brief muestra a la persona a elegir
 * \param array de tipo ePersona
 */
void mostrarPersona(ePersona);


/** \brief muestra a todas las personas dadas de alta
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
void mostrarTodos(ePersona[], int);


/** \brief inicializa todos los estados en 0
 * \param un array de la clase ePersona
 * \param tamaño del array
 */

void restaurarEstado(ePersona[], int);


/** \brief Ordena los nombres en orden alfabetico
 * \param un array de la clase ePersona
 * \param tamaño del array
 */

void ordenarNombres(ePersona[], int);


/** \brief Agrega una persona a un array de tipo ePersona
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
void agregarPersona(ePersona[], int);

/** \brief BAJA a una persona
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
void confirmarEliminarPersona(ePersona[], int);


/** \brief Imprime un grafico de edades especificadas dentro de la funcion
 * \param un array de la clase ePersona
 * \param tamaño del array
 */
void imprimirGraficoEdades(ePersona[], int);

#endif // FUNCIONES_H_INCLUDED

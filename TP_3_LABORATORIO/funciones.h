#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;


/** \brief Agrega una pelicula al tipo de dato ArrayList
 * \param El tipo de dato ArrayList
 */
agregarPelicula(ArrayList*,FILE*);



/** \brief Elimina una pelicula del ArrayList
 * \param El tipo de dato ArrayList
 */
borrarPelicula(ArrayList*, FILE*);



/** \brief Constructor por defecto de la estructura eMovie
 * \return un puntero a un tipo de dato eMovie
 */

eMovie* newMovie();



/** \brief Modifica una pelicula dentro del ArrayList
 * \param El tipo de dato ArrayList
 */
modificarPelicula(ArrayList*,FILE*);



/** \brief genera una pagina web donde se mostraran los datos de cada elemento del ArrayList
 * \param El tipo de dato ArrayList
 */
generarPagina(ArrayList*);




/** \brief Genera un archivo .dat con los datos del ArrayList
 *
 * \param El tipo de dato ArrayList
 * \param el FILE bin
 */
generarBin(ArrayList*, FILE*);

#endif // _EMPLOYEE_H




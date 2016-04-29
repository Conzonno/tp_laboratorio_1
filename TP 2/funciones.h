#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Carga los datos de la estructura
 *
 * \param Array de la estructura
 * \param Entero que maneja el largo del array
 * \return Retorno vacio
 *
 */
void personasAlta(EPersona lista[] , int );

/** \brief Realiza una baja logica
 *
 * \param Array de la estructura
 * \param Entero que maneja el largo del array
 * \return Retorno vacio
 *
 */

void personasBorrar(EPersona lista[] ,int);

/** \brief Muestra alfabeticamente los datos
 *
 * \param Array de la estructura
 * \param Entero que maneja el largo del array
 * \return Retorno vacio
 *
 */

void mostrarNombre(EPersona lista[], int);

/** \brief Inicializa el array en 1
 *
 * \param Array de la estructura
 * \param Entero que maneja el largo del array
 * \return Retorno vacio
 *
 */

void inicializarArray(EPersona lista[], int);

/** \brief Muestra el grafico de barras
 *
 * \param Array de la estructura
 * \param Entero que maneja el largo del array
 * \return Retorno vacio
 *
 */

void mostrarGrafico(EPersona lista[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int lenght);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED

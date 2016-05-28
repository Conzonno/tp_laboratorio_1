#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define L 3


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie movie[L];
    FILE* aMovie;


    inicializar(movie, L);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        printf("Escoja una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie, aMovie);
                break;
            case 2:
                borrarPelicula(movie, aMovie);
                break;
            case 3:
                generarPagina(movie, aMovie);
               break;
            case 4:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta");
                break;
        }
    }

    return 0;
}

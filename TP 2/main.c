#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LARGE 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona personas[LARGE];

    inicializarArray( personas,  LARGE);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                personasAlta(personas, LARGE);
                break;
            case 2:
                personasBorrar(personas, LARGE);
                break;
            case 3:
                mostrarNombre(personas, LARGE);
                break;
            case 4:
                mostrarGrafico(personas, LARGE);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

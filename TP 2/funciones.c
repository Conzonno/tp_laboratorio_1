#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int aContador[3];

void inicializarArray(EPersona lista[], int lenght)
{
    int i;
    for(i=0; i<lenght; i++)
    {
        lista[i].estado=1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int lenght)
{
     int i;
     int retorno=-1;
    for(i=0; i<lenght; i++)
    {
        if(lista[i].estado==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[],int lenght)
{
    int i;
    int retorno=-1;
    int auxdni;

    printf("Ingrese el DNI ha buscar: ");
    fflush(stdin);
    scanf("%d", &auxdni);

    for(i=0; i<lenght; i++)
    {
        if(lista[i].estado==0 && lista[i].dni==auxdni)
        {

            retorno=i;
            printf("El DNI ha sido encontrado...\n");
            break;
        }
    }
    return retorno;
}

void personasAlta (EPersona lista[],int lenght)
{
    int i;
    int j;

    for(i=0;i<lenght;i++)
    {
        system("cls");
        j=obtenerEspacioLibre( lista,  lenght);
        if(j==-1)
        {
            printf("No hay mas lugar para cargar datos\n");
            system("pause");
            break;
        }
        else if(j!=-1)
        {
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(lista[j].nombre);
            printf("Ingrese Edad: ");
            fflush(stdin);
            scanf("%d", &lista[j].edad);
                while(lista[i].edad<1 || lista[j].edad>100)
                {
                    printf("Error re ingrese: ");
                    scanf("%d", &lista[j].edad);
                }
            printf("Ingrese DNI: ");
            fflush(stdin);
            scanf("%d", &lista[j].dni);
                while(lista[i].dni<5000000 || lista[j].dni>99000000)
                {
                    printf("Error re ingrese: ");
                    scanf("%d", &lista[j].dni);
                }
            lista[i].estado=0;
        }

    }
}

void personasBorrar(EPersona lista[],int lenght)
{
    int i;
    i=buscarPorDni(lista, lenght);

    if(i==-1)
    {
        printf("El DNI no ha sido encontrado\n");
        system("pause");

    }
    else if(i!=-1)
    {
        lista[i].estado=1;
        printf("El DNI ha sido borrado\n");
        system("pause");
    }
}

void mostrarNombre(EPersona lista[],int lenght)
{
    int i,j;
    EPersona auxB;

    for(i=0;i<lenght-1;i++)
    {
        for(j=i+1;j<lenght;j++)
        {
            if(lista[i].estado==0)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxB=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxB;
                }
            }
        }
    }
    printf("Nombre\tEdad\tDNI\n");
    for(i=0;i<lenght;i++)
    {
        if(lista[i].estado==0)
        {
            printf("%s\t%d\t%d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
    system("pause");
}

void mostrarGrafico(EPersona lista[],int lenght)
{
    int i=0;
    int j;
    int max;
    int x;
    int contador18=0;
    int contador1935=0;
    int contador35=0;


    for(x=0;x<lenght;x++)
    {
        if(lista[x].edad<=18)
        {
            contador18++;
        }
        else if(lista[x].edad>=19 && lista[x].edad<=35)
        {
            contador1935++;
        }
        else
        {
            contador35++;
        }
    }
    aContador[0]=contador18;
    aContador[1]=contador1935;
    aContador[2]=contador35;

   max = 0;
   for (i = 0; i < lenght; i++)
   {
       if (aContador[i]>max)
      {
          max = aContador[i];
      }
   }
   for (i = max; i > 0; i--)
    {

      for (j = 0; j < lenght; j++)
      {
           if (aContador[j] >= i)
             {
                  printf(" *");
             }
             else
             {
                 printf("  ");
             }
             printf("\t");
      }
        printf("\n");
    }
    printf("<18\t19-35\t35>\n");
    system("pause");
}

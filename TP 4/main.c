#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "ArrayList.h"
#include "area.h"
#include "files.h"

int main()
{
    ArrayList* pList;
    ArrayList* pListArea;

    int opcion;
    int auxI;
    char seguir='s';
    char seguir2='s';

    pList=al_newArrayList();
    pListArea=al_newArrayList();
    do
    {
        system("cls");
        opcion=showMainMenu();
        seguir2='s';
        switch(opcion)
        {
            case 1:
                do
                {
                    system("cls");
                    opcion=showMenuEmploye();
                    switch(opcion)
                    {
                        case 1:
                            auxI=addEmploye(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 2:
                            auxI=removeEmploye(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 3:
                            auxI=modifyEmploye(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 4:
                            printArrayListEmployee(pList, pListArea);
                            break;
                        case 5:
                            auxI=deleteEmployes(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 6:
                            auxI=arrayLenght(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 7:
                            auxI=backUpEmploye(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 8:
                            auxI=uploadEmployeFiles(pList);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 9:
                            auxI=sortEmploye(pList, pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 10:
                            seguir2='n';
                            break;
                        default:
                            printf("Opcion incorrecta");
                            break;
                    }
                }while(seguir2=='s');
                break;
            case 2:
                do
                {
                    system("cls");
                    opcion=showMenuArea();
                    switch(opcion)
                    {
                        case 1:
                            auxI=addArea(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 2:
                            auxI=removeArea(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 3:
                            auxI=modifyArea(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                           break;
                        case 4:
                            auxI=deleteAreas(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 5:
                            auxI=arrayAreaLenght(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 6:
                            auxI=backUpArea(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 7:
                            auxI=uploadAreaFiles(pListArea);
                            if(auxI==-1)
                            {
                                printf("Hubo un error en el programa");
                            }
                            break;
                        case 8:
                            seguir2='n';
                            break;
                        default:
                            printf("Opcion incorrecta");
                            break;
                    }
                }while(seguir2=='s');
                break;
            case 3:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta");
                break;
        }
    }while(seguir=='s');

    return 0;
}

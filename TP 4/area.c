#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "ArrayList.h"
#include "area.h"

eArea* newAreaArray(void)
{
    eArea* auxReturn = NULL;
    eArea* area;

    area=(eArea *)malloc(sizeof(eArea));
    if(area!=NULL)
    {
        auxReturn=area;
    }

    return auxReturn;
}

int addArea(ArrayList* pListArea)
{
    int auxReturn=-1;
    int auxI;
    eArea* area;

    area=newAreaArray();

    if(pListArea!=NULL && area!=NULL)
    {
        printf("Ingrese nombre del area: ");
        fflush(stdin);
        gets(area->areaName);
        printf("Ingrese codigo del area: ");
        fflush(stdin);
        scanf("%d", &area->areaCode);
        while((area->areaCode)<0 || (area->areaCode)>pListArea->size)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &area->areaCode);
        }

        area->areaState=1;
        auxI=al_add(pListArea, area);
        auxReturn=0;
        if(auxI==-1)
        {
            printf("Hubo un error en el prgrama");
            auxReturn=-1;
        }
    }
    return auxReturn;
}

int removeArea(ArrayList* pListArea)
{
    int auxReturn = -1;
    int auxI;

    if(pListArea!=NULL)
    {
        eArea* area;
        eArea* areaAux;
        int index;

        index=seekIndex(pListArea);
        area = (eArea*)pListArea->get(pListArea,index);

        if(index>=0 && index<=pListArea->size)
        {
            areaAux=(eArea*)al_pop(pListArea, index);

            free(area+index);
            auxI=al_remove(pListArea, index);
            auxReturn=0;
            if(auxI==-1)
            {
                printf("Hubo un error en el prgrama");
                auxReturn=-1;
            }
            else
            {
                printf("Datos del area eliminada.\nNombre\tCodigo\n%s \t%d",areaAux->areaName,areaAux->areaCode);
            }
        }
    }
    return auxReturn;
}

int modifyArea(ArrayList* pListArea)
{
    int auxReturn=-1;
    int index;
    eArea* area;

    index=seekAreaIndex(pListArea);
    area = (eArea*)pListArea->get(pListArea,index);

    if(area!=NULL && pListArea!=NULL && index>=0 && index<pListArea->size)
    {
        //preguntar si desea cambiar tal campo
        printf("Ingrese nombre del area: ");
        fflush(stdin);
        gets(area[index].areaName);
        printf("Ingrese codigo del area: ");
        fflush(stdin);
        scanf("%d", &area[index].areaCode);
        while((area->areaCode)<0 || (area->areaCode)>pListArea->size)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &area->areaCode);
        }

        auxReturn=0;
    }
    return auxReturn;
}

int containsEmploye(ArrayList* pListArea, ArrayList* pList)
{
    int auxReturn=-1;
    int i,auxI;

    if(pListArea!=NULL && pList!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            eEmploye* employe;
            employe = (eEmploye*)pList->get(pList,i);
            if(employe!=NULL)
            {
                auxI=al_contains(pListArea, employe);
                if(auxI==-1)
                {
                    printf("Hubo un error en el prgrama");
                    auxReturn=-1;
                    break;
                }
            }
            auxReturn=0;
        }


    }
    return auxReturn;
}

int seekAreaIndex(ArrayList* pListArea)
{
    int i;
    int auxCode;
    int auxReturn=-1;
    eArea* area;

    if(pListArea!=NULL)
    {
       printf("Ingrese el legajo del empleado deseado: ");
        scanf("%d", &auxCode);

        for(i=0;i<pListArea->size;i++)
        {
            area = (eArea*)pListArea->get(pListArea,i);
            if((area->areaCode)==auxCode)
            {
                break;
            }
        }
        auxReturn=i;
    }
    return auxReturn;
}

ArrayList* backUpArea(ArrayList* pListArea)
{
    ArrayList* auxReturn=NULL;
    ArrayList* newArray;
    int auxI;

    if(pListArea!=NULL)
    {
        newArray=al_clone(pListArea);
        if(newArray!=NULL)
        {
            auxI=al_containsAll(pListArea, newArray);
            auxReturn=newArray;
            if(auxI==-1)
            {
                printf("Hubo un error en el prgrama");
                auxReturn=NULL;
            }
        }
    }
    return auxReturn;
}

void printArea(eArea* p)
{
    printf("%s\t%d\n",p->areaName,p->areaCode);
}

void printArrayListArea(ArrayList* pListArea)
{
    int i;
    eArea* aux;
    if(pListArea!=NULL)
    {
        printf("Nombre\tCodigo\n");
        for(i=0;i < pListArea->size; i++)
        {
            aux = (eArea*)pListArea->get(pListArea,i);
            printArea(aux);
        }
    }
}

int deleteAreas(ArrayList* pListArea)
{
    int auxReturn=-1;
    int i,auxI,auxI2;

    if(pListArea!=NULL)
    {
        eArea* area;
        for(i=0;i<pListArea->size;i++)
        {
            area = (eArea*)pListArea->get(pListArea,i);
            free(area+i);
        }
        auxI=al_deleteArrayList(pListArea);
        auxI2=al_clear(pListArea);
        auxReturn=0;
        if(auxI==-1 || auxI2==-1)
        {
            printf("Hubo un error en el prgrama");
            auxReturn=-1;
        }
    }
    return auxReturn;
}

int arrayAreaLenght(ArrayList* pListArea)
{
    int auxReturn=-1;
    int auxI;

    if(pListArea!=NULL)
    {
        auxI=al_len(pListArea);
        if(auxI!=-1)
        {
            printf("Existen %d empleado/s", auxI);
            auxReturn=0;
        }
    }
    return auxReturn;
}

int showMenuArea(void)
{
    int opcion;

    printf("1_Agregar area\n");
    printf("2_Borrar area\n");
    printf("3_Modificar area\n");
    printf("4_Salir\n");

    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "ArrayList.h"
#include "area.h"

//int* pFunc=&compareEmployee(void*,void*);

eEmploye* newEmployeArray(void)
{
    eEmploye* auxReturn = NULL;
    eEmploye* employee;

    employee=(eEmploye *)malloc(sizeof(eEmploye));
    if(employee!=NULL)
    {
        auxReturn=employee;
    }

    return auxReturn;
}

int addEmploye(ArrayList* plist)
{
    int auxReturn=-1;
    int auxI;
    eEmploye* employee;

    employee=newEmployeArray();

    if(plist!=NULL && employee!=NULL)
    {
        printf("Ingrese nombre del empleado: ");
        fflush(stdin);
        gets(employee->name);
        printf("Ingrese apellido del empleado: ");
        fflush(stdin);
        gets(employee->surname);
        printf("Ingrese salario del empleado: ");
        fflush(stdin);
        scanf("%f", &employee->salary);
        while((employee->salary)<0 || (employee->salary)>50000)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%f", &employee->salary);
        }
        printf("Ingrese edad del empleado: ");
        fflush(stdin);
        scanf("%d", &employee->age);
        while((employee->age)<0 || (employee->age)>65)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee->age);
        }
        printf("Ingrese legajo del empleado: ");
        fflush(stdin);
        scanf("%d", &employee->legacy);
        while((employee->legacy)<0 || (employee->legacy)>20000)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee->legacy);
        }
        printf("Ingrese area del empleado: ");
        fflush(stdin);
        scanf("%d", &employee->area);
        while((employee->area)<0 || (employee->area)>100)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee->area);
        }

        auxI=al_add(plist, employee);
        auxReturn=0;
        if(auxI==-1)
        {
            printf("Hubo un error en el prgrama");
            auxReturn=-1;
        }
    }
    return auxReturn;
}

int removeEmploye(ArrayList* pList)
{
    int auxReturn = -1;
    int auxI;
    if(pList!=NULL)
    {
        eEmploye* employee;
        eEmploye* employeeAux;

        int index;
        index=seekIndex(pList);
        employee = (eEmploye*)pList->get(pList,index);

        if(employee!=NULL && index>=0 && index<=pList->size)
        {
            employeeAux=(eEmploye*)al_pop(pList, index);


            free(employee+index);
            auxI=al_remove(pList, index);

            auxReturn=0;
            if(auxI==-1)
            {
                printf("Hubo un error en el prgrama");
                auxReturn=-1;
            }
            else
            {
                printf("Datos del empleado eliminado.\nNombre\tApellido\n%s \t%s",employeeAux->name,employeeAux->surname);
            }
        }
    }
    return auxReturn;
}

int modifyEmploye(ArrayList* pList)
{
    int auxReturn=-1;
    int index;
    eEmploye* employee;
    index=seekIndex(pList);

    employee = (eEmploye*)pList->get(pList,index);

    if(employee!=NULL && pList!=NULL && index>=0 && index<pList->size)
    {
        printf("Ingrese nuevo nombre del empleado: ");
        fflush(stdin);
        gets(employee[index].name);
        printf("Ingrese nuevo apellido del empleado: ");
        fflush(stdin);
        gets(employee[index].surname);
        printf("Ingrese nuevo slario del empleado: ");
        fflush(stdin);
        scanf("%f", &employee[index].salary);
        while((employee[index].salary)<0 || (employee[index].salary)>50000)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%f", &employee[index].salary);
        }
        printf("Ingrese nueva edad del empleado: ");
        fflush(stdin);
        scanf("%d", &employee[index].age);
        while((employee[index].age)<0 || (employee[index].age)>65)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee[index].age);
        }
        printf("Ingrese nuevo legajo del empleado: ");
        fflush(stdin);
        scanf("%d", &employee[index].legacy);
        while((employee[index].legacy)<0 || (employee[index].legacy)>20000)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee[index].legacy);
        }
        printf("Ingrese nueva area del empleado: ");
        fflush(stdin);
        scanf("%d", &employee[index].area);
        while((employee[index].area)<0 || (employee[index].area)>100)
        {
            printf("Hubo un error en el dato ingresado");
            fflush(stdin);
            scanf("%d", &employee[index].area);
        }


        auxReturn=0;
    }

    return auxReturn;
}

int sortEmploye(ArrayList* pList, ArrayList* pListArea)
{
    int auxReturn=-1;
    int i,j;
    int auxI;
    int auxI2;
    ArrayList* newAuxList;
    eEmploye* auxEmploye;
    if(newAuxList!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            auxEmploye = (eEmploye*)pList->get(pList,i);
            auxI=al_add(newAuxList,auxEmploye);
            if(auxI==-1)
            {
                printf("Hubo un error en el programa");
                auxReturn=-1;
            }
        }
    }


    if(pList!=NULL && auxI!=-1)
    {
        auxI=al_sort(newAuxList,compareEmployee,0);
        if(auxI==-1)
            {
                printf("Hubo un error en el programa");
                auxReturn=-1;
            }
        eEmploye* employe;
        eArea* area;

        for(i=0; i<pList->size; i++)
        {
            employe = (eEmploye*)newAuxList->get(newAuxList,i);
            for(j=0; j<pListArea->size; j++)
            {
                area = (eArea*)pListArea->get(pListArea,i);
                if(employe->area==area->areaCode)
                {
                    break;
                }
            }
            printf("%s \t%s \t%f \t%d \t%d \t%s\n",employe->name,employe->surname,employe->salary,employe->age,employe->legacy,area->areaName);
        }

        auxI2=(newAuxList);
        if(auxI2==-1)
            {
                printf("Hubo un error en el programa");
                auxReturn=-1;
            }

    }

    return auxReturn;
}

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((eEmploye*)pEmployeeA)->legacy > ((eEmploye*)pEmployeeB)->legacy)
    {
        return 1;
    }
    if(((eEmploye*)pEmployeeA)->legacy < ((eEmploye*)pEmployeeB)->legacy)
    {
        return -1;
    }
    return 0;


}

int seekIndex(ArrayList* pList)
{
    int i;
    int auxLegacy;
    int auxReturn=-1;
    eEmploye* employe;

    if(pList!=NULL)
    {
       printf("Ingrese el legajo del empleado deseado: ");
        scanf("%d", &auxLegacy);

        for(i=0;i<pList->size;i++)
        {
            employe = (eEmploye*)pList->get(pList,i);
            if((employe->legacy)==auxLegacy)
            {
                break;
            }
        }
        auxReturn=i;
    }
    return auxReturn;
}

int showMenuEmploye(void)
{
    int opcion;
    printf("1_Agregar empleado\n");
    printf("2_Borrar empleado\n");
    printf("3_Modificar empleado\n");
    printf("7_Salir\n");

    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

ArrayList* backUpEmploye(ArrayList* pList)
{
    ArrayList* auxReturn=NULL;
    ArrayList* newArray;
    int auxI;

    if(pList!=NULL)
    {
        newArray=al_clone(pList);
        if(newArray!=NULL)
        {
            auxI=al_containsAll(pList, newArray);
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

void printEmployee(eEmploye* p, eArea* p2)
{
    printf("%s \t%s \t%f \t%d \t%d \t%s\n",p->name,p->surname,p->salary,p->age,p->legacy,p2->areaName);
}

void printArrayListEmployee(ArrayList* pList, ArrayList* pListArea)
{
    int j,x;
    eEmploye* aux;
    eArea* area;
    if(pList!=NULL)
    {
        printf("Nombre\tApellido\tSalario\tEdad\tLegajo\tArea\n");

        for(j=0;j<pListArea->size;j++)
        {
            area=(eArea*)pListArea->get(pListArea,j);
            for(x=0;x<pList->size;x++)
            {
                aux=(eEmploye*)pList->get(pList,x);
                if(((area->areaCode)+j)==((aux->area)+x))
                {
                    printEmployee(aux, area);
                }
            }
        }

    }
}

int deleteEmployes(ArrayList* pList)
{
    int auxReturn=-1;
    int i,auxI,auxI2;

    if(pList!=NULL)
    {
        eEmploye* employe;
        for(i=0;i<pList->size;i++)
        {
            employe = (eEmploye*)pList->get(pList,i);
            free(employe+i);
        }
        auxI=al_deleteArrayList(pList);
        auxI2=al_clear(pList);
        auxReturn=0;
        if(auxI==-1 || auxI2==-1)
        {
            printf("Hubo un error en el prgrama");
            auxReturn=-1;
        }
    }
    return auxReturn;
}

int arrayLenght(ArrayList* pList)
{
    int auxReturn=-1;
    int auxI;

    if(pList!=NULL)
    {
        auxI=al_len(pList);
        if(auxI!=-1)
        {
            printf("Existen %d empleado/s", auxI);
            auxReturn=0;
        }
    }
    return auxReturn;
}

int showMainMenu(void)
{
    int opcion;
    printf("1_Ir a Menu de Empleados\n");
    printf("2_Ir a Menu de Areas\n");
    printf("3_Salir\n");

    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

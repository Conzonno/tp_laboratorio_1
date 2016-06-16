#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "ArrayList.h"
#include "area.h"

typedef struct
{
    char name[25];
    char surname[25];
    float salary;
    int age;
    int legacy;
    int area;
    int state;
}eEmploye;
#endif // EMPLOYEE_H_INCLUDED

eEmploye* newEmployeArray(void);

int addEmploye(ArrayList*);

int removeEmploye(ArrayList*);

int modifyEmploye(ArrayList*);

void printArrayListEmployee(ArrayList* pList, ArrayList* );

void printEmploye(eEmploye* p, eArea*);

int deleteEmployes(ArrayList* pList);

int arrayLenght(ArrayList* pList);

ArrayList* backUpEmploye(ArrayList*);

int seekIndex(ArrayList*);

int showMenuEmploye(void);

int showMainMenu(void);

int compareEmployee(void* pEmployeeA,void* pEmployeeB);

int sortEmploye(ArrayList* pList, ArrayList*);

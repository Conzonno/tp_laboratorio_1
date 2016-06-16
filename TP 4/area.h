#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED

#include "ArrayList.h"

typedef struct
{
    char areaName[50];
    int areaCode;
    int areaState;
}eArea;

eArea* newAreaArray(void);

int addArea(ArrayList*);

int removeArea(ArrayList*);

int modifyArea(ArrayList*);

int seekAreaIndex(ArrayList*);

int containsEmploye(ArrayList*, ArrayList*);

int deleteAreas(ArrayList* pListArea);

int arrayAreaLenght(ArrayList* pListArea);

void printArrayListArea(ArrayList* pListArea);

void printArea(eArea* p);

ArrayList* backUpArea(ArrayList*);

int showMenuArea(void);

#endif // AREA_H_INCLUDED

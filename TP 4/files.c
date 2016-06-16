#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "ArrayList.h"
#include "area.h"
#include "files.h"

int uploadEmployeFiles(ArrayList* pList)
{
    int i;
    int auxReturn=-1;
    FILE *empArch;
    eEmploye* employe;

    empArch=fopen("employes.dat","wb");
    if(empArch!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            employe = (eEmploye*)pList->get(pList,i);
            fwrite(employe,sizeof(eEmploye),1,empArch);
        }
        fclose(empArch);
        auxReturn=0;
    }

    return auxReturn;
}

int uploadAreaFiles(ArrayList* pListArea)
{
    int i;
    int auxReturn=-1;
    FILE *areaArch;
    eArea* area;

    areaArch=fopen("areas.dat","wb");
    if(areaArch!=NULL)
    {
        for(i=0;i<pListArea->size;i++)
        {
            area = (eArea*)pListArea->get(pListArea,i);
            fwrite(area,sizeof(eArea),1,areaArch);
        }
        fclose(areaArch);
        auxReturn=0;
    }

    return auxReturn;
}

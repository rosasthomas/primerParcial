#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bibliotecaGetsYComprobaciones.h"
#include "parcialDirectores.h"

int addDirec(sDirector listDirec[])
{
    int flag;
    int indexFreeSlot;

    indexFreeSlot = findFreeSlotDirec(listDirec, LEN_DIREC);
    if(indexFreeSlot == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        flag = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listDirec[indexFreeSlot]= setDirec(listDirec);
    flag = 0;

    return flag;
}

sDirector setDirec(sDirector listDirec[])
{
    sDirector director;

    director.id = nextIdDirec(listDirec, LEN_DIREC);

    fflush(stdin);
    getStringOnly("Ingrese el nombre: ", director.nombre);

    fflush(stdin);
    getStringOnly("Ingrese el pais origen: ", director.paisOrigen);

    director.fechaNacimiento = setDate();

    director.isEmpty = TAKEN;

    return director;
}

sFecha setDate()
{
    sDirector direc;
    char barra[2] = {"/"};

    validDay("Ingrese el dia: ", direc.fechaNacimiento.dia);
    validMonth("Ingrese el mes: ", direc.fechaNacimiento.mes);
    validYearDirec("Ingrese el anio: ", direc.fechaNacimiento.anio);
    strcpy(direc.fechaNacimiento.fecha, direc.fechaNacimiento.dia);
    strcat(direc.fechaNacimiento.fecha, barra);
    strcat(direc.fechaNacimiento.fecha, direc.fechaNacimiento.mes);
    strcat(direc.fechaNacimiento.fecha, barra);
    strcat(direc.fechaNacimiento.fecha, direc.fechaNacimiento.anio);

    return direc.fechaNacimiento;
}
int findFreeSlotDirec(sDirector listDirec[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listDirec[i].isEmpty == FREE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int nextIdDirec(sDirector listDirec[],int len)
{
    int value = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(listDirec[i].isEmpty== TAKEN)
        {
            if(listDirec[i].id > value)
            {
                value = listDirec[i].id;
            }
        }
    }
    return value + 1;
}

void validDay(char mensaje[], char day[])
{
    int flag;
    int auxDay;

    do
   {
        auxDay = getIntOnly(mensaje);
        if(auxDay < 1 || auxDay  > 31)
        {
            system("cls");
            printf("\nEl dia no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxDay, day, 10);
        }
   }while(flag != 1);
}

void validMonth(char mensaje[], char month[])
{
    int flag;
    int auxMonth;

    do
   {
        auxMonth = getIntOnly(mensaje);
        if(auxMonth < 1 || auxMonth > 12)
        {
            system("cls");
            printf("\nEl mes no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxMonth, month, 10);
        }
   }while(flag != 1);

}

void validYearDirec(char mensaje[], char year[])
{
    int flag;
    int auxYear;

    do
   {
        auxYear = getIntOnly(mensaje);
        if(auxYear < 1600 || auxYear > 2018)
        {
            system("cls");
            printf("\nEl anio no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxYear, year, 10);
        }
   }while(flag != 1);

}

void printADirector(sDirector listDirec[], int index)
{
    if(listDirec[index].isEmpty == TAKEN)
    {
        printf(" %5d| %-15s       | %-10s         | %s \n", listDirec[index].id, listDirec[index].nombre,
               listDirec[index].paisOrigen, listDirec[index].fechaNacimiento.fecha);
    }
}

void printDirector(sDirector listDirec[], int len)
{
    int i;
    printf("\n\n    Id| Nombre                | Pais de origen     |Fecha de nacimiento\n");
    for(i = 0; i < len; i++)
    {
        if(listDirec[i].isEmpty != FREE)
        {
            printADirector(listDirec, i);
        }
    }
}

int initDirec(sDirector listDirec[], int len)
{
    int flag = -1;
    int i;
    for(i = 0 ; i < len; i++)
    {
        listDirec[i].isEmpty = FREE;
        flag = 0;
    }

    return flag;
}

int removeDirec(sDirector listDirec[], int len)
{
    char auxNombre[256];
    int index;
    int flag;

    system("cls");
    printf("BAJA(director)\n\n");
    printDirector(listDirec, len);
    getStringOnly("\nIngrese el nombre del director a dar de baja: ", auxNombre);
    index = findDirecByName(listDirec, len, auxNombre);
    if(index == -1)
    {
        printf("No se encuentra ese nombre.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listDirec[index].isEmpty = FREE;
            flag = 0;
        }
    }
    return flag;
}

int findDirecByName(sDirector listDirec[], int len, char name[])
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listDirec[i].isEmpty != FREE && strcmp(listDirec[i].nombre, name) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void initDirectorHardCode(sDirector listDirec[])
{
    int id[4] = {100,101,102,103};
    char nombre[][50] = {"Oscar", "Ana", "Juan", "Jose"};
    char fecha[][11] = {"22/2/2000","10/11/1801","6/5/1978","30/8/2008"};
    char paisOrigen[][50] = {"argentina", "eeuu", "colombia", "venezuela"};

    int i;

    for(i=0; i<4; i++)
    {
        listDirec[i].id = id[i];
        listDirec[i].isEmpty = TAKEN;
        strcpy(listDirec[i].nombre, nombre[i]);
        strcpy(listDirec[i].paisOrigen, paisOrigen[i]);
        strcpy(listDirec[i].fechaNacimiento.fecha, fecha[i]);
    }
}

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

    setDate(director);

    director.isEmpty = TAKEN;

    return director;
}

void setDate(sDirector director)
{
    director.fechaNacimiento.dia = 20;//validDay("Ingrese el dia: ");
    director.fechaNacimiento.mes = 12;//validMonth("Ingrese el mes: ");
    director.fechaNacimiento.anio = 2000;//validYearDirec("Ingrese el anio: ");
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

int validDay(char mensaje[])
{
    int day;
    int flag;

    do
   {
        day = getIntOnly(mensaje);
        if(day < 1 || day > 31)
        {
            system("cls");
            printf("\nEl dia no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
   }while(flag != 1);

    return day;
}

int validMonth(char mensaje[])
{
    int month;
    int flag;

    do
   {
        month = getIntOnly(mensaje);
        if(month < 1 || month > 12)
        {
            system("cls");
            printf("\nEl mes no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
   }while(flag != 1);

    return month;
}

int validYearDirec(char mensaje[])
{
    int year;
    int flag;

    do
   {
        year = getIntOnly(mensaje);
        if(year < 1000 || year > 2018)
        {
            system("cls");
            printf("\nEl anio no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
   }while(flag != 1);

    return year;
}

void printADirector(sDirector listDirec[], int index)
{
    if(listDirec[index].isEmpty == TAKEN)
    {
        printf(" %5d| %-15s       | %-10s          | %d\n", listDirec[index].id, listDirec[index].nombre,
               listDirec[index].paisOrigen, listDirec[index].fechaNacimiento.dia);
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
    printf("BAJA (director)\n\n");
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

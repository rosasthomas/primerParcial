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

    director.fechaNacimiento.dia = 20;
    director.fechaNacimiento.mes = 10;
    director.fechaNacimiento.anio = 2000;

    director.isEmpty = TAKEN;

    return director;
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

/*sFecha getFecha(sDirector listDirec[])
{
    sFecha fecha;
    char barra[2] = {"/"};

    //barra = "/";
    char dia[3];
    dia = validDia("Ingrese el dia: ");
    strcpy(fecha.dia, dia);
    fecha.mes = validMes("Ingrese el mes: ");
    fecha.anio = validAnioDirec("Ingrese el anio: ");

    strcpy(fecha.fecha, fecha.dia);
    strcpy(fecha.fecha, barra);
    strcpy(fecha.fecha, fecha.mes);
    strcpy(fecha.fecha, barra);
    strcpy(fecha.fecha, fecha.anio);

    return fecha;
}

char validDia(char mensaje[])
{
    char dia[3];
    int flag;

    do
   {
        getStringNumber(mensaje, dia);
        if(dia < '1' && dia > '31')
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

    return dia;
}

char validMes(char mensaje[])
{
    char mes[3];
    int flag;

    do
   {
        getStringNumber(mensaje, mes);
        if(mes < '1' || mes > '12')
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

    return mes;
}

char validAnioDirec(char mensaje[])
{
    char anio[5];
    int flag;

    do
   {
        getStringNumber(mensaje, anio);
        if(anio < '1' || anio > '2018')
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

    return anio;
}
*/

void printADirector(sDirector listDirec[], int index)
{
    if(listDirec[index].isEmpty == TAKEN)
    {
        printf(" %5d| %-15s         | %-15s         \n", listDirec[index].id, listDirec[index].nombre,
               listDirec[index].paisOrigen);
    }
}

void printDirector(sDirector listDirec[], int len)
{
    int i;
    printf("\n\n    Id| Nombre                | Pais de origen   \n");
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

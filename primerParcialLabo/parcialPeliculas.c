#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "parcialPeliculas.h"

int initFilm(sFilm listFilm[], int len)
{
    int flag = -1;
    int i;
    for(i = 0 ; i < len; i++)
    {
        listFilm[i].isEmpty = FREE;
        flag = 0;
    }

    return flag;
}

int addFilm(sFilm listFilm[])
{
    int flag;
    int indexFreeSlot;

    indexFreeSlot = findFreeSlot(listFilm, LEN_PEL);
    if(indexFreeSlot == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        flag = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listFilm[indexFreeSlot] = setFilm(listFilm);
    flag = 0;

    return flag;
}

sFilm setFilm(sFilm listFilm[])
{
    sFilm film;

    film.id = nextId(listFilm, LEN_PEL);

    fflush(stdin);
    getStringOnly("Ingrese el titulo: ", film.titulo);

    film.director = getIntOnly("Ingrese director: ");

    fflush(stdin);
    getStringOnly("Ingrese la nacionalidad: ", film.nacionalidad);

    film.anio = validAnio("Ingrese el anio: ");

    film.isEmpty = TAKEN;

    return film;
}

int findFreeSlot(sFilm listFilm[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listFilm[i].isEmpty == FREE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int nextId(sFilm listFilm[],int len)
{
    int value = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(listFilm[i].isEmpty== TAKEN)
        {
            if(listFilm[i].id > value)
            {
                value = listFilm[i].id;
            }
        }
    }
    return value + 1;
}

void listar(sFilm listFilm[], int len)
{
    int  choice;
    system("cls");
    do
    {
        choice = getIntOnly("Listar\n\n1.Listar Peliculas\n2.\n3.Regresar\nIngrese una opcion: ");
        switch(choice)
        {
        case 1:
            system("cls");
            printFilm(listFilm, len);
            system("pause");
            break;
        case 2:
            break;
        case 3:
            choice = 3;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
        system("cls");
    }while(choice != 3);
}

void printAnFilm(sFilm listFilm[], int index)
{
    if(listFilm[index].isEmpty == TAKEN)
    {
        printf(" %5d| %-8s    |    %d    |  %d  | %-8s\n", listFilm[index].id, listFilm[index].titulo,
               listFilm[index].director, listFilm[index].anio, listFilm[index].nacionalidad);
    }
}

void printFilm(sFilm listFilm[], int len)
{
    int i;
    printf("\n\nId    | Titulo      | Director| Anio   | Nacionalidad  \n");
    for(i = 0; i < len; i++)
    {
        if(listFilm[i].isEmpty != FREE)
        {
            printAnFilm(listFilm, i);
        }
    }
}

int validAnio(char mensaje[])
{
    int anio;
   int flag = 0;
   do
   {
         anio = getIntOnly(mensaje);
        if(anio < 1600 || anio > 2018)
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

int modifyFilm(sFilm listFilm[])
{
    int auxId;
    int indexPosition;
    int flag;

    system("cls");
    printf("MODIFICAR\n\n");
    printFilm(listFilm, LEN_PEL);
    auxId = getIntOnly("Ingrese el Id a modificar: ");
    indexPosition = findFilmById(listFilm, LEN_PEL, auxId);
    if(indexPosition == -1)
    {
        printf("\nLa Id no existe.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        modifyMenu(listFilm, indexPosition);
        flag = 0;
    }

    return flag;
}

int findFilmById(sFilm listFilm[], int len, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listFilm[i].isEmpty != FREE && listFilm[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void modifyMenu(sFilm listFilm[], int position)
{
    int choice;

    do
    {
        system("cls");
        choice = getIntOnly("MODIFICAR\n\n1.Titulo \n2.Anio \n3.Nacionalidad \n4.Director \n5.Regresar \n Ingrese una opcion: ");
        switch(choice)
        {
        case 1: //modificar titulo
            modifyTitle(listFilm, position);
            break;
        case 2: //modificar Anio
            modifyAnio(listFilm, position);
            break;
        case 3: //modificar nacionalidad
            modifyNacionalidad(listFilm, position);
            break;
        case 4: //modificar director
            modifyDirector(listFilm, position);
            break;
        case 5://regresar
            choice = 5;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
    }
    while(choice != 5);
}

void modifyTitle(sFilm listFilm[], int position)
{
    char auxTitle[100];
    system("cls");
    printf("Modificacion del titulo\n\n");
    printAnFilm(listFilm, position);
    getStringOnly("\nIngrese el nuevo titulo: ", auxTitle);
    printf("\nEsta seguro que desea cambiar el titulo?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listFilm[position].titulo, auxTitle);
    }
}

void modifyAnio(sFilm listFilm[], int position)
{
    int auxAnio;
    system("cls");
    printf("Modificacion del anio\n\n");
    printAnFilm(listFilm, position);
    auxAnio = validAnio("\nIngrese el nuevo anio: ");
    printf("\nEsta seguro que desea cambiar el anio?(s/n): ");
    if(getch() == 's')
    {
        listFilm[position].anio = auxAnio;
    }
}

void modifyNacionalidad(sFilm listFilm[], int position)
{
    char auxNacionalidad[100];
    system("cls");
    printf("Modificacion de nacionalidad\n\n");
    printAnFilm(listFilm, position);
    getStringOnly("\nIngrese la nueva nacionalidad: ", auxNacionalidad);
    printf("\nEsta seguro que desea cambiar la nacionalidad?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listFilm[position].nacionalidad, auxNacionalidad);
    }
}

void modifyDirector(sFilm listFilm[], int position)
{
    int auxDirector;
    system("cls");
    printf("Modificacion del director\n\n");
    printAnFilm(listFilm, position);
    auxDirector = getIntOnly("\nIngrese el nuevo director: ");
    printf("\nEsta seguro que desea cambiar el director?(s/n): ");
    if(getch() == 's')
    {
        listFilm[position].anio = auxDirector;
    }
}

void initPeliculaHardCode(sFilm listFilm[])
{
    int id[4] = {100,101,102,103};
    char titulo[][50] = {"luna", "marte", "jupiter", "saturno"};
    int anio[4] = {2000,2001,2010,2018};
    int director[4] = {1,2,3,4};
    char nacionalidad[][50] = {"argentina", "eeuu", "colombia", "venezuela"};

    int i;

    for(i=0; i<4; i++)
    {
        listFilm[i].id=id[i];
        listFilm[i].anio=anio[i];
        listFilm[i].director = director[i];
        listFilm[i].isEmpty = TAKEN;
        strcpy(listFilm[i].titulo, titulo[i]);
        strcpy(listFilm[i].nacionalidad, nacionalidad[i]);
    }

}

int removeFilm(sFilm listFilm[], int len)
{
    int auxId;
    int index;
    int flag;

    system("cls");
    printf("BAJA\n\n");
    printFilm(listFilm, len);
    auxId = getIntOnly("\nIngrese el numero de Id a dar de baja: ");
    index = findFilmById(listFilm, len, auxId);
    if(index == -1)
    {
        printf("No se encuentra ese Id.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listFilm[index].isEmpty = FREE;
            flag = 0;
        }
    }
    return flag;
}


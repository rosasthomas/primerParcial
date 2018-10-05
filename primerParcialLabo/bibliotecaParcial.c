#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bibliotecaParcial.h"


void listar(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec)
{
    int  choice;
    system("cls");
    do
    {
        choice = getIntOnly("Listar\n\n1.Listar Peliculas\n2.Listar Directores\n3.Regresar\nIngrese una opcion: ");
        switch(choice)
        {
        case 1:
            system("cls");
            printFilm(listFilm, lenFilm);
            system("pause");
            break;
        case 2:
            system("cls");
            printDirector(listDirec, lenDirec);
            system("pause");
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

sFilm setFilm(sFilm listFilm[], sDirector listDirec[], int lenDirec)
{
    sFilm film;
    int flag = 0;

    film.id = nextId(listFilm, LEN_PEL);

    fflush(stdin);
    getStringOnly("Ingrese el titulo: ", film.titulo);

    fflush(stdin);
    getStringOnly("Ingrese la nacionalidad: ", film.nacionalidad);

    film.anio = validAnio("Ingrese el anio: ");
    do
    {
    printDirector(listDirec, lenDirec);
    film.director = getIntOnly("Ingrese director: ");
    int i;
    for(i = 0; i < lenDirec; i++)
    {
        if(film.director != listDirec[i].id || film.director == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    printf("Ese director no existe\n");
    system("pause");
    system("cls");
    }while(flag != 1);
    film.isEmpty = TAKEN;

    return film;
}

int addFilm(sFilm listFilm[], sDirector listDirec[])
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
    listFilm[indexFreeSlot] = setFilm(listFilm, listDirec, LEN_DIREC);
    flag = 0;

    return flag;
}

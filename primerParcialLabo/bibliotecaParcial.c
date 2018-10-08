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
        choice = getIntOnly("Listar\n\n1.Listar Peliculas\n2.Listar Directores\n3.La/s peliculas mas viejas\n"
                            "4.Cada pelicula con el nombre de su director\n5.Director con su pelicula\n"
                            "6.Cantidad de peliculas por director\n7.Los directores con mas peliculas\n"
                            "8.Regresar\nIngrese una opcion: ");
        switch(choice)
        {
        case 1://listar peliculas
            system("cls");
            printFilm(listFilm, lenFilm);
            system("pause");
            break;
        case 2://listar directores
            system("cls");
            printDirector(listDirec, lenDirec);
            system("pause");
            break;
        case 3://peliculas mas viejas
            system("cls");
            listOldsFilms(listFilm, lenFilm);
            system("pause");
            break;
        case 4://peliculas con nombre de director
            system("cls");
            printFilmWithDirec(listFilm, lenFilm, listDirec, lenDirec);
            system("pause");
            break;
        case 5:
            system("cls");
            directorWithFilms(listFilm, lenFilm, listDirec, lenDirec);
            system("pause");
            break;
        case 6:
            system("cls");
            qtyFilmsForDirec(listFilm, lenFilm, listDirec, lenDirec);
            system("pause");
            break;
        case 7:
            system("cls");
            direcMasPelis(listFilm, lenFilm, listDirec, lenDirec);
            system("pause");
            break;
        case 8://salir
            choice = 8;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
        system("cls");
    }while(choice != 8);
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
    film.director = getIntOnly("Ingrese ID del director: ");
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
    if(flag == 0)
    {
        printf("Ese director no existe\n");
    }
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

void listOldsFilms(sFilm listFilm[], int len)
{
    int i;

    int min = 2019;


    printf("LAS PELICULAS MAS VIEJAS\n\n");
    printf("\n\n    Id| Titulo                  | Director |   Anio  | Nacionalidad  \n");
    for(i = 0; i < len; i++)
    {
        if(listFilm[i].anio < min && listFilm[i].isEmpty != FREE)
        {
            min = listFilm[i].anio;
        }
    }
    int k;
    for(k = 0; k < len; k++)
    {
        if(listFilm[k].anio == min && listFilm[k].isEmpty != FREE)
        {
            printAFilm(listFilm, k);
        }
    }
}

void printFilmWithDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec)
{
    int i;
    printf("PELICULAS CON NOMBRE DE SU DIRECTOR\n\n");
    printf("\n\n    Id| Titulo                  | Director  |   Anio  | Nacionalidad  \n");
    for(i = 0; i < lenFilm; i++)
    {

            printAFilmWithDirec(listFilm, i, listDirec);

    }

}

void printAFilmWithDirec(sFilm listFilm[], int index, sDirector listDirec[])
{
    if(listFilm[index].isEmpty == TAKEN)
    {
        int i;
        for(i = 0; i < LEN_DIREC; i++)
        {
            if(listFilm[index].director == listDirec[i].id)
            {
               printf(" %5d| %-15s         | %-10s    |  %5d  | %-8s\n", listFilm[index].id, listFilm[index].titulo,
               listDirec[i].nombre, listFilm[index].anio, listFilm[index].nacionalidad);
            }
        }
    }
}

void directorWithFilms(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec)
{
    printf("DIRECTORES CON SUS PELICULAS\n\n");

    int i;
    int k;

    for(i = 0; i < lenDirec; i++)
    {
        if(listDirec[i].isEmpty != FREE)
        {
            printf("\n%s: \n", listDirec[i].nombre);
        }
        for(k = 0; k < lenFilm; k++)
        {
            if(listFilm[k].director == listDirec[i].id && listFilm[k].isEmpty != FREE)
            {
                printAFilm(listFilm, k);
            }
        }
    }
}

void qtyFilmsForDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec)
{
    char auxName[51];
    int auxIdDirec;
    int flag = 0;
    int i;
    int contador = 0;

    printf("CANTIDAD DE PELICULAS POR DIRECTOR\n\n");
    printDirector(listDirec, lenDirec);
    do
    {
        getStringLetters("Ingrese el nombre del director: ", auxName);
        for(i = 0; i < lenDirec; i++)
        {
            if(strcmp(auxName, listDirec[i].nombre) == 0)
            {
                auxIdDirec = listDirec[i].id;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Ese director no existe.");
        }
    }while(flag != 1);

    for(i = 0; i < lenFilm; i++)
        {
            if(listFilm[i].director == auxIdDirec)
            {
                contador++;
            }
        }
    printf("\n%s tiene %d peliculas.\n", auxName, contador);
}

void direcMasPelis(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec)
{
    printf("LOS DIRECTORES CON MAS PELICULAS\n\n");

    int i;
    int k;
    int m;
    int q;
    int cont = 0;
    int max = 0;
    int contDos = 0;

    for(i = 0; i < lenDirec; i++)
    {
        cont = 0;
       if(listDirec[i].isEmpty != FREE)
       {
        for(k = 0; k < lenFilm; k++)
        {
            if(listFilm[k].director == listDirec[i].id && listFilm[k].isEmpty != FREE)
            {
                cont++;

            }
        }
       }
       if(cont > max)
       {
        max = cont;
       }
    }
    printf("Los directores con mas peliculas son: \n");
   for(m = 0; m < lenDirec; m++)
    {
        contDos = 0;
       if(listDirec[m].isEmpty != FREE)
       {
        for(q = 0; q < lenFilm; q++)
        {
            if(listFilm[q].director == listDirec[m].id && listFilm[q].isEmpty != FREE)
            {
                contDos++;
            }
        }
       }
        if(contDos == max)
        {
            printf("                %s\n",listDirec[m].nombre);
        }
    }
}

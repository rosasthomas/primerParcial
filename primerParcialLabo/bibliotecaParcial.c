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

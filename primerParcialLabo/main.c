#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaParcial.h"
#include "bibliotecaGetsYComprobaciones.h"

int main()
{
    sFilm listFilm[LEN_PEL];
    sDirector listDirec[LEN_DIREC];
    int choice;
    int isErrorFilm;
    int isErrorDirec;
    int isErrorAdd;
    int isErrorRemove;
    int flagIsCharged = 1;
    int isErrorModify;
    int isErrorAddDirec;

    do
    {
        isErrorFilm = initFilm(listFilm, LEN_PEL);
        isErrorDirec = initDirec(listDirec, LEN_DIREC);
        initPeliculaHardCode(listFilm);
    }while(isErrorFilm == -1 || isErrorDirec == -1);

    do
    {
        choice = getIntOnly("Ficha tecnica\n\n1.Alta de pelicula\n2.Modificar pelicula\n3.Baja pelicula\n4.Alta director\n5.\n6.Listar\n7.Salir\nIngrese una opcion: ");

        switch(choice)
        {
        case 1://alta pelicula
            isErrorAdd = addFilm(listFilm, listDirec);
                if(isErrorAdd == 0)
                {
                    flagIsCharged = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
            break;
        case 2://modif
                if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }
                isErrorModify = modifyFilm(listFilm);
                if(isErrorModify == 0)
                {
                    system("cls");
                    printf("\nSe modifico correctamente.\n");
                }
                 else
                {
                    system("cls");
                    printf("\n No se ha podido modificar el empleado.\n");
                }
            break;
        case 3://baja
            if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
               isErrorRemove = removeFilm(listFilm, LEN_PEL);
               if(isErrorRemove == 0)
                {
                    system("cls");
                    printf("\nSe dio de baja correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido dar de baja la pelicula.\n");
                }
            break;
        case 4: //alta director
                isErrorAddDirec = addDirec(listDirec);
                if(isErrorAddDirec == 0)
                {
                    flagIsCharged = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
            break;
        case 5:
            break;
        case 6:
            if(flagIsCharged != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }
            listar(listFilm, LEN_PEL, listDirec, LEN_DIREC);
            break;
        case 7:
            choice = 7;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
        system("pause");
        system("cls");
    }while(choice != 7);
    return 0;
}

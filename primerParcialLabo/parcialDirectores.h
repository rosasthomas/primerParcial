#include "bibliotecaGetsYComprobaciones.h"
#define LEN_DIREC 500
#define FREE 1
#define TAKEN 0

typedef struct
{
    char dia[3];
    char mes[3];
    char anio[5];
    char fecha[11];
}sFecha;

typedef struct
{
    int id;
    char nombre[51];
    sFecha fechaNacimiento;
    char paisOrigen[51];
    int isEmpty;
}sDirector;

int addDirec(sDirector listDirec[]);

sDirector setDirec(sDirector listDirec[]);

int findFreeSlotDirec(sDirector listDirec[], int len);

int nextIdDirec(sDirector listDirec[],int len);

sFecha getFecha(sDirector listDirec[]);

char validDia(char mensaje[]);

char validMes(char mensaje[]);

char validAnioDirec(char mensaje[]);

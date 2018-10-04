#include "bibliotecaGetsYComprobaciones.h"
#define LEN_DIREC 500
#define FREE 1
#define TAKEN 0

typedef struct
{
    int dia;

    int mes;
    int anio;
}sFecha;

typedef struct
{
    int id;
    char nombre[51];
    sFecha fechaNacimiento;
    char paisOrigen[51];
    int isEmpty;
}sDirector;

/** \brief add a director in array of directors
 *
 * \param listDirec[] sDirector array of directors
 * \return int return (-1) if error, (0) if ok
 *
 */
int addDirec(sDirector listDirec[]);

/** \brief load the information about a director
 *
 * \param listDirec[] sDirector array of directors
 * \return sDirector data set of director
 *
 */
sDirector setDirec(sDirector listDirec[]);

/** \brief find free slot in flag(isEmpty)
 *
 * \param listDirec[] sDirector array of directors
 * \param len int array length
 * \return int index of free slot
 *
 */
int findFreeSlotDirec(sDirector listDirec[], int len);

/** \brief find free slot in flag(isEmpty)
 *
 * \param listDirec[] sDirector array of directors
 * \param len int array length
 * \return int index of free slot
 *
 */
int nextIdDirec(sDirector listDirec[],int len);

/*
sFecha getFecha(sDirector listDirec[]);

char validDia(char mensaje[]);

char validMes(char mensaje[]);

char validAnioDirec(char mensaje[]);
*/

/** \brief print directors array
 *
 * \param listDirec[] sDirector array of directors
 * \param len int array length
 * \return void
 *
 */
void printDirector(sDirector listDirec[], int len);

/** \brief print information about one director
 *
 * \param listDirec[] sDirector array of directors
 * \param index int position of director
 * \return void
 *
 */
void printADirector(sDirector listDirec[], int index);

/** \brief Initialize all the flags (isEmpty) in true
 *
 * \param listDirec sDirector array of directors
 * \param len int array length
 * \return int  Return (-1) if Error - (0) if Ok
 *
 */
int initDirec(sDirector listDirec[], int len);

/** \brief find a directors by name and returns the position in array
 *
 * \param listDirec[] sDirector array of directors
 * \param len int array length
 * \param name[] char name to search
 * \return int (-1) if error or director index position
 *
 */
int findDirecByName(sDirector listDirec[], int len, char name[]);

/** \brief remove director interface
 *
 * \param listDirec[] sDirector array of directors
 * \param len int array length
 * \return int (-1) if error, (0) if ok
 *
 */
int removeDirec(sDirector listDirec[], int len);

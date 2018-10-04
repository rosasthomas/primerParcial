#include "bibliotecaGetsYComprobaciones.h"
#define LEN_PEL 1000
#define FREE 1
#define TAKEN 0

typedef struct
{
    int id;
    char titulo[51];
    char nacionalidad[51];
    int director;
    int anio;
    int isEmpty;
}sFilm;

/** \brief Initialize all the flags (isEmpty) in true
 *
 * \param listFilm sFilm array of films
 * \param len int array length
 * \return int  Return (-1) if Error - (0) if Ok
 *
 */
int initFilm(sFilm listFilm[], int len);

sFilm setFilm(sFilm listFilm[]);

/** \brief find free slot in flag(isEmpty)
 *
 * \param listFilm[] sFilm array of Film
 * \param len int array length
 * \return int index of free slot
 *
 */
int findFreeSlot(sFilm listFilm[], int len);
/** \brief add a Film in array of Film
 *
 * \param listFilm[] sFilm array of Film
 * \return int return (-1) if error, (0) if ok
 *
 */
int addFilm(sFilm listFilm[]);

/** \brief find the next id for Film
 *
 * \param listFilm[] sFilm array of Film
 * \param len int array length
 * \return int value of next id
 *
 */
int nextId(sFilm listFilm[],int len);

/** \brief modify information about an Film
 *
 * \param listFilm[] sFilm array of Film
 * \return int (-1) if error, (0) if ok
 *
 */

void listar(sFilm listFilm[], int len);

/** \brief print information about one Film
 *
 * \param listFilm[] sFilm array of Film
 * \param index int position of Film
 * \return void
 *
 */
void printAnFilm(sFilm listFilm[], int index);

/** \brief print Film array
 *
 * \param listFilm[] sFilm array of Film
 * \param len int array length
 * \return void
 *
 */
void printFilm(sFilm listFilm[], int len);

int validAnio(char mensaje[]);

int findFilmById(sFilm listFilm[], int len, int id);

void modifyMenu(sFilm listFilm[], int position);

void modifyTitle(sFilm listFilm[], int position);

void modifyAnio(sFilm listFilm[], int position);

void modifyDirector(sFilm listFilm[], int position);

void modifyNacionalidad(sFilm listFilm[], int position);

int modifyFilm(sFilm listFilm[]);

void initPeliculaHardCode(sFilm listFilm[]);

int removeFilm(sFilm listFilm[], int len);


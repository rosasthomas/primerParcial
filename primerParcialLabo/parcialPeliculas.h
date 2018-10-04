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

/** \brief load the information about a film
 *
 * \param listFilm sFilm array of films
 * \return sFilm data set of film
 *
 */
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

/** \brief print information about one Film
 *
 * \param listFilm[] sFilm array of Film
 * \param index int position of Film
 * \return void
 *
 */
void printAFilm(sFilm listFilm[], int index);

/** \brief print Film array
 *
 * \param listFilm[] sFilm array of Film
 * \param len int array length
 * \return void
 *
 */
void printFilm(sFilm listFilm[], int len);

/** \brief check if the enter number is a logic year
 *
 * \param mensaje[] char
 * \return int year
 *
 */
int validAnio(char mensaje[]);

/** \brief find a film by id and returns the position in array
 *
 * \param listFilm[] sFilm array of films
 * \param len int array length
 * \param id int id to search
 * \return int (-1) if error or film index position
 *
 */
int findFilmById(sFilm listFilm[], int len, int id);

/** \brief menu to select what modify
 *
 * \param listFilm[] sFilm array of films
 * \param position int film position in array
 * \return void
 *
 */
void modifyMenu(sFilm listFilm[], int position);

/** \brief modify the title of a film
 *
 * \param listFilm[] sFilm array of films
 * \param position int film position in array
 * \return void
 *
 */
void modifyTitle(sFilm listFilm[], int position);

/** \brief modify the year of a film
 *
 * \param listFilm[] sFilm array of films
 * \param position int film position in array
 * \return void
 *
 */
void modifyAnio(sFilm listFilm[], int position);

/** \brief modify the director of a film
 *
 * \param listFilm[] sFilm array of films
 * \param position int film position in array
 * \return void
 *
 */
void modifyDirector(sFilm listFilm[], int position);

/** \brief modify the nationality of a film
 *
 * \param listFilm[] sFilm array of films
 * \param position int film position in array
 * \return void
 *
 */
void modifyNacionalidad(sFilm listFilm[], int position);


/** \brief modify film interface
 *
 * \param listFilm[] sFilm arraoy of films
 * \return int (-1) if error, (0) if ok
 *
 */
int modifyFilm(sFilm listFilm[]);

/** \brief initialize harcode of films
 *
 * \param listFilm[] sFilm array of films
 * \return void
 *
 */
void initPeliculaHardCode(sFilm listFilm[]);

/** \brief remove film interface
 *
 * \param listFilm[] sFilm array of films
 * \param len int array length
 * \return int (-1) if error, (0) if ok
 *
 */
int removeFilm(sFilm listFilm[], int len);


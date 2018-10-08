#include "parcialDirectores.h"
#include "parcialPeliculas.h"

/** \brief list interface
 *
 * \param listFilm[] sFilm array of films
 * \param lenFilm int array films length
 * \param listDirec[] sDirector array of directors
 * \param lenDirec int array directors length
 * \return void
 *
 */
void listar(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);

/** \brief load the information about a film
 *
 * \param listFilm sFilm array of films
 * \return sFilm data set of film
 *
 */
sFilm setFilm(sFilm listFilm[], sDirector listDirec[], int lenDirec);

/** \brief add a Film in array of Film
 *
 * \param listFilm[] sFilm array of Film
 * \return int return (-1) if error, (0) if ok
 *
 */
int addFilm(sFilm listFilm[], sDirector listDirec[]);

void listOldsFilms(sFilm listFilm[], int len);
void printAFilmWithDirec(sFilm listFilm[], int index, sDirector listDirec[]);
void printFilmWithDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);

void directorWithFilms(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);
void qtyFilmsForDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);

void direcMasPelis(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);


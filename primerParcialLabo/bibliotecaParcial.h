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

/** \brief lista las peliculas mas antiguas
 *
 * \param listFilm[] sFilm array of films
 * \param len int   array film
 * \return void
 *
 */
void listOldsFilms(sFilm listFilm[], int len);
/** \brief  muestra una pelicula con su director
 *
 * \param listFilm[] sFilm array of films
 * \param index int posicion del array
 * \param listDirec[] sDirector array of directors
 * \return void
 *
 */
void printAFilmWithDirec(sFilm listFilm[], int index, sDirector listDirec[]);
/** \brief imprime la lista de peliculas con su director
 *
 * \param listFilm[] sFilm array of films
 * \param lenFilm int array films length
 * \param listDirec[] sDirector array of directors
 * \param lenDirec int array directors length
 * \return void
 *
 */
void printFilmWithDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);

/** \brief muestra un director con sus peliculas
 *
 * \param listFilm[] sFilm array of films
 * \param lenFilm int array films length
 * \param listDirec[] sDirector array of directors
 * \param lenDirec int array directors length
 * \return void
 *
 */
void directorWithFilms(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);
/** \brief muestra la cantidad de peliculas por director
 *
 * \param listFilm[] sFilm array of films
 * \param lenFilm int array films length
 * \param listDirec[] sDirector array of directors
 * \param lenDirec int array directors length
 * \return void
 *
 */
void qtyFilmsForDirec(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);

/** \brief muestra el director con mas peliculas
 *
 * \param listFilm[] sFilm array of films
 * \param lenFilm int array films length
 * \param listDirec[] sDirector array of directors
 * \param lenDirec int array directors length
 * \return void
 *
 */
void direcMasPelis(sFilm listFilm[], int lenFilm, sDirector listDirec[], int lenDirec);


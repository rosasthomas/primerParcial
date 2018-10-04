typedef struct
{
    int legajo;
    char nombre[21];
    int nota;
    float altura;
    char mail[50];
    int estado;
}sAlumno;

/** \brief muestra los datos de un alumno
 *
 * \param sAlumno[] array donde se encuentra
 * \param int subindice del array
 * \return void
 *
 */
void mostrarUnAlumno(sAlumno[], int);
/** \brief cargar los datos de un alumno
 *
 * \return sAlumno devuelve los datos
 *
 */
sAlumno cargarUnAlumno();
/** \brief carga un listado
 *
 * \param sAlumno[] array del listado
 * \param int el tamaño del array
 * \return void
 *
 */
void cargarListado(sAlumno[], int);
/** \brief muestra un listado
 *
 * \param sAlumno[] array del listado
 * \param int tamaño del array
 * \return void
 *
 */
void mostrarListado(sAlumno[], int);
/** \brief ordena por nombre
 *
 * \param sAlumno[] array de alumnos
 * \param int tamaño del array
 * \return void
 *
 */
void ordenar(sAlumno[], int);
/** \brief inicializa el campo "estado" de la estructura en un valor
 *
 * \param sAlumno[] el array
 * \param int el tamaño del array
 * \param int valor con el cual de cargara "estado"
 * \return void
 *
 */
void inicializoEstructura(sAlumno[], int, int);
/** \brief busca el primer lugar donde se encuentre el valor requerido en el campo "estado"
 *
 * \param sAlumno[] el array
 * \param int tamaño del array
 * \param int valor a buscar
 * \return int retorna el subindice donde se encontro
 *
 */
int buscarPrimerOcurrenciaEstado(sAlumno[], int, int);
/** \brief busca el primer lugar donde se encuentre el valor requerido en el campo "legajo"
 *
 * \param sAlumno[] el array
 * \param int el tamaño del array
 * \param int valor a buscar
 * \return int retorna el subindice donde se encontro
 *
 */
int buscarPrimerOcurrenciaLegajo(sAlumno[], int, int);
/** \brief da de alta un alumno
 *
 * \param sAlumno[] array donde dar de alta
 * \return int 1 si se dio de alta, 0 si no
 *
 */
int altaDeAlumno(sAlumno[]);
/** \brief da de baja un alumno
 *
 * \param sAlumno[] array donde dar de baja
 * \return int 1 si se dio de baja, 0 si no
 *
 */
int bajaDeAlumno(sAlumno[]);
/** \brief modifica la nota de un alumno
 *
 * \param sAlumno[] array donde se encuentra el alumno
 * \return int 1 si se modifico, 0 si no
 *
 */
int modificacionDeAlumno(sAlumno[]);

/** \brief carga una estructura con datos determinados
 *
 * \param sAlumno[] array a inicializar
 * \param int tamaño del array
 * \return void
 *
 */
void inicializarAlumnos(sAlumno[], int);

/** \brief inicia el campo estado en 0 (libre) y el campo legajo en 0
 *
 * \param sAlumno[] array de alumnos
 * \param  int tamaño del array
 * \return int -1 si no se realizo, 0 si se realizo
 *
 */
int eGen_init(sAlumno[],int );
/** \brief da el numero del proximo id a ingresar
 *
 * \param sAlumno[] array de alumnos
 * \param  int  tamaño del array
 * \return int 0 si no se realizo, numero del proximo id
 *
 */
int eGen_siguienteId(sAlumno[] ,int );

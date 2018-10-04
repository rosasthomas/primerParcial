#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaEstructuras.h"
#include "bibliotecaGetsYComprobaciones.h"
#define LIBRE 0
#define OCUPADO 1

void mostrarUnAlumno(sAlumno listado[], int indice)
{
    printf("%d -- %s -- %f -- %d -- %s\n", listado[indice].legajo, listado[indice].nombre, listado[indice].altura, listado[indice].nota, listado[indice].mail);
}

sAlumno cargarUnAlumno()
{
    sAlumno miAlumno;

    miAlumno.legajo = getIntOnly("Ingrese legajo: ");

    fflush(stdin);
    getStringOnly("Ingrese nombre: ", miAlumno.nombre);

    miAlumno.nota = getIntOnly("Ingrese nota: ");

    miAlumno.altura = getFloatOnly("Ingrese altura: ");

    printf("Ingrese mail: ");
    fflush(stdin);
    gets(miAlumno.mail);

    miAlumno.estado = 1;

    return miAlumno;
}

void cargarListado(sAlumno listadoAlumnos[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listadoAlumnos[i] = cargarUnAlumno();
    }
}

void mostrarListado(sAlumno listadoAlumnos[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listadoAlumnos[i].estado != -1)
        {
            mostrarUnAlumno(listadoAlumnos, i);
        }
    }
}

void ordenar(sAlumno listado[], int tam)
{
    int i;
    int j;
    sAlumno auxAlumno;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(strcmp(listado[i].nombre, listado[j].nombre) > 0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }
    }
}

void inicializoEstructura(sAlumno listado[], int cantidad, int valorInicio)
{
    int indice;
    for(indice = 0 ; indice < cantidad; indice++)
    {
        listado[indice].estado = valorInicio;
    }
}

int buscarPrimerOcurrenciaEstado(sAlumno listado[], int cantidad, int valor)
{
    int index = -1;
    int i;
    for(i = 0; i < cantidad; i ++)
    {
        if(listado[i].estado == valor)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarPrimerOcurrenciaLegajo(sAlumno listado[], int cantidad, int valor)
{
    int index = -1;
    int i;
    for(i = 0; i < cantidad; i ++)
    {
        if(listado[i].estado != -1 && listado[i].legajo == valor)
        {
            index = i;
            break;
        }
    }
    return index;
}

int altaDeAlumno(sAlumno listado[])
{
    int bandera;
    int indiceLugarLibre;

    indiceLugarLibre = buscarPrimerOcurrenciaEstado(listado, 10, LIBRE);
    if(indiceLugarLibre == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        bandera = 0;
    }
    system("cls");
    printf("ALTA\n\n");
    listado[indiceLugarLibre] = cargarUnAlumno();
    bandera = 1;

    return bandera;
}

void inicializarAlumnos(sAlumno listado[], int tam)
{
    int legajo[3] = {5,9,7};
    char nombre[3][21] = {"Juan", "Maria", "Luis"};
    int nota[3] = {3,9,7};
    float altura[3] = {1.7,2.0,1.6};
    char mail[3][50] = {"asd@asd.com", };

    int i;
    for(i = 0; i < 3; i++)
    {
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nombre, nombre[i]);
        listado[i].nota = nota[i];
        listado[i].altura = altura[i];
        strcpy(listado[i].mail, mail[i]);
        listado[i].estado = 1;
    }
}

int bajaDeAlumno(sAlumno listado[])
{
    int auxiliarLegajo;
    int indiceBusqueda;
    int flag;

    system("cls");
    printf("BAJA\n\n");
    mostrarListado(listado, 10);
    auxiliarLegajo = getIntOnly("\nIngrese el numero de legajo a dar de baja: ");
    indiceBusqueda = buscarPrimerOcurrenciaLegajo(listado, 10, auxiliarLegajo);
    if(indiceBusqueda == -1)
    {
        printf("No se encuentra ese legajo.\n");
        flag = 0;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listado[indiceBusqueda].estado = -1;
            flag = 1;
        }
    }
    return flag;
}

int modificacionDeAlumno(sAlumno listado[])
{
    int auxiliarLegajo;
    int indiceBusqueda;
    int auxiliarNuevaNota;
    int flag;

    system("cls");
    printf("MODIFICAR\n\n");
    mostrarListado(listado, 10);
    auxiliarLegajo = getIntOnly("\nIngrese el legajo a modificar: ");
    indiceBusqueda = buscarPrimerOcurrenciaLegajo(listado, 10, auxiliarLegajo);
    if(indiceBusqueda == -1)
    {
        printf("\nEl legajo no existe.\n");
        system("pause");
        flag = 0;
    }
    else
    {
    auxiliarNuevaNota = getInt("Ingrese la nueva nota: ");
    printf("\nEsta seguro que desea cambiar la nota?(s/n): ");
    if(getch() == 's')
    {
        listado[indiceBusqueda].nota = auxiliarNuevaNota;
        flag = 1;
    }
    }
    return flag;
}

int eGen_init( sAlumno listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].legajo= 0;
        }
    }
    return retorno;
}


int eGen_siguienteId(sAlumno listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].legajo>retorno)
                    {
                         retorno=listado[i].legajo;
                    }

            }
        }
    }

    return retorno+1;
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employees.h"
#define TEXT 51

void hardcodearEmployees(Employees array[],int* contadorID)
{
    int i;
    Employees y[]=
    {
        {1,0,"ana", "apellido1",1, 15000},
        {2,0,"luis","apellido2",2, 25000},
        {3,0,"alberto","apellido3",1, 10000},
        {4,0,"julia", "apellido4",3, 30000},
        {5,0,"julieta","apellido5",2, 23000},
        {6,0,"andrea", "apellido6",2, 31000},
        {7,0,"mauro", "apellido7", 1,27000},
    };
    for(i=0; i<7; i++)
    {
        array[i] = y[i];
        (*contadorID)++;

    }
}
/** \brief  inicializa la array en el campo .isEmpty en 1
*
* \param array Employees Array de Employees
* \param size int tamaño de array
* \return int Return (-1) si array=NULL o size<0 (0) si Ok
*
*/
int initEmployees(Employees array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief buscar en el campo isEmpty de una array la primer posicion que se encuentre vacia(1)
 * \param array Employees Array de Employees
 * \param size int tamaño de array
 * \param posicion int* puntero a la posicion que se encontro vacia
 * \return int Return (-1) si array=NULL,posicion=NULL, size<0 o no se encuntra posicion  (0) si se encuentra posicion vacia
 *
 */
int employees_buscarEmpty(Employees array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array employees Array de employees
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return return int Return (-1) si array=NULL, size<0 o no se encontro el id (0) si encontro el id
*
*/
int findEmployeeById(Employees array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array employees Array de employees
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int addEmployees(Employees array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(employees_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].id=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("Ingrese el nombre(maximo 50 carateres)\n: ","\nno valido ingrese nuevamente",1,TEXT,3,array[posicion].name);
            utn_getName("Ingrese el apellido (maximo 50 carateres)\n: ","\nno valido ingrese nuevamente",1,TEXT,3,array[posicion].lastname);
            utn_getUnsignedInt("Ingrese el sector (RRHH=1 contable=2 ventas=3)\n","\nno valido ingrese nuevamente",1,sizeof(int),1,3,3,&array[posicion].sector);
            utn_getFloat("\nIngrese el salario ","\nno valido ingrese nuevamente",1,sizeof(float),0,100000,3,&array[posicion].salary);
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sector: %d\n salario %f\n\n(sector: RRHH=1 contable=2 ventas=3)",
                   posicion, array[posicion].id,array[posicion].name,array[posicion].lastname,array[posicion].sector,array[posicion].salary);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array employees Array de employees
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int removeEmployee(Employees array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nIngrese el ID del empleado","\nID no valido (rango de ID 1-1000)",
        1,sizeof(int),1,1000,3,&id);
        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].id=0;
            strcpy(array[posicion].name,"");
            strcpy(array[posicion].lastname,"");
            array[posicion].sector=0;
            array[posicion].salary=0;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array employees Array de employees
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int modEmployees(Employees array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nID no valido",1,sizeof(int),1,sizeArray,3,&id);
        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sector: %d\n salario %f\n\n(sector: RRHH=1 contable=2 ventas=3)",
                   posicion, array[posicion].id,array[posicion].name,array[posicion].lastname,array[posicion].sector,array[posicion].salary);
                utn_getUnsignedInt("\nModificar:\n 1- Nombre\n2- Apellido\n3- Sector\n4- Salario\n 5- salir","\nopcion no valida",1,sizeof(int),1,5,3,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("Ingrese el nombre(maximo 50 carateres)\n: ","\nno valido ingrese nuevamente",1,TEXT,3,array[posicion].name);
                        break;
                    case 2:
                        utn_getName("Ingrese el apellido (maximo 50 carateres)\n: ","\nno valido ingrese nuevamente",1,TEXT,3,array[posicion].lastname);
                        break;
                    case 3:
                       utn_getUnsignedInt("Ingrese el sector (RRHH=1 contable=2 ventas=3)\n","\nno valido ingrese nuevamente",1,sizeof(int),1,3,3,&array[posicion].sector);
                        break;
                    case 4:
                        utn_getFloat("\nIngrese el salario ","\nno valido ingrese nuevamente",1,sizeof(float),0,10000,3,&array[posicion].salary);
                        break;
                }
            }while(opcion!=5);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por campo .lastname y .sector los elementos de un array
* \param array employees Array de employees
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int sortEmployees(Employees array[],int size)
{
    int retorno=-1;
    int i, j;
    Employees bufferEmployes;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferEmployes=array[i];
            j = i - 1;
            while ((j >= 0) && strcmp(bufferEmployes.lastname,array[j].lastname)<0 &&bufferEmployes.sector==array[j].sector)
            {
                array[j + 1]=array[j];
                j--;
            }
            array[j+1]=bufferEmployes;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos de un array
* \param array employees Array de employees
* \param size int Tamaño del array
* \return int Return (-1) si array=NULL o size<0 (0) si Ok
*
*/
int printEmployees(Employees array[], int size)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;
            else
            {
                 printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sector: %d\n salario %f\n\n(sector: RRHH=1 contable=2 ventas=3)",
                   posicion, array[posicion].id,array[posicion].name,array[posicion].lastname,array[posicion].sector,array[posicion].salary);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief indica promedio de salarios y catidad de perosnas que lo superan
 *
 * \param array employees Array de employees
 * \param size int Tamaño del array
 * \return int Return (-1) si array=NULL o size<0 (0) si Ok
 *
 */

int employees_informe(Employees array[], int size)
{
    float promedio;
    int acumulador,contador,i,retorno=-1;
    if(array != NULL && size >= 0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0)
            {
            acumulador=acumulador+array[i].salary;
            contador++;
            }
        }
        promedio=(float) acumulador/contador;
        contador=0;
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0 && array[i].salary>=promedio)
            {
                contador++;
            }
        }
        printf("El promedio es: %f \n La cantidad de personas que lo superan es: %d",promedio,contador);
        retorno=0;
    }
    return retorno;
}

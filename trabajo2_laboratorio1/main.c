#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employees.h"
#define LEN 1000
#define TEXT 51

int main()
{
    int option;
    int option2;
    int i,j;
    int contadorIdemployees=0;
    Employees arrayEmployees[LEN];
    initEmployees(arrayEmployees,LEN);
    hardcodearEmployees(arrayEmployees,&contadorIdemployees);

    do
    {
        i=utn_getUnsignedInt("\n\n1-Alta de empleado \n2-Modificar empleado \n3-Baja de empleado \n4-Informes\n5-Salir\n",
                      "\nEl valor ingresado no es valido ",1,sizeof(int),1,5,3,&option);
        if(i==-1)
            option=5;
        switch(option)
        {
            case 1:
                i=addEmployees(arrayEmployees,LEN,&contadorIdemployees);
                break;
            case 2:
                i=modEmployees(arrayEmployees,LEN);
                break;
            case 3:
                i=removeEmployee(arrayEmployees,LEN);
                break;
            case 4:
                i=utn_getUnsignedInt("\n\n1-Listado de Empleados\n 2-Total y promedio de los salarios y cantidad de empleados que superan el minimo\n",
                      "\nEl valor ingresado no es valido ",1,sizeof(int),1,2,3,&option2);
                switch(option2)
                {
                    case 1:
                        j=sortEmployees(arrayEmployees,LEN);
                        i=printEmployees(arrayEmployees,LEN);
                        break;
                    case 2:
                        i=employees_informe(arrayEmployees,LEN);
                        break;
                }
                break;
        }
        if(i==-1 || j == -1)
        {
            printf("Ocurrio un error, no se realizo la operacion requeriada");
        }
    }
    while(option!=5);
    return 0;
}

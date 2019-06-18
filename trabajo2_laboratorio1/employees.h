#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED
#define TEXT 51
typedef struct
{
    int id;
    int isEmpty;
    char name[TEXT];
    char lastname[TEXT];
    int sector;
    float salary;
}Employees;

void hardcodearEmployees(Employees array[],int* contadorID);
int initEmployees(Employees array[], int size);
int employees_buscarEmpty(Employees array[], int size, int* posicion);
int findEmployeeById(Employees array[], int size, int valorBuscado, int* posicion);
int addEmployees(Employees array[], int size, int* contadorID);
int removeEmployee(Employees array[], int sizeArray);
int modEmployees(Employees array[], int sizeArray);
int sortEmployees(Employees array[],int size);
int printEmployees(Employees array[], int size);
int employees_informe(Employees array[], int size);

#endif // EMPLOYEES_H_INCLUDED

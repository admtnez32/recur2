/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: MARTINEZ ALEXIS
 *      Division: 1G
 *      TP NUM 2
 */
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{

    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

}eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


void mostrarMenuOpciones(void);

void mostrarMenuModificaciones(void);

void mostrarMenuListados(void);


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE = 1 in all
* position of the array
* \param list Employee Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*free
*/
int addEmployees(eEmployee list[], int len, int* pId);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee list[], int len, int orden);

int mostrarEmpleado(eEmployee lista);

/** \brief print the content of employees array
*
* \param list Employee
* \param length int
* \return int
*
*/
int printEmployees(eEmployee list[], int len, int opcion);

/** \brief Busca array empleados libre comparando isEmpty = 1
 *
 * \param list[] eEmployee  array empleados
 * \param len int   tamanio array
 * \return int  retorna posicion libre
 *
 */
int buscarLibre(eEmployee list[], int len);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee list[], int len, int idBuscado);


/** \brief Da opcion de modificar empleado
 *  nombre, apellido, salario o sector
 * \param list[] eEmployee  array empleados
 * \param len int   tamanio
 * \return int -1 Error o 0 todo OK
 *
 */
int modificarEmpleado(eEmployee list[], int len);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee list[], int len);

/** \brief calcula cantidad de empleados dados de alta
 *
 * \param list[] eEmployee array empleados
 * \param len int   tamanio
 * \return int  retorna cantidad de empleados dados de alta
 *
 */
int calcularEmpleados(eEmployee list[], int len);

/** \brief calcula la suma de todos los salarios
 *
 * \param list[] eEmployee  array empleados
 * \param len int   tamanio array
 * \param sumaSalarios float*   puntero a int donde guardar el resultado
 * \return int  retorna 0 todoOK, -1 error
 *
 */
int calcularSalarios(eEmployee list[], int len, float* sumaSalarios);

/** \brief calcula el promedio de los salarios
 *
 * \param list[] eEmployee  array empleados
 * \param len int tamanio array
 * \param promedioSal float*    puntero a int donde guarda el resultado
 * \return int  retorna 0 todoOK, -1 error
 *
 */
int promedioSalarios(eEmployee list[], int len, float* promedioSal);

/** \brief calcula empleados con salario mayor al promedio
 *
 * \param lista[] eEmployee array empleados
 * \param tam int   tamanio array
 * \return int  retorna 0 todo OK, -1 Error
 *
 */
int empleadosSalarioPromedio(eEmployee lista[],int tam);

/** \brief  printea el promedio de salarios y cant. empleados con salario mayor al prom
 *
 * \param list[] eEmployee  array empleados
 * \param len int   tamanio array
 * \return int  retorna 0 OK, -1 ERROR
 *
 */
int mostrarPromedio(eEmployee list[], int len);

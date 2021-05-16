/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: MARTINEZ ALEXIS
 *      Division: 1G
 *      TP NUM 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funcionesPropias.h"
#include "string.h"

void mostrarMenuOpciones(void){

    printf("    ***MENU DE OPCIONES***\n\n");
    printf("    1-ALTAS (dar de alta un empleado)\n");
    printf("    2-MODIFICAR (modificar datos de un empleado)\n");
    printf("    3-BAJAS (dar de baja un empleado)\n");
    printf("    4-INFORMAR (listdo de empleados)\n");
    printf("    5-SALIR\n\n");

}

void mostrarMenuModificaciones(void){

    printf("\n    *** MODIFICAR ***\n\n");
    printf("    1-NOMBRE\n");
    printf("    2-APELLIDO\n");
    printf("    3-SALARIO\n");
    printf("    4-SECTOR\n");

}

void mostrarMenuListados(void){
    system("cls");
    printf("\n    *** listR ***\n\n");
    printf("    1-listDO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR\n");
    printf("    2-TOTAL Y PROMEDIO DE LOS SALARIOS, Y CUANTOS EMPLEADOS SUPERAN EL SALARIO PROMEDIO\n");

}

int initEmployees(eEmployee list[], int len){

    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int sortEmployees(eEmployee list[], int len, int orden){

    eEmployee auxEmpleado;

    for(int i=0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(orden){

                if(strcmpi(list[i].apellido, list[j].apellido) > 0  || (strcmpi(list[i].apellido, list[j].apellido) == 0 && list[i].sector > list[j].sector))
                {

                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                }
            }
            else if(strcmpi(list[i].apellido, list[j].apellido) < 0  || (strcmpi(list[i].apellido, list[j].apellido) == 0 && list[i].sector < list[j].sector))
            {

                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
            }
        }
    }
    return 0;
}

int addEmployees(eEmployee list[], int len, int* pId){

    eEmployee bufferEmpleado;
    int retorno = -1;
    int indice;


    if(list != NULL && len > 0 && pId != NULL){

            indice = buscarLibre(list, len);

            if(indice >=0)
            {
                system("cls");
                ale_getCaracterCadena(bufferEmpleado.nombre, sizeof(bufferEmpleado.nombre), "Ingrese su nombre: ", "");
                ale_getCaracterCadena(bufferEmpleado.apellido, sizeof(bufferEmpleado.apellido), "\nIngrese su apellido: ", "");
                ale_getFloat(&bufferEmpleado.salario, "\nIngrese sueldo: ");
                ale_getInt(&bufferEmpleado.sector, "\nIngrese sector: ");
                bufferEmpleado.id = *pId;
                bufferEmpleado.isEmpty = 0;
                list[indice] = bufferEmpleado;
                (*pId)++;
                retorno = 1;

            }
            else
            {
                printf("No hay lugar en el sistema.\n\n");
            }

    }
    return retorno;
}

int mostrarEmpleado(eEmployee list){

        printf("%d", list.id);
        printf("%10s", list.nombre);
        printf("%14s", list.apellido);
        printf("%14.2f", list.salario);
        printf("%9d", list.sector);

return 0;
}

int printEmployees(eEmployee list[], int len, int opcion){
    int retorno = -1;
    int orden;

    if(opcion == 1)
    {

        ale_getIntRango(&orden, "\nIngrese 1 para ASCENDENTE o 0 para DESCENDENTE: ", "\nError, seleccione opcion valida.\n", 0,1);
        printf("ID     NOMBRE      APELLIDO      SALARIO      SECTOR\n");
        sortEmployees(list, len, orden);// VER ORDENAMIENTO
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {

                mostrarEmpleado(list[i]);
                printf("\n");
                retorno = 0;
            }
        }
    }
    else   if(list != NULL && len > 0)
    {
        system("cls");
        printf("ID     NOMBRE      APELLIDO      SALARIO      SECTOR\n");
        sortEmployees(list, len, 1);// VER ORDENAMIENTO
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {

                mostrarEmpleado(list[i]);
                printf("\n");
            }

        }

        retorno = 0;
    }
    printf("\n\n");
    return retorno;
}

int buscarLibre(eEmployee list[], int len){

    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int findEmployeeById(eEmployee list[], int len, int idBuscado){
    int retorno = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == idBuscado)
        {
            retorno = i;
            break;
        }
    }


    return retorno;
}

int modificarEmpleado(eEmployee list[], int len){
    int retorno = -1;
    int idBuscado;
    int indice;
    int opcion;


    if(list != NULL && len > 0)
    {
        ale_getInt(&idBuscado, "Ingrese id del empleado a modificar: ");
        indice = findEmployeeById(list, len, idBuscado);
        if(indice >= 0 && list[indice].isEmpty == 0)
        {
            mostrarMenuModificaciones();
            ale_getInt(&opcion, "\nIngrese opcion: ");
            switch(opcion)
            {
                case 1:
                    ale_getCaracterCadena(list[indice].nombre, sizeof(list[indice].nombre), "Ingrese su nombre: ", "");
                    strupr(list[indice].nombre);
                    break;
                case 2:
                    ale_getCaracterCadena(list[indice].apellido, sizeof(list[indice].apellido), "\nIngrese su apellido: ", "");
                    strupr(list[indice].apellido);
                    break;
                case 3:
                    ale_getFloat(&list[indice].salario, "\nIngrese sueldo: ");
                    break;
                case 4:
                    ale_getInt(&list[indice].sector, "\nIngrese sector: ");
                    break;
            }
            printf("\n Modificacion exitosa !!\n");
            retorno = 1;
        }
        else
        {
            printf("\nNo existe ningun empleado con ese id...\n");
        }
    }
    return retorno;
}

int removeEmployee(eEmployee list[], int len){

    int retorno = -1;
    int idBuscado;
    int indice;


    if(list != NULL && len > 0)
    {
        ale_getInt(&idBuscado, "Ingrese id del empleado que quiere dar de baja: ");
        indice = findEmployeeById(list, len, idBuscado);
        if(indice >= 0 && list[indice].isEmpty == 0)
        {
            list[indice].isEmpty = 1;
            printf("\nBaja exitosa!!!\n");
            retorno = 0;
        }
        else
        {
            printf("\nNo existe ningun empleado con ese id...\n");
        }
    }
    return retorno;
}

int calcularEmpleados(eEmployee list[], int len){


    int contadorCantidad = 0;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contadorCantidad++;
            }
        }

    }

    return contadorCantidad;
}

int calcularSalarios(eEmployee list[], int len, float* sumaSalarios){

    float suma = 0;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                suma = suma + list[i].salario;
            }
        }

    }
    *sumaSalarios = suma;

    return 0;
}

int promedioSalarios(eEmployee list[], int len, float* promedioSal){

    int cantidadEmpleados = calcularEmpleados(list, len);
    float sumaSalarios;

    calcularSalarios(list, len, &sumaSalarios);

    *promedioSal = sumaSalarios / cantidadEmpleados;

return 0;
}

int empleadosSalarioPromedio(eEmployee list[],int len){

    float promedio;
    int contador = 0;

    promedioSalarios(list, len, &promedio);

    for(int i = 0; i<len; i++){

        if(list[i].salario > promedio)
        {
            contador++;
        }

    }

    printf("        %d\n\n", contador);
return contador;
}

int mostrarPromedio(eEmployee list[], int len){

    float sumaSalarios;
    float promSalarios;

    calcularSalarios(list, len, &sumaSalarios);
    promedioSalarios(list, len, &promSalarios);
    system("cls");
    printf("SALARIOS        PROMEDIO    CANT. EMP > PROM\n");
    printf("%.2f        %.2f", sumaSalarios, promSalarios);
    empleadosSalarioPromedio(list, len);


return 0;
}

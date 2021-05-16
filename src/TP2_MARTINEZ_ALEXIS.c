/*
 ============================================================================
 Name        : TP2_MARTINEZ_ALEXIS.c
 Division    : 1G
 			   TP NUM 2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "funcionesPropias.h"
#define TAM 1000


int main()
{
	setbuf(stdout, NULL);
    int nextId = 900;
    int salir = 1;
    int opcion;
    int flagAltaEmpleado = 0;
    eEmployee kiosco[TAM];

    initEmployees(kiosco, TAM);




    do
    {
        //system("cls");
        mostrarMenuOpciones();
        ale_getInt(&opcion, "Seleccione opcion: ");

        switch(opcion)
        {
        case 1:
            flagAltaEmpleado = addEmployees(kiosco, TAM, &nextId); //OK
            break;

        case 2:
            if(flagAltaEmpleado)
            {
                sortEmployees(kiosco, TAM, 1);
                printEmployees(kiosco, TAM, opcion);
                modificarEmpleado(kiosco, TAM); //OK
            }
            else
            {
                printf("\nAntes debe dar de alta un empleado.\n");
            }
            break;

        case 3:
            if(flagAltaEmpleado)
            {
                printEmployees(kiosco, TAM, opcion);
                removeEmployee(kiosco, TAM); //OK
            }
            else
            {
                printf("\nAntes debe dar de alta un empleado.\n");
            }
            break;

        case 4:
            if(flagAltaEmpleado)
            {
                mostrarMenuListados();
                ale_getIntRango(&opcion, "\nSeleccione opcion: ", "\nError, seleccione 1 0 2.\n", 1,2);

                if(opcion == 1)
                {
                    printEmployees(kiosco, TAM, opcion);
                }
                else
                {
                    mostrarPromedio(kiosco, TAM);
                }
            }
            else
            {
                printf("\nAntes debe dar de alta un empleado.\n");
            }
            break;

        case 5:
            system("cls");
            printf("\n\n    *** ADIOS ***\n");
            salir = 0;
            break;
        }
        printf("\n");
        system("pause");
    }
    while(salir);

    printf("\n\n");
    return 0;
}

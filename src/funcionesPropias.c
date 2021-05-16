/*
 * funcionesPropias.c
 *
 *  Created on: 15 may. 2021
 *      Author: MARTINEZ ALEXIS
 *      Division: 1G
 *      TP NUM 2
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcionesPropias.h"
#include "ArrayEmployees.h"


int ale_getIntRango(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo)
{

    int bufferInt;
    int retorno = -1;

    if(numero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do{
        printf("%s", mensaje);
        scanf("%d", &bufferInt);

        if(bufferInt >= minimo && bufferInt <= maximo)
        {
            *numero = bufferInt;
            retorno = 0;
        }
        else
        {
            printf("%s", mensajeError);

        }
        }while(bufferInt < minimo || bufferInt > maximo);
    }
    return retorno;
}

int ale_getInt(int* numero, char* mensaje)
{

    int bufferInt;
    int retorno = -1;

    if(mensaje != NULL && numero != NULL )
    {

        printf("%s", mensaje);
        scanf("%d", &bufferInt);
        *numero = bufferInt;
        retorno = 0;
    }
    return retorno;
}

int ale_getFloat(float* numero, char* mensaje)
{
    float bufferFloat;
    int retorno = -1;

    if(mensaje != NULL && numero != NULL )
    {
        printf("%s", mensaje);
        scanf("%f", &bufferFloat);
        *numero = bufferFloat;
        retorno = 0;
    }
    return retorno;
}

int ale_getFloatRango(float* numero, char* mensaje, char* mensajeError, float minimo, float maximo)
{

    float bufferFloat;
    int retorno = -1;

    if(numero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {

        printf("%s", mensaje);
        scanf("%f", &bufferFloat);

        if(bufferFloat >= minimo && bufferFloat <= maximo)
        {
            *numero = bufferFloat;
            retorno = 0;
        }
        else
        {
            printf("%s", mensajeError);
        }
    }
    return retorno;
}

int ale_getCaracter(char* caracter, char* mensaje, char* mensajeError)
{
    char bufferCar;
    int retorno = -1;

    if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
    {

        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &bufferCar);

        *caracter = bufferCar;
        retorno = 0;
    }
    else
    {
        printf("%s", mensajeError);
    }

    return retorno;
}

int ale_getCaracterCadena(char lista[], int tam, char* mensaje, char* mensajeError)
{
    char bufferCar[100];
    int retorno = -1;


    if(lista != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(bufferCar);

        if(strlen(bufferCar) < tam)
        {
            strcpy(lista,bufferCar);
            retorno = 0;
        }
    }


    return retorno;
}

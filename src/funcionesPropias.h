/*
 * funcionesPropias.h
 *
 *  Created on: 15 may. 2021
 *      Author: MARTINEZ ALEXIS
 *      Division: 1G
 *      TP NUM 2
 */

#ifndef FUNCIONESPROPIAS_H_
#define FUNCIONESPROPIAS_H_

int ale_getInt(int* numero, char* mensaje);
int ale_getIntRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int ale_getFloat(float* numero, char* mensaje);
int ale_getFloatRango(float* numero, char* mensaje, char* mensajeError, float minimo, float maximo);
int ale_getCaracter(char* caracter, char* mensaje, char* mensajeError);
int ale_getCaracterCadena(char lista[], int tam, char* mensaje, char* mensajeError);

#endif /* FUNCIONESPROPIAS_H_ */

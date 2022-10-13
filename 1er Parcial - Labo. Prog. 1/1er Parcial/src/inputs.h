/*
 * inputs.h
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include "vehiculo.h"

void showMenu(int* pOption);
int utn_pedirNumeroV5(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getString(char *string, int len);
int normalizarCadena(char* cadena);
//static int getIntV4(int* pResultado);
//static int myGets(char* cadena, int longitud);
//static int esNumerica(char* cadena);

#endif /* INPUTS_H_ */

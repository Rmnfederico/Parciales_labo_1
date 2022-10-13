/*
 * tipo.h
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */

#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int idTipo;
	char descripcion[31];
	int isEmpty;

}eTipo;

int inicializarTipos(eTipo array[], int size);
int hardcodearTipos(eTipo array[], int size, int elements, int* pNextId);
int validarTipo(eTipo array[], int size, int id);

void mostrarTipoFilaSinId(eTipo item);
void mostrarTipoFilaConId(eTipo item);
void mostrarTipoColumnaSinId(eTipo item);
void mostrarTipoColumnaConId(eTipo item);

int listarTipos(eTipo array[], int size);

eTipo buscarPorId(eTipo array[], int size, int id);

#endif /* TIPO_H_ */

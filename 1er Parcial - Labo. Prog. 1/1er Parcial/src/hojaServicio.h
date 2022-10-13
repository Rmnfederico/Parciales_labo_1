/*
 * hojaServicio.h
 *
 *  Created on: 6 oct. 2022
 *      Author: Pc And the boyz
 */

#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "vehiculo.h" // ---> VER SI ROMPE CUANDO FUNCIONE MODIFICAR VEHICULO

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int idHoja;
	int vehiculoId;
	char descripcion[20];
	float precioServicio;
	eFecha fechaServicio;
	int isEmpty;

}eHojaServicio;

int inicializarServicios(eHojaServicio array[], int size);
int hardcodearServicios(eHojaServicio array[], int size, int elements, int* pNextId, int* flag);

//int altaServicio(eHojaServicio array[], int size, int* pNextId, eVehiculo arrayV[], int sizeV);//
int buscarLibreServicio(eHojaServicio array[], int size);

int buscarServicio(eHojaServicio array[], int size,int id, int* pIndex);

void mostrarServicioFila(eHojaServicio item);
int listarServicios(eHojaServicio array[], int size);

#endif /* HOJASERVICIO_H_ */

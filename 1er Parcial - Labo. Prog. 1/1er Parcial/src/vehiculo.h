/*
 * vehiculo.h
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hojaServicio.h"

typedef struct
{
	int idVehiculo;
	char descripcion[20];
	int modelo;
	char color[11];
	int tipoId;
	int isEmpty;

}eVehiculo;

int inicializarVehiculos(eVehiculo array[], int size); //OK
int hardcodearVehiculos(eVehiculo array[], int size, int elements, int* pnextId, int* flag); //OK

int altaVehiculo(eVehiculo array[], int size, int* pNextId); // OK
int buscarLibre(eVehiculo array[], int size); //OK

int modificarVehiculo(eVehiculo arrayVehiculos[], int sizeV, eHojaServicio arrayServicios[], int sizeServ);//OK - REFACTOR
int serviciosPorVehiculo(eVehiculo arrayVehiculos[], int sizeV, eHojaServicio arrayServicios[], int sizeServ, int idVehiculo);
int buscarVehiculo(eVehiculo array[], int size,int id, int* pIndex);//OK
int eliminarVehiculo(eVehiculo array[], int size);

void mostrarVehiculoColumna(eVehiculo item); //OK
void mostrarVehiculoFila(eVehiculo item); //OK
int listarVehiculos(eVehiculo array[], int size); //OK

#endif /* VEHICULO_H_ */

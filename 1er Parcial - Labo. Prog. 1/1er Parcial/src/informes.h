/*
 * informes.h
 *
 *  Created on: 12 oct. 2022
 *      Author: Pc And the boyz
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "vehiculo.h"
#include "tipo.h"
//#include "hojaServicio.h"

int mostrarVehiculosXTipo(eVehiculo arrayVehiculos[], int tamV, eTipo arrayTipos[], int tamT);
int mostrarServiciosXFecha(eHojaServicio array[], int size);
int mostrarImporteTotalServiciosParaUnVehiculo(eVehiculo arrayVehiculos[], int tamV, eHojaServicio arrayServicios[], int tamServ, float* acumulador);
int mostrarImporteTotalServiciosXTipoXFecha(eHojaServicio arrayServicios[], int tamServ, eTipo arrayTipos[], int tamTipos, float* acumulador);


#endif /* INFORMES_H_ */

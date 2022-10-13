/*
 ============================================================================
 Name        : 1er Parcial.c
 Author      : Federico Roman
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Primer Parcial Labo 1E - Taller Mecanico
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "vehiculo.h"
#include "tipo.h"
#include "informes.h"

#define TAM_V 10
#define TAM_T 3
#define TAM_S 10

int main(void)
{
	setbuf(stdout, NULL);

	///Arranca la locomotora del sabor
	int idVehiculos = 1;
	int idTipos = 1000;
	int idServicios = 20000;

	eVehiculo arrayVehiculos[TAM_V];
	eTipo arrayTipos[TAM_T];
	eHojaServicio arrayServicios[TAM_S];

	int flagVehiculosCargados = 0;
	int flagServiciosCargados = 0;
	float acumulador;

	inicializarVehiculos(arrayVehiculos, TAM_V);
	hardcodearVehiculos(arrayVehiculos, TAM_V, 4, &idVehiculos, &flagVehiculosCargados);

	inicializarTipos(arrayTipos, TAM_T);
	hardcodearTipos(arrayTipos, TAM_T, 3, &idTipos);

	inicializarServicios(arrayServicios, TAM_S);
	hardcodearServicios(arrayServicios, TAM_S, 5, &idServicios, &flagServiciosCargados);


	int option;
	 do{

			printf("\t\n\n ***** Bienvenido al Menu del Taller Mecanico *****\n\n"
				   "¿Que accion desea realizar?\n\n"
				   "1-ALTA de un Vehiculo\n"
				   "2-MODIFICAR un Vehiculo\n"
				   "3-BAJA de un Vehiculo\n"
				   "4-Listar Vehiculos\n"
				   "5-Listar Tipos\n"
				   "6-ALTA de una hoja de servicio\n"
	               "7-Listar Hojas de Servicio\n"
				   "\nINFORMES:\n"
					"8-Mostrar vehiculos por tipo\n"
					"9-Mostrar servicios por fecha\n"
					"10-Informar importe total de las hojas de servicios para un vehiculo\n"
					"11-Informar importe total de todas las hojas de servicio de un tipo en una fecha seleccionada\n"
				   "8-Salir\n");

					printf("\nSu opcion:");
			        scanf("%d",&option);

		switch(option)
		{

			case 1:
				if(altaVehiculo(arrayVehiculos, TAM_V, &idVehiculos))
				{
					printf("\nVehiculo cargado con exito.\n");
					flagVehiculosCargados = 1;
				}
				break;

			case 2:
				if(flagVehiculosCargados)
				{
					modificarVehiculo(arrayVehiculos, TAM_V, arrayServicios, TAM_S);
				}else
				{
					printf("No hay vehiculos o servicios para modificar.\n");
				}

				break;

			case 3:
				if(flagVehiculosCargados)
				{
					eliminarVehiculo(arrayVehiculos, TAM_V);
				}else
				{
					printf("No hay vehiculos para eliminar.\n");
				}
				break;

			case 4:
				listarVehiculos(arrayVehiculos, TAM_V);
				break;

			case 5:
				listarTipos(arrayTipos , TAM_T);
				break;

			case 6:
				altaServicio(arrayServicios, TAM_S, &idServicios , arrayVehiculos, TAM_V);
			    break;

			case 7:
				listarServicios(arrayServicios, TAM_S);
			    break;
			case 8:
				mostrarVehiculosXTipo(arrayVehiculos, TAM_V, arrayTipos, TAM_T);
				break;
			case 9:
				mostrarServiciosXFecha(arrayServicios, TAM_S);
				break;
			case 10:
				mostrarImporteTotalServiciosParaUnVehiculo(arrayVehiculos, TAM_V, arrayServicios, TAM_S, &acumulador);
				printf("\nImporte total para el vehiculo seleccionado:%.2f\n", acumulador);
				break;
			case 11:
				break;
			case 12:
				break;
			}

		}while(option != 12);
	    printf("\nHa salido del menu.\n");

	return EXIT_SUCCESS;
}

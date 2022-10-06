/*
 * inputs.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */
#include "inputs.h"

void showMenu(int* pOption)
{

    do{

		printf("\t ***** Bienvenido al Menu del Taller Mecanico *****\n\n"
			   "¿Que accion desea realizar?\n\n"
			   "1-ALTA de un Vehiculo\n"
			   "2-BAJA de un Vehiculo\n"
			   "3-MODIFICAR un Vehiculo\n"
			   "4-Listar Vehiculos\n"
			   "5-Listar Tipos\n"
               "6-Listar Hojas de Servicio\n"
			   "7-Salir\n");

				printf("\nSu opcion:");
		        scanf("%d",pOption);

	switch(*pOption)
	{

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
		    break;

		case 7:
		    break;
		}

	}while(*pOption != 7);
    printf("\nHa salido del menu.\n");

}



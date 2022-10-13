/*
 * informes.c
 *
 *  Created on: 12 oct. 2022
 *      Author: Pc And the boyz
 */

#include "informes.h"

int mostrarVehiculosXTipo(eVehiculo arrayVehiculos[], int tamV, eTipo arrayTipos[], int tamT)
{
	int retorno = 0;

	if(arrayVehiculos != NULL && tamV > 0 && arrayTipos != NULL && tamT > 0)
	{
		int auxIdTipo;
		eTipo auxTipo;

		listarTipos(arrayTipos, tamT);
		printf("Ingrese el ID del tipo a listar:");
		scanf("%d", &auxIdTipo); // USAR VALIDACIONES_UTN

		auxTipo = buscarPorId(arrayTipos, tamT, auxIdTipo);

		printf("\nVehiculos encontrados para el tipo %s:\n", auxTipo.descripcion);
		for(int i =0; i<tamT; i++)
		{
			if(arrayVehiculos[i].tipoId == auxIdTipo)
			{
				mostrarVehiculoFila(arrayVehiculos[i]);
			}
		}
		retorno = 1;
	}

	return retorno;
}

int mostrarServiciosXFecha(eHojaServicio array[], int size)
{
	int retorno = 0;
	eFecha auxFecha;

	if(array != NULL && size >0)
	{
		printf("Ingrese la fecha a buscar:\n");
		printf("Mes:");
		scanf("%d", &auxFecha.mes);

		printf("Dia:");
		scanf("%d", &auxFecha.dia);

		printf("Anio:");
		scanf("%d", &auxFecha.anio);

		printf("\nServicios realizados en la fecha %d/%d/%d:\n",auxFecha.dia,auxFecha.mes,auxFecha.anio);
		for(int i = 0; i<size; i++)
		{
			if(array[i].fechaServicio.dia == auxFecha.dia && array[i].fechaServicio.mes == auxFecha.mes && array[i].fechaServicio.anio == auxFecha.anio)
			{
				mostrarServicioFila(array[i]);
			}
		}
		retorno = 1;
	}

	return retorno;

}

int mostrarImporteTotalServiciosParaUnVehiculo(eVehiculo arrayVehiculos[], int tamV, eHojaServicio arrayServicios[], int tamServ, float* acumulador)
{
	int retorno = 0;
	*acumulador = 0;
	int auxIdVehiculo;
	int indiceV;

	if(arrayVehiculos != NULL && tamV > 0 && arrayServicios != NULL && tamServ > 0 && acumulador != NULL)
	{
		listarVehiculos(arrayVehiculos, tamV);
		printf("Ingrese el ID del vehiculo para calcular el total de servicios:");
		scanf("%d", &auxIdVehiculo);

		if(buscarVehiculo(arrayVehiculos, tamV, auxIdVehiculo, &indiceV))
		{
			if(indiceV == -1)
			{
				printf("No existe un vehiculo con id %d en el sistema.\n", auxIdVehiculo);
			}else
			{
				for(int i=0; i<tamServ; i++)
				{
					if(arrayServicios[i].vehiculoId == auxIdVehiculo)
					{
						*acumulador += arrayServicios[i].precioServicio;
						retorno = 1;
					}
				}
			}
		}

	}


	return retorno;
}

int mostrarImporteTotalServiciosXTipoXFecha(eHojaServicio arrayServicios[], int tamServ, eTipo arrayTipos[], int tamTipos, float* acumulador)
{
	int retorno = 0;

	if(arrayServicios != NULL && tamServ > 0 && arrayTipos != NULL && tamTipos > 0 && acumulador != NULL)
	{

	}

	return retorno;
}


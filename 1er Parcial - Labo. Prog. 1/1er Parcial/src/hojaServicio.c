/*
 * hojaServicio.c
 *
 *  Created on: 6 oct. 2022
 *      Author: Pc And the boyz
 */

#include "hojaServicio.h"

int inicializarServicios(eHojaServicio array[], int size)
{
    int retorno = 0;

    if(array != NULL && size > 0)
    {
    	for(int i = 0; i < size; i++)
    	{

    		array[i].isEmpty = 0;
    	}
    	retorno = 1;
    }
    return retorno;
}

int hardcodearServicios(eHojaServicio array[], int size, int elements, int* pNextId, int* flag)
{
	int retorno = 0;
		if(array != NULL && size > 0 && elements <= size && elements > 0)
		{

			eHojaServicio auxArray[5] = {{0,1,"Balanceo",150.5,{9,9,9},1},
									{0,2,"Balanceo",150.5,{9,9,9},1},
									{0,3,"Balanceo",150.5,{9,9,9},1},
									{0,3,"Balanceo",150.5,{9,9,9},1},
									{0,2,"Balanceo",150.5,{9,9,9},1}};

			for(int i= 0; i<elements; i++)
			{
				array[i] = auxArray[i];
				array[i].idHoja = *pNextId;
				(*pNextId)++;
			}
			retorno = 1;
			*flag = 1;
		}
		return retorno;
}

void mostrarServicioFila(eHojaServicio item)
{
	printf("|  %d %8d %18s %12.2f %10d/%d/%d  |\n", item.idHoja,
													item.vehiculoId,
													item.descripcion,
													item.precioServicio,
													item.fechaServicio.dia,
													item.fechaServicio.mes,
													item.fechaServicio.anio);
}

int listarServicios(eHojaServicio array[], int size)
{
	int retorno = -1;
	if(array != NULL && size > 0)
	{
		printf("             ***** Listado de Vehiculos *****\n");
		printf("\n--------------------------------------------------------------------\n");
		printf("|    ID    |  Vehiculo    |     Descripcion    |  Precio  |  Fecha |\n");
		printf("|------------------------------------------------------------------\n");
		for(int i = 0; i<size; i++)
		{
			if(array[i].isEmpty)
			{
				mostrarServicioFila(array[i]);
			}

		}
		printf("|------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}

int buscarServicio(eHojaServicio array[], int size,int id, int* pIndex)
{
	int retorno = 0;

	if(array != NULL && size > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i = 0; i<size; i++)
		{
			if(array[i].isEmpty && array[i].idHoja == id)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

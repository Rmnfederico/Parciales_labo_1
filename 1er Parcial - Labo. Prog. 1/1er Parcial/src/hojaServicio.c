/*
 * hojaServicio.c
 *
 *  Created on: 6 oct. 2022
 *      Author: Pc And the boyz
 */

#include "inputs.h"
#include "vehiculo.h"

int altaServicio(eHojaServicio array[], int size, int* pNextId, eVehiculo arrayV[], int sizeV);

//////////////////////////////////////////////////////////

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
									{0,2,"Chapa",150.5,{9,9,9},1},
									{0,3,"Pintura",150.5,{9,9,9},1},
									{0,3,"Balanceo",150.5,{9,9,8},1},
									{0,2,"Distribucion",150.5,{9,9,8},1}};

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

int buscarLibreServicio(eHojaServicio array[], int size)
{
	int retorno = -1;

	if(array != NULL && size > 0)
	{
		for(int i= 0; i < size; i++)
		{
			if(array[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaServicio(eHojaServicio array[], int size, int* pNextId, eVehiculo arrayV[], int sizeV)
{
	int retorno = 0;
	int indice;
	int auxId;
	int indiceV;

	eHojaServicio auxServicio;

	if(array != NULL && size > 0)
	{
		indice = buscarLibreServicio(array, size);

		if(indice == -1)
		{
			printf("No hay lugar disponible.\n");
		}else
		{
			printf("     *** Alta de Servicio ***     \n\n");

			auxServicio.idHoja = *pNextId;

			listarVehiculos(arrayV, sizeV);
			printf("Ingrese el id del vehiculo:");
			scanf("%d", &auxId);

			//VALIDAR QUE NO SE PUEDA SEGUIR EL ALTA SI NO EXISTE EL ID DEL VEHICULO
			if(buscarVehiculo(arrayV, sizeV, auxId, &indiceV))
			{
				if(indiceV == -1)
				{
					printf("No existe un vehiculo con id %d en el sistema.\n", auxId);
				}else
				{
					auxServicio.vehiculoId = auxId;
				}
			}

			printf("Ingrese la descripcion del servicio:");
			//CAMBIAR NOMBRE/ VERIFICAR RETORNO & ARMAR IF QUE AVISE SI GUARDO O NO
			//getString(auxServicio.descripcion, strlen(auxServicio.descripcion));
			fflush(stdin);
			fgets(auxServicio.descripcion, 20,stdin);
			normalizarCadena(auxServicio.descripcion);

			printf("Ingrese el precio del servicio:");
			scanf("%f", &auxServicio.precioServicio);

			//FUNCION VALIDAR FECHA
			printf("Ingrese la fecha del servicio:\n");
			printf("Mes:");
			scanf("%d", &auxServicio.fechaServicio.mes);

			printf("Dia:");
			scanf("%d", &auxServicio.fechaServicio.dia);

			printf("Anio:");
			scanf("%d", &auxServicio.fechaServicio.anio);

			auxServicio.isEmpty = 1;

			array[indice] = auxServicio;

			(*pNextId)++;
			retorno = 1;
		}
	}

	return retorno;
}

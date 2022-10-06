/*
 * tipo.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */
#include "tipo.h"


int inicializarTipos(eTipo array[], int size)
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

int hardcodearTipos(eTipo array[], int size, int elements, int* pNextId)
{
	int retorno = 0;
	if(array != NULL && size > 0 && elements <= size && elements > 0)
	{

		eTipo auxArray[3] = {{0,"Sedan (3 puertas)", 1},
								{0,"Sedan (5 puertas)", 1},
								{0,"Camioneta", 1}};


		for(int i= 0; i<elements; i++)
		{
			array[i] = auxArray[i];
			array[i].idTipo = *pNextId;
			(*pNextId)++;
		}
		retorno = 1;
	}
	return retorno;
}

void mostrarTipoFilaConId(eTipo item)
{
	printf("  %4d %24s\n", item.idTipo, item.descripcion);
}

int listarTipos(eTipo array[], int size)
{
	int retorno = -1;
	if(array != NULL && size > 0)
	{
		printf("\n|  ID     |     Descripcion     |\n");
		for(int i= 0; i<size; i++)
		{
			if(array[i].isEmpty == 1)
			{
				mostrarTipoFilaConId(array[i]);
			}
		}
		retorno = 0;
	}
	return retorno;
}

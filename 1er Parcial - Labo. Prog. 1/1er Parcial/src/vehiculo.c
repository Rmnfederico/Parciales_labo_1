/*
 * vehiculo.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */

#include "vehiculo.h"
#include "hojaServicio.h"

int inicializarVehiculos(eVehiculo array[], int size)
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

int hardcodearVehiculos(eVehiculo array[], int size, int elements,int* pNextId, int* flag)
{
	int retorno = 0;
	if(array != NULL && size > 0 && elements <= size && elements > 0)
	{

		eVehiculo auxArray[5] = {{0,"Auto 1",1990,"azul",1000,1},
								{0,"Auto 2",1990,"rojo",1001,1},
								{0,"Auto 3",1990,"verde",1002,1},
								{0,"Auto 4",1990,"negro",1003,1},
								{0,"Auto 5",1990,"gris",1004,1}};

		for(int i= 0; i<elements; i++)
		{
			array[i] = auxArray[i];
			array[i].idVehiculo = *pNextId;
			(*pNextId)++;
		}
		retorno = 1;
		*flag = 1;
	}
	return retorno;
}

int buscarLibre(eVehiculo array[], int size)
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

int altaVehiculo(eVehiculo array[], int size, int* pNextId)
{
	int retorno = 0;
	int indice;
	//int idTipo;
	eVehiculo auxVehiculo;

	if(array != NULL && pNextId != NULL && size > 0)
	{
		indice = buscarLibre(array, size);

		if(indice == -1)
		{
			printf("No hay lugar disponible.\n");
		}else
		{
			printf("     *** Alta de Vehiculo ***     \n\n");

			auxVehiculo.idVehiculo = *pNextId;
			printf("\nIngrese descripcion:");
			fflush(stdin);
			fgets(auxVehiculo.descripcion,20,stdin);
			normalizarCadena(auxVehiculo.descripcion);

			printf("\nIngrese el modelo:");
			scanf("%d", &auxVehiculo.modelo);

			printf("\nIngrese el color:");
			fflush(stdin);
			fgets(auxVehiculo.color,20,stdin);
			normalizarCadena(auxVehiculo.color);

			printf("Ingrese el tipo:");
			scanf("%d", &auxVehiculo.tipoId);
			//LISTAR TIPOS Y ELEGIR POR OPCION, VALIDAR CON BIBLIOTECA UTN

			auxVehiculo.isEmpty = 1;
			array[indice] = auxVehiculo;

			(*pNextId)++;
			retorno = 1;
		}
	}

	return retorno;
}

//////////////////////
void mostrarVehiculoColumna(eVehiculo item)
{
    printf("\nDescripcion: %s", item.descripcion);
    printf("\nModelo: %d", item.modelo);
    printf("\nColor: %s", item.color);
    printf("\nTipo: %d\n", item.tipoId);
}

void mostrarVehiculoFila(eVehiculo item)
{
	printf("|  %d %16s %18d %12s %10d  |\n", item.idVehiculo, item.descripcion,item.modelo,item.color,item.tipoId);
}

int listarVehiculos(eVehiculo array[], int size)
{
	int retorno = -1;
	if(array != NULL && size > 0)
	{
		printf("             ***** Listado de Vehiculos *****\n");
		printf("\n--------------------------------------------------------------------\n");
		printf("|    ID    |  Descripcion    |     Modelo    |  Color  |  ID Tipo |\n");
		printf("|------------------------------------------------------------------\n");
		for(int i = 0; i<size; i++)
		{
			if(array[i].isEmpty)
			{
				mostrarVehiculoFila(array[i]);
			}

		}
		printf("|------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}

int buscarVehiculo(eVehiculo array[], int size,int id, int* pIndex)
{
	int retorno = 0;

	if(array != NULL && size > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i = 0; i<size; i++)
		{
			if(array[i].isEmpty && array[i].idVehiculo == id)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

int menuModificarVehiculo()
{
	int opcion;
	printf("  *** Que desea modificar?: ***\n\n");
	printf("1. Descripcion\n");
	printf("2. Precio de servicio\n");
	printf("3. Salir sin modificar\n");
	printf("\nIngrese su opcion:");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int serviciosPorVehiculo(eVehiculo arrayVehiculos[], int sizeV, eHojaServicio arrayServicios[], int sizeServ, int idVehiculo)
{
	int retorno = -1;
	if(arrayVehiculos != NULL && sizeV > 0 && arrayServicios != NULL && sizeServ > 0)
	{
		for(int i=0; i<sizeV; i++) //SERVICIOS
		{
			if(arrayServicios[i].vehiculoId == idVehiculo)
			{
				mostrarServicioFila(arrayServicios[i]);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int modificarVehiculo(eVehiculo arrayVehiculos[], int sizeV, eHojaServicio arrayServicios[], int sizeServ)
{
	int retorno = -1;
	int id;
	int indice;
	char auxDescripcion[20];
	int idServicio;
	int indexServicio;
	float precioServicio;


	if(arrayVehiculos != NULL && sizeV > 0 && arrayServicios != NULL && sizeServ > 0)
	{
		listarVehiculos(arrayVehiculos, sizeV);
		printf("  Seleccione el ID del vehiculo a modificar:\n");
		scanf("%d", &id);


		if(buscarVehiculo(arrayVehiculos, sizeV, id, &indice))
		{
			if(indice == -1)
			{
				printf("No existe un vehiculo con id %d en el sistema.\n", id);
			}else
			{
				//Func mostrarEncabezado() --> IMPLEMENTAR
				printf("\n--------------------------------------------------------------------\n");
				printf("|    ID    |  Descripcion    |     Modelo    |  Color  |  ID Tipo |\n");
				printf("|------------------------------------------------------------------\n");
				mostrarVehiculoFila(arrayVehiculos[indice]);

				switch(menuModificarVehiculo())
				{
				case 1:
					printf("Ingrese nueva descripcion:");
					fflush(stdin);
					fgets(auxDescripcion, 20, stdin);
					//validar descripcion
					strcpy(arrayVehiculos[indice].descripcion, auxDescripcion);
					printf("Descripcion modificada con exito.\n");
					retorno = 0;
					break;
				case 2:
					if(serviciosPorVehiculo(arrayVehiculos, sizeV, arrayServicios, sizeServ, id) != 0)
					{
						printf("Este vehiculo no tiene servicios asociados.\n");
					}

					printf("Ingrese ID del servicio para modificar su precio.\n");
					scanf("%d", &idServicio);
					if(buscarServicio(arrayServicios , sizeServ, idServicio, &indexServicio))
					{
						if(indexServicio == -1)
						{
							printf("No existe un Servicio con id %d en el sistema.\n", idServicio);
						}else
						{
							printf("Ingrese el nuevo precio del servicio:");
							scanf("%f", &precioServicio);
							//validar precio antes de guardar en la struct
							arrayServicios[indexServicio].precioServicio = precioServicio;
							printf("\nPrecio modificado con exito.\n");
							retorno = 0;
						}
					}

					break;
				default:
					printf("Opcion incorrecta, modificacion cancelada.\n");
					break;
				}
			}
		}
	}

	return retorno;
}

int eliminarVehiculo(eVehiculo array[], int size)
{
	int retorno = 0;
	int indice;
	int id;
	char confirmacion;

	if(array != NULL && size > 0)
	{
		listarVehiculos(array, size);
		printf("Ingrese el id:");
		scanf("%d", &id);

		if(buscarVehiculo(array, size, id, &indice))
		{
			if(indice == -1)
			{
				printf("No existe un vehiculo con id %d en el sistema.\n", id);
			}else
			{
				printf("\n--------------------------------------------------------------------\n");
				printf("|    ID    |  Descripcion    |     Modelo    |  Color  |  ID Tipo |\n");
				printf("|------------------------------------------------------------------\n");
				mostrarVehiculoFila( array[indice]);
				printf("Confirmar eliminacion? (s/S = SI)");
				fflush(stdin);
				scanf("%c", &confirmacion);

				if(confirmacion == 's' || confirmacion == 'S')
				{
					array[indice].isEmpty = 0;
					printf("Eliminacion exitosa.\n");
				}else
				{
					printf("Eliminacion cancelada.\n");
				}
			}
			retorno = 1;
		}
	}

	return retorno;
}

int buscarIdMayor(eVehiculo array[], int size)
{
	int mayor;
	if(array != NULL && size > 0)
	{
		for(int i = 0; i<size; i++)
		{
			if(i == 0 || array[i].idVehiculo > mayor)
			{
				mayor = array[i].idVehiculo;
			}
		}
	}

	return mayor;
}

int buscarIdMenor(eVehiculo array[], int size)
{
	int menor;
	if(array != NULL && size > 0)
	{
		for(int i = 0; i<size; i++)
		{
			if(i == 0 || array[i].idVehiculo < menor)
			{
				menor = array[i].idVehiculo;
			}
		}
	}
	return menor;
}

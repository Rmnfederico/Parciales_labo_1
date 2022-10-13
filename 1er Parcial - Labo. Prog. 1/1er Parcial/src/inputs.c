/*
 * inputs.c
 *
 *  Created on: 5 oct. 2022
 *      Author: Pc And the boyz
 */
#include "inputs.h"

static int getIntV4(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);

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

int utn_pedirNumeroV5(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;

    while(reintentos>0)
    {
        reintentos --;
        printf("%s", mensaje);

        if(getIntV4(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }

        }

        printf("%sIntentos restantes: %d\n\n", mensajeError, reintentos);
    }
    if(retorno != 0)
    {
        printf("Numero de intentos agotado.\n");
    }

    return retorno;
}

/////////////// Funcion getInt() Ver.4 (FINAL) con myGets() & esNumerica() --> NORMALIZA EL '\n' a traves de myGets()
static int getIntV4(int* pResultado)
{
    int ret=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
          if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            ret = 0;
        }
    }


    return ret;
}

static int myGets(char* cadena, int longitud)
{
    int retorno=-1;
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
    	fflush(stdin);
        //fflush(stdin); // fflush o __fpurge
        if(cadena[strlen(cadena) -1] == '\n')
        {
            cadena[strlen(cadena) -1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}

static int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int getString(char *string, int len)
{
	int retorno = -1;
	char bufferString[64];

	if (string != NULL && len > 0)
	{
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(string, bufferString, len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int normalizarCadena(char* cadena)
{
    int retorno = -1;
    if(cadena != NULL)
    {
        if(cadena[strlen(cadena) -1] == '\n')
        {
            cadena[strlen(cadena) -1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}

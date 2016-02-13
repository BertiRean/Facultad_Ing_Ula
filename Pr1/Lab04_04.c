/*
	LABORATORIO 4
	PRACTICA CICLOS
	CICLO REPITA MIENTRAS

	AUTOR: ELADIO DAPENA Y ANTONIO BERTI
*/

/*
	PROGRAMA PARA OBTENER EL PROMEDIO DE 10 NOTAS INTRODUCIDAS POR UN USUARIO
*/

#include <stdio.h>

int main()
{
	int cant = 0 , nota[10], suma = 0;
	float promedio;
	//REPITA MIENTRAS
	printf("Introduzca la nota (-1 para terminar): ");
	scanf("%d",&nota[cant]);
	while (nota[cant] != -1)
	{
		if(nota[cant] <= 0 || nota[cant] > 20) // Validacion de la nota
		{
			printf("La nota introducida no es valida\n");
			printf("Introduzca la nota (-1 para terminar): ");
			scanf("%d",&nota[cant]);
		}
		else
		{
			suma += nota[cant]; //suma = suma + nota
			cant++; //cant = cant + 1
			if(cant == 10) // Aqui valido que solo me introduzca un maximo de 10 notas que validas
			{
				break;
			}
			printf("Introduzca la nota (-1 para terminar): ");
			scanf("%d",&nota[cant]);
		}

	}
	 //leimos el valor de parada -1
	promedio = (float)suma/cant;
	printf("Promedio: %5.2f\n",promedio);
	return 0;
}
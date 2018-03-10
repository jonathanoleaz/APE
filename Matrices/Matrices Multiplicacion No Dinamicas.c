#include <stdio.h>
#include <stdlib.h>
#include <conio.h>								//PARA matriz M2, SE USAN AL REVES FILAS Y COLUMNAS, (POR CUESTIONES DE MATEMATICA)
int **M1;
int **M2; 
int **M3;
int filas,columnas;

int main()
{
	int M1[5][3];
	int M2[3][5];
	int M3[5][5];
	int i,j,k,result,save;		
	filas=5;
	columnas=3;
	srand(time(NULL));
	if(filas>columnas) save=filas;
	else save=columnas;
	
	result=filas;
	
	for(i=0;i<filas;i++)		
		for(j=0;j<columnas;j++)
		{
		M1[i][j]=rand()%10;	
		M2[j][i]=rand()%10;	
		}
	
	for(i=0;i<result;i++)
		for(j=0;j<result;j++)
		M3[i][j]=0;	
	
	printf("Matriz 1:\n");
	for(i=0;i<filas;i++)
		{
		for(j=0;j<columnas;j++)
		printf("%d\t",M1[i][j]);
		printf("\n");			
	}
	
	printf("Matriz 2:\n");
	for(i=0;i<columnas;i++)
		{
		for(j=0;j<filas;j++)
		printf("%d\t",M2[i][j]);
		printf("\n");			
	}
	
	for(i=0;i<filas;i++)
		for(j=0;j<save;j++)						//Este debe ser el mayor numero, de entre columnnas o filas, sino hace solo una columna para el caso 3,1
			for(k=0;k<columnas;k++)
			{
			M3[i][j]+=M1[i][k]*M2[k][j];
		}
		
	printf("Matriz 3:\n");
	for(i=0;i<result;i++)
		{
		for(j=0;j<result;j++)
		printf("%d\t",M3[i][j]);
		printf("\n");			
	}
	
	getch();
	
		
}

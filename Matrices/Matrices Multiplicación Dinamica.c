#include <stdio.h>
#include <stdlib.h>
#include <conio.h>								//PARA matriz M2, SE USAN AL REVES FILAS Y COLUMNAS, (POR CUESTIONES DE MATEMATICA)
int **M1;
int **M2; 
int **M3;
int filas,columnas;

int main()
{
	int i,j,k,result,save;
	srand(time(NULL));		
	printf("Filas para A: "); scanf("%d",&filas);
	printf("Columnas para A: "); scanf("%d",&columnas);
	if(filas>columnas) save=filas;
	else save=columnas;
	
	result=filas;
	
	M1=(int **)malloc(filas*sizeof(int*));				//Asignacion dinámica para las matrices. malloc guarda memoria segun el tamaño de bits en entero de filas
	M2=(int **)malloc(columnas*sizeof(int*));			//PARA M2 EL ACCESO ES AL REVES (PARA LAS FILAS Y COLUMNAS)
	M3=(int **)malloc(result*sizeof(int*));
	if (M1==NULL || M2==NULL || M3==NULL)
	{
		printf("Sin reserva de memoria");
		exit(1);
	}
	
	for(i=0; i<filas; i++)
		M1[i]=(int*)malloc(columnas*sizeof(int*));			//Ahora, cada vector tiene un arreglo de punteros
	
	for(i=0; i<columnas; i++)
	M2[i]=(int*)malloc(filas*sizeof(int*));
	
	for(i=0; i<result; i++)
	M3[i]=(int*)malloc(result*sizeof(int*));
	
	
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

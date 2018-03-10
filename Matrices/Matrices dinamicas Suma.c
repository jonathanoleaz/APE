#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int sumsubst (int **M1, int **M2, int filas, int columnas)
{
	int **M3;
	int **M4;
	int i,j;
	M3=(int **)malloc(filas*sizeof(int*));				//Asignacion dinámica para las matrices
	M4=(int **)malloc(filas*sizeof(int*));
	if (M3==NULL || M4==NULL)
	{
		printf("Sin reserva de memoria");
		exit(1);
	}
	
	for(i=0; i<filas; i++)
	{
		M3[i]=(int*)malloc(columnas*sizeof(int*));
		M4[i]=(int*)malloc(columnas*sizeof(int*));
		if (M3==NULL || M4==NULL)
		{
			printf("Sin reserva de memoria");
			exit(1);
		}
	}
	
	///
	printf("Suma:\n");
	for (i=0;i<filas;i++)
	{
		for(j=0;j<columnas;j++)
		{
		M3[i][j]=M1[i][j]+M2[i][j];
		printf("%d\t",M3[i][j]);
		M4[i][j]=M1[i][j]-M2[i][j];	
		}
		printf("\n");
	}
	printf("Resta:\n");
	for (i=0;i<filas;i++)
	{
		for(j=0;j<columnas;j++)
		{
		printf("%d\t",M4[i][j]);	
		}
		printf("\n");
	}
	
}
int main()
{
	int i,j,filas,columnas;
	int **M1;
	int **M2;
	srand(time(NULL));
	printf("Filas: "); scanf("%d",&filas);
	printf("Columnas: "); scanf("%d",&columnas);
	
	M1=(int **)malloc(filas*sizeof(int*));				//Asignacion dinámica para las matrices
	M2=(int **)malloc(filas*sizeof(int*));
	if (M1==NULL || M2==NULL)
	{
		printf("Sin reserva de memoria");
		exit(1);
	}
	
	for(i=0; i<filas; i++)
	{
		M1[i]=(int*)malloc(columnas*sizeof(int*));
		M2[i]=(int*)malloc(columnas*sizeof(int*));
		if (M1==NULL || M2==NULL)
		{
			printf("Sin reserva de memoria");
			exit(1);
		}
	}
	
	for(i=0;i<filas;i++)
		{
		for(j=0;j<columnas;j++)
		{
		M1[i][j]=rand()%10;	
		M2[i][j]=rand()%10;	
		}
		}
	printf("Matriz 1:\n");
	for(i=0;i<filas;i++)
		{
		for(j=0;j<columnas;j++)
		printf("%d\t",M1[i][j]);
		printf("\n");			
	}
	
	printf("Matriz 2:\n");
	for(i=0;i<filas;i++)
		{
		for(j=0;j<columnas;j++)
		printf("%d\t",M2[i][j]);
		printf("\n");			
	}
	sumsubst(M1,M2,filas,columnas);	
	
	getch();
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int sumsubst (int m1[5][5], int m2[5][5])
{
	int m3[5][5];
	int m4[5][5];
	int i,j;
	printf("Suma:\n");
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		m3[i][j]=m1[i][j]+m2[i][j];
		printf("%d\t",m3[i][j]);
		m4[i][j]=m1[i][j]-m2[i][j];	
		}
		printf("\n");
	}
	printf("Resta:\n");
	for (i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%d\t",m4[i][j]);	
		}
		printf("\n");
	}
	return m3;
	return m4;
	
}
int main()
{
	int i,j,acum;
	int M1[5][5];
	int M2[5][5];
	srand(time(NULL));
	for(i=0;i<5;i++)
		{
		for(j=0;j<5;j++)
		{
		M1[i][j]=rand()%10;	
		M2[i][j]=rand()%10;	
		}
		}
	printf("Matriz 1:\n");
	for(i=0;i<5;i++)
		{
		for(j=0;j<5;j++)
		printf("%d\t",M1[i][j]);
		printf("\n");			
	}
	
	printf("Matriz 2:\n");
	for(i=0;i<5;i++)
		{
		for(j=0;j<5;j++)
		printf("%d\t",M2[i][j]);
		printf("\n");			
	}
	sumsubst(M1,M2);
	
	getch();	
}

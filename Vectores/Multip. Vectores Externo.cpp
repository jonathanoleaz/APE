#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Producto externo    		Transpuesta
int main()
{
	
	int m[4][4]; 		//[filas][columnas]
	int r1[]={1,2,3,4};
	int r2[]={4,3,2,1};
	int i,j;
	
	for(i=0;i<4;i++)				//Fila por fila, y despues columna por columna
		for(j=0;j<4;j++)
	{
		m[i][j]=r1[j]*r2[i];
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		printf("%d\t",m[i][j]);
		printf("\n");
	}
   getch();
	return 0;

	
}

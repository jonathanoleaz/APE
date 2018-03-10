#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int determinante(int **M, int n) 	//La otra dimension se pasa con un apuntador, o un doble apuntador ..HW=Suma resta y multiplicacion de matrices
{
	int i,j,k,s,l,r=0;
	int **M1;

	M1=(int**)malloc(5*sizeof(int*));
	//int M1[5][5];//pasar a puntero con malloc
	for(i=0; i<5; i++)
		M1[i]=(int*)malloc(5*sizeof(int*));
	
	if(n==1)
	return M[0][0];
	
	for(i=0;i<n;i++)
	{
		s=(i%2==0)?1:-1;
		for(j=1;j<n;j++)
		{
		l=0;
			for(k=0;k<n;k++)
			{
			if(k!=i)							//Las filas las da k
			{
				M1[j-1][l++]=M[j][k];			//La matriz M es la que entra	
				//printf("\t%d",M[j][k]);
			}
			//printf("\n");
			}
		}
		
		s*=determinante(M1,n-1);
		//printf("S: %d",s);
		
		r*=s;
		//printf("R= %d",r);
	}
	return r;
}

int main()
{
	//int M[5][5];
	int i,j,r;
	int **M;
	srand(time(NULL));
	M=(int**)malloc(5*sizeof(int*));
	for(i=0; i<5; i++)
		M[i]=(int*)malloc(5*sizeof(int*));
		
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		M[i][j]=rand()%10;
		printf("%d\t",M[i][j]);
	}
	M[0][0]=100;	
	printf("\n");
	}
		
	r=determinante(M,5);
	printf("r=%d",r);
	getch();
	return 0;
	
}
	

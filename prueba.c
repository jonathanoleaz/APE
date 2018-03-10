#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
double Det(double **M, int n)
{
	double r,a;
	double **Mc;
	double *Salv;  //Para salvar en caso de haber division sobre 0, el vector que lo contiene y traslaparlos
	int i, j, k, l;
	
	Mc=(double **)malloc(n*sizeof(double*));
	Salv=(double *)malloc(n*sizeof(double*));
	
	for(i=0; i<n; i++)
	{
		Mc[i]=(double *)malloc(n*sizeof(double));
	for(j=0; j<n; j++)
		Mc[i][j]=M[i][j];
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Mc[i][i]==0)
			{
				for(l=0;l<n;l++)
				{
				Salv[l]=Mc[i][l];			//Se salva la fila i
				Mc[i][l]=Mc[j][l];  		//Se intercambian las filas
				Mc[j][l]=Salv[l];
				}		
			}
			a=Mc[j][i]/Mc[i][i];//Revisar para esto
			for(k=i;k<n;k++)
			Mc[j][k]-=a*Mc[i][k];
		}
		}
	for(i=n-1;i>0;i--)
	{
		for(j=n;j>i+1;j--)
		{
			if(Mc[i][i]==0)
			{
				for(l=0;l<n;l++)
				{
				Salv[l]=Mc[i][l];			//Se salva la fila i
				Mc[i][l]=Mc[j][l];  		//Se intercambian las filas
				Mc[j][l]=Salv[l];
				}		
			}
			a=Mc[j][i]/Mc[i][i];//Revisar para esto
			for(k=i;k<n;k++)
			Mc[j][k]-=a*Mc[i][k];
		}
		}
	r=1;
	for(i=0;i<n;i++)
	r*=Mc[i][i];
	
	printf("Matriz resultado:\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		printf("%.2f\t",Mc[i][j]);
	}
	printf("\n");
	}
	printf("%.3f",r);
	
	for(i=0;i<n;i++)	 
	free(Mc[i]);
	//free[Mc];
	return r;
}


int main()
{
	int i,j,n,gr;
	int count=1;
	double **M;
	printf("Tamaño de la matriz(cuadrada): "); scanf("%d",&n);
	M=(double**)malloc(n*sizeof(double*));
	for(i=0;i<n+1;i++)
	{
		M[i]=(double *)malloc(n*sizeof(double*));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++,count++)
		{
		printf("Valor para [%d][%d]: ",i,j); scanf("%d",&gr);
		M[i][j]=(double)gr;
	}
	printf("\n");
	}
	
	Det(M,n);
		
	getch();
	return 0;
}


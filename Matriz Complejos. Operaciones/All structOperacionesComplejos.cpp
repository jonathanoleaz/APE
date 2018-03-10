#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

struct complejo
{
	double real; 
	double imag;
};
typedef complejo Complejo;//para no estar ponenindo struct cada que se llaama a esta estructura

struct matriz
{
	complejo **M;
	int n;
	int m;	
};

typedef matriz Matriz;

//nos devuelve una matriz con el tamano que le digamos
Matriz nueva(int n, int m)
{
	int i,j;
	Matriz r;//la matriz que se devolverá
	r.m=m;
	r.n=n;
	r.M=(Complejo**)malloc(n*sizeof(Complejo*));				//el tamaño de complejo es de 12 bits  4 DEL APUNTADOR MAS LOS 8 DE LOS 2 INT
	for(i=0; i<n; i++)
	{
		r.M[i]=(Complejo*)malloc(m*sizeof(Complejo));
		for(j=0;j<m;j++)
		{
			r.M[i][j].real=0;
			r.M[i][j].imag=0;
	}
	}
	return r;
}

Matriz rand(int n, int m)
{
	int i,j;
	srand(time(NULL));
	Matriz r;//la matriz que se devolverá
	r.m=m;
	r.n=n;
	r.M=(Complejo**)malloc(n*sizeof(Complejo*));				//el tamaño de complejo es de 12 bits  4 DEL APUNTADOR MAS LOS 8 DE LOS 2 INT
	for(i=0; i<n; i++)
	{
		r.M[i]=(Complejo*)malloc(m*sizeof(Complejo));
		for(j=0;j<m;j++)
		{
			r.M[i][j].real=rand()%(5-1+1)+5;
			r.M[i][j].imag=rand()%(5-1+1)+5;
	}
	}
	return r;
}
Matriz rand2(int n, int m)
{
	int i,j;
	srand(time(NULL));
	Matriz r;//la matriz que se devolverá
	r.m=m;
	r.n=n;
	r.M=(Complejo**)malloc(n*sizeof(Complejo*));				//el tamaño de complejo es de 12 bits  4 DEL APUNTADOR MAS LOS 8 DE LOS 2 INT
	for(i=0; i<n; i++)
	{
		r.M[i]=(Complejo*)malloc(m*sizeof(Complejo));
		for(j=0;j<m;j++)
		{
			r.M[i][j].real=rand()%(10-5+1)+5;
			r.M[i][j].imag=rand()%(10-5+1)+5;
	}
	}
	return r;
}


Matriz notrand(int n, int m)
{
	int i,j;
	srand(time(NULL));
	Matriz r;//la matriz que se devolverá
	r.m=m;
	r.n=n;
	r.M=(Complejo**)malloc(n*sizeof(Complejo*));				//el tamaño de complejo es de 12 bits  4 DEL APUNTADOR MAS LOS 8 DE LOS 2 INT
	for(i=0; i<n; i++)
	{
		r.M[i]=(Complejo*)malloc(m*sizeof(Complejo));
		for(j=0;j<m;j++)
		{
			printf("En [%d][%d]:",i,j); scanf("%lf",&r.M[i][j].real); 
			printf("En [%d][%d]img:",i,j); scanf("%lf",&r.M[i][j].imag); 
			//r.M[i][j].real=rand()%10;
			//r.M[i][j].imag=rand()%10;
	}
	}
	return r;
}

void print(Matriz A,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A.M[i][j].imag>=0)
			printf("%.2lf+%.2lfi\t", A.M[i][j].real,A.M[i][j].imag); //CHECAR POR SI EN RESTA DA UN IMAGINARIO NEGATIVO, NO PONGA +-
			else printf("%.2lf %.2lfi\t", A.M[i][j].real,A.M[i][j].imag);
		}
		printf("\n");
	}
}

Complejo suma(Complejo a, Complejo b)
{
	Complejo c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}
Complejo resta(Complejo a, Complejo b)
{
	Complejo c;
	c.real=a.real-b.real;
	c.imag=a.imag-b.imag;
	return c;
}
Complejo multiplica(Complejo a, Complejo b)
{
	Complejo c;
	c.real=a.real*b.real-a.imag*b.imag;
	c.imag=a.real*b.imag+a.imag*b.real;
	return c;
}

Complejo divide(Complejo a, Complejo b)
{
	Complejo c;
	c.real=(a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
	c.imag=(a.real*b.imag-a.imag*b.real)/(b.real*b.real+b.imag*b.imag);
	return c;
}

Matriz sumaM(Matriz A, Matriz B)
{
	int i,j;
	Matriz C;
	C.M=NULL;
	if(A.n==B.n && A.m==B.m)
	{
		C=nueva(A.n,A.m);
		for(i=0; i<A.n; i++)
		{
			for(j=0; j<A.m; j++)
			{
				C.M[i][j].real=A.M[i][j].real+B.M[i][j].real;//Asi si se quisiera sumar directamente
				
				C.M[i][j]=suma(A.M[i][j],B.M[i][j]);//Asi solo se pasa el elelmetno matriz de la estructura $CHECK$
			}
		}
	}
	return C;
}
Matriz restaM(Matriz A, Matriz B)
{
	int i,j;
	Matriz C;
	C.M=NULL;
	if(A.n==B.n && A.m==B.m)
	{
		C=nueva(A.n,A.m);
		for(i=0; i<A.n; i++)
		{
			for(j=0; j<A.m; j++)
			{
				C.M[i][j].real=A.M[i][j].real+B.M[i][j].real;//Asi si se quisiera sumar directamente
				
				C.M[i][j]=resta(A.M[i][j],B.M[i][j]);//Asi solo se pasa el elelmetno matriz de la estructura $CHECK$
			}
		}
	}
	return C;
}
Matriz multiplicaM(Matriz A, Matriz B)
{
	int i,j,k;
	Matriz C;
	C.M=NULL;
	if(A.n==B.n && A.m==B.m)
	{
		C=nueva(A.n,A.m);
		/*for(i=0; i<A.n; i++)   --LA MULTIPLICACION NO ES DIRECTA, COMO EN LA SUMA Y RESTA--
		{
			for(j=0; j<A.m; j++)
			{
				C.M[i][j]=multiplica(A.M[i][j],B.M[i][j]);//Asi solo se pasa el elelmetno matriz de la estructura $CHECK$
			}
		}*/
		//C.M[i][j].real=A.M[i][j].real+B.M[i][j].real;
		for(i=0;i<A.n;i++)
		for(j=0;j<A.m;j++)						//Este debe ser el mayor numero, de entre columnnas o filas, sino hace solo una columna para el caso 3,1
			for(k=0;k<A.m;k++)
			{
			C.M[i][j].real=(A.M[i][j].real*B.M[i][j].real-A.M[i][j].imag*B.M[i][j].imag)+C.M[i][j].real;
			C.M[i][j].imag=(A.M[i][j].real*B.M[i][j].imag+A.M[i][j].imag*B.M[i][j].real)+C.M[i][j].imag;
			//c.real=a.real*b.real-a.imag*b.imag;
			//c.imag=a.real*b.imag+a.imag*b.real;
		}
	}
	return C;
}
Matriz divideEscalar(Matriz A, Complejo escalar)
{
	int i,j;		//rad2 es para el control de los matriz.imag
	Matriz C;
	C.M=NULL;
		C=nueva(A.n,A.m);
		for(i=0;i<A.n;i++)
		for(j=0;j<A.m;j++)
		{
			C.M[i][j].real=(A.M[i][j].real*escalar.real+A.M[i][j].imag*escalar.imag)/(escalar.real*escalar.real+escalar.imag*escalar.imag);
			C.M[i][j].imag=(A.M[i][j].real*escalar.imag-A.M[i][j].imag*escalar.real)/(escalar.real*escalar.real+escalar.imag*escalar.imag);
		}		
	return C;
}
Matriz multiplicaEscalar(Matriz A, Complejo escalar)
{
	int i,j;		//rad2 es para el control de los matriz.imag
	Matriz C;
	C.M=NULL;
		C=nueva(A.n,A.m);
		for(i=0;i<A.n;i++)
		for(j=0;j<A.m;j++)
		{
			C.M[i][j].real=(A.M[i][j].real*escalar.real-A.M[i][j].imag*escalar.imag);
			C.M[i][j].imag=(A.M[i][j].real*escalar.imag+A.M[i][j].imag*escalar.real);	
		}		
	return C;
}

void borrar(Matriz A)
{
	int i;
	if(A.m!=NULL)
	for(i=0;i<A.n;i++)
		free(A.M[i]);
	free(A.M);
}

int main()
{
	Matriz A,B,C,D,E,F,G,H,I;
	Complejo escalar;
	int n,i,j;
	int resp;
	
	printf("Ingrese tamaño de matriz: "); scanf("%d",&n);
	printf("Ingreso de elementos: \n"); 
	printf("1.-Aleatorio. \n2.-Por el usuario. \n");
	printf("Seleccione: "); scanf("%d",&resp);
	switch(resp)
	{
		case 1:
				A=rand(n,n);
				B=rand(n,n);
				escalar.real=rand()%10;
				escalar.imag=rand()%10;
				break;
		case 2:
				printf("Valores para matriz A:\n");
				A=notrand(n,n);
				printf("Valores para matriz B:\n");
				B=notrand(n,n);
				printf("Valor real para el escalar: "); scanf("%lf",&escalar.real);
				printf("Valor imag. para el escalar: "); scanf("%lf",&escalar.imag);
				break;
		default:
				printf("Opción no valida, debe ser 1 o 2");	
	}
	
	A=rand(n,n);
	B=rand2(n,n);
	C=sumaM(A,B);
	D=multiplicaM(A,B);
	E=restaM(A,B);
	F=divideEscalar(A,escalar);
	G=divideEscalar(B,escalar);
	H=multiplicaEscalar(A,escalar);
	I=multiplicaEscalar(B,escalar);
	
	printf("Escalar: \n %.3f+%.3fi\n",escalar.real,escalar.imag );
	printf("Matriz A: \n");
	print(A,n);
	printf("\nMatriz B: \n");
	print(B,n);
	printf("\nSuma: \n");
	print(C,n);
	printf("\nResta: \n");
	print(E,n);
	printf("\nMultiplicaci\242n de matrices A B: \n");
	print(D,n);
	printf("\nDivisi\242n A entre escalar: \n");
	print(F,n);
	printf("\nDivisi\242n B entre escalar: \n");
	print(G,n);
	printf("\nMultiplicaci\242n A por escalar: \n");
	print(H,n);
	printf("\nMultiplicaci\242n B por escalar: \n");
	print(I,n);
	borrar(A);
	borrar(B);
	borrar(C);
	borrar(D);
	borrar(E);
	borrar(F);

	getch();
	return 0;
}

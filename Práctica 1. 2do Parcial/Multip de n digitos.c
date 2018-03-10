#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char x[101], y[101], z[201], q[200];
	int i,j,k,carry,m, n=100;
	
	printf("Ingresar numero de digitos: "); scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		x[i]=rand()%10+48;
		y[i]=rand()%10+48;
	}
	
	for(i=0; i<n*2; i++)
	{
		z[i]=0;
		q[i]=0;
	}
	for (i=n-1; i>=0; i--)		//j recorre x[]
	{
		carry=0;
		for(j=i+n+1; j<n*2; j++) //se llenan con ceros a la derecha
		q[j]=0;
		
		for(j=n-1,k=i+n; j>=0; j--,k--)   //k para saber donde se van dejando los digitos de la multiplicacion
		{
			m=(y[i]-48)*(x[j]-48)+carry;
			carry=m/10;
			q[k]=m%10;					//Para mostrar, sumarle 48
		}
		q[k]=carry;
		carry=0;
		
		for(j=n*2-1; j>=0; j--)
		{
			m=q[j]+z[j]+carry;
			carry=m/10;
			z[j]=m%10;
		}
	}
	for(i=0; i<n*2; i++)
	z[i]+=48;
	
	z[n*2]=0;
	x[n]=0;
	y[n]=0;
	
	
	printf("\n x=%s", x);
	printf("\n y=%s", y);
	printf("\n z=%s", z);
	
	getch();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
//Producto de vectores interno(punto)
int main()
{
	double r1[]={9,7,2};
	double r2[]={1,7,5};
	double r3[3];
	double esc=0;
	int i;
	
	for(i=0; i<3; i++)
	{
	r3[i]=r1[i]*r2[i];
	esc+=r3[i];
	}
		
	printf("r3=(");
	for(i=0; i<2; i++)
	 printf("%.2lf,",r3[i]);
	 
	printf("%.2lf)",r3[i]);
	
	printf("\n %.2lf",esc);
	
	return 0;
}

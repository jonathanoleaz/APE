#include <stdio.h>
#include <conio.h>

int main()
{
	int a,b,r,z,s,t;
	
	printf("a,b="); scanf("%d,%d",&a,&b);
	s=a;
	t=b;
	while (b>0)								//Z solo sirve para ir guadando       					[30,18]
	{											//
	z=b;										//En Z guardo b. 										En Z<---18
	b=a%b;										//El residuo lo guardo en a, ahora dividirá				En A<---12
	a=z;										//Ahora en b guardo el valor de Z para la sig. div.		En B<---	
	}
	
	
	r=(s/a)*t;
	printf("mcm=%d",r);
	printf("\nMCD=%d",a);

   getch();

   return 0;
}

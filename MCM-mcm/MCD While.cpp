#include <stdio.h>
#include <conio.h>

int main()
{
	int a,b,z;
	
	printf("a,b="); scanf("%d,%d",&a,&b);
	
	while (b>0)								//Z solo sirve para ir guadando       					[30,18]
	{											//
	z=b;										//En Z guardo b. 										En Z<---18
	b=a%b;										//El residuo lo guardo en a, ahora dividirá				En A<---12
	a=z;										//Ahora en b guardo el valor de Z para la sig. div.		En B<---	
	}
	printf("MCD=%d",a);

	
	
	getch ();
	
	return 0;
}

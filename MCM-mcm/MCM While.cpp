#include<conio.h>
#include<stdio.h>

int mcd(int a, int b)
{
	int z;
	
	while (b>0)								//Z solo sirve para ir guadando       					[30,18]					2da.
	{											//
	z=b;										//En Z guardo b. 										En Z<---18			Z-->18
	b=a%b;									//El residuo lo guardo en a, ahora dividirá				En A<---12         	a-->6 (Viene del residuo b%a
	a=z;										//Ahora en b guardo el valor de Z para la sig. div.		En B<---18			b-->18		
	}
	return a;
}
int main()
{
	int a,b;
	printf("a,b="); scanf("%d,%d",&a,&b);
	
	printf("MCM=%d",(a*b)/mcd(a,b));

	
	getch();

	return 0;
	
}

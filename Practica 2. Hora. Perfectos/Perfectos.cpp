#include<stdio.h>
#include<conio.h>

int main ()
{

	unsigned long long num, i, j, acum;
	printf("N="); scanf("%d",&num); 
	
	for (i=2; i<=num; i=i+2)			//NOTA: Se sutituyo el incremento en 1 por 2, ya que los perfectos estan incluidos en los pares, 
	{									//		
		//printf("\n%d",i);
		acum=0;
		for (j=1;j<i;j++)
		{
			if(i%j==0)
			acum=acum+j;
		}
		if(i==acum)
		printf("\n %d",i);
	}
	printf("\n --->Terminado");
	//getch();
	return 0;
}

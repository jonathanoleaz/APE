#include<stdio.h>
#include<conio.h>

void funcion (int t, int base)
{
	int r;
	if (t==0)
	return;
	
	r=t%base;
	funcion (t/base,base);
	printf("%c",(r<10)?48+r:55+r);  							//? es un if, expresado de otra forma, donde (condicion)?instruccion_A_ejecutar:instruccionSinoSeCumpleCondicion
	
	
}

int main ()
{
	int x,y;
	printf("Num. a convertir: "); scanf("%d",&x);
	printf("\nEn base: "); scanf("%d",&y);
	if (y<2)
	{
		printf("\Base no valida");
		return 0;
	}
	funcion(x,y);
	getch();
	return 0;
}

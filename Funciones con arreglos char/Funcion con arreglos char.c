#include <stdio.h>
#include <conio.h>

double f(double x)
{
	double r;
	r=x;
	return r;
}

int main()
{
	char cad[25][81];   //Tipo de dato, nombre variable, SOLO es una dimension porque es char
	int i,j;
	double x,y;
	for (i=0; i<25; i++)			//lectura de cadenas
	{
		for(j=0;j<80;j++)
		cad[i][j]=' ';
		cad[i][80]=0;
	}	
	
	j=0;
	for (x=-5; j<80; x+=(1/8.0))		//Debe ponerse el .0 al ocho para que sea division entre int/float y resulte un flotante (double)
	{
		y=f(x);
		i=12-y;
		cad[i][j++]='.';
	}
	
	for (i=0; i<25;i++)	
	puts(cad[i]);
	
}

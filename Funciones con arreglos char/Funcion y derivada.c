#include <stdio.h>
#include <conio.h>
#include <math.h>

double f(double x)
{
	double r;
	r=sin(x);
	return r;
}
double derivada(double x)
{
	double h=0.000000000001;
	double r;
	r=(f(x+h)-f(x))/h;
	return r;
}
int main()
{
	char cad[25][80];
	int i,j;
	double x,y,amp=10,a,b;
	for(i=0;i<25;i++)
	{
		for(j=0;j<79;j++)
		cad[i][j]=' ';
		cad[i][79]=0;
	}
	a=-2*M_PI;
	b= 2*M_PI;
	for(j=0,x=a;j<79;j++,x+=(b-a)/80)
	{
		y=f(x);
		y=12-amp*y;
		if((y-(int)y)>=0.5)
		  i=y+1;
		  else
		  i=y;
		if(i>=0 && i<25)
		cad[i][j]='*';
	}
	for(j=0,x=a;j<79;j++,x+=(b-a)/80)
	{
		y=derivada(x);
		y=12-amp*y;
		if((y-(int)y)>=0.5)
		  i=y+1;
		  else
		  i=y;
		if(i>=0 && i<25)
		cad[i][j]='0';
	}
	for(i=0;i<25;i++)
	   puts(cad[i]);
	
	getch();
	return 0;
}

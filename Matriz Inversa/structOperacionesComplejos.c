#include <stdio.h>
#include <conio.h>
#include <time.h>

struct complejo
{
	double real;
	double imag;
};
typedef struct complejo Complejo;


//funcion que regresa numero complejo
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

int main()
{
	Complejo a,b,c,d,e,f;
	double *send;
	a.real=0.0;
	a.imag=0.0;
	b.real=0.0;
	b.imag=0.0;
	printf("Ingrese valores para a:\n");
	printf("Real:");	scanf("%lf",&a.real);
	printf("\nImag:");	scanf("%lf",&a.imag);
	printf("Ingrese valores para b:\n");
	printf("\nReal:");	scanf("%lf",&b.real);
	printf("\nImag:");	scanf("%lf",&b.imag);
	
	c=suma(a,b);
	printf("Suma: \nc= %.3f+%.3fi",c.real,c.imag);
	f=resta(a,b);
	printf("\nResta: \nc= %.3f+%.3fi",f.real,f.imag);
	d=multiplica(a,b);
	printf("\nProducto: \nd= %.3f+%.3fi",d.real,d.imag);
	e=divide(a,b);
	printf("\nCociente: \nd= %.3f+%.3fi",e.real,e.imag);
	getch();
	return 0;
}

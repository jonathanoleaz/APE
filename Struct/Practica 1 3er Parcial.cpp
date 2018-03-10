/*pedir numero de personas. ordenar por lo que quiera el userb (nombre,telefono,escuela) (usar algoritmo de ordenación). menu
usar switch
leer
mostrar*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct persona
{
	char nombre[20];
	char paterno[20];
	char materno[20];
	char telefono[10];
	char dir[100];
};
typedef persona Persona;

Persona* ingreso(int n)
{
	int i;
	Persona *p;
	
	p=(Persona *)malloc(n*sizeof(Persona));
	
	for(i=0;i<n;i++)
	{
	printf("Persona %d \n",i+1);
	 fflush(stdin);
	printf("Nombre: "); gets(p[i].nombre); 
	printf("Materno: "); gets(p[i].paterno);
	printf("Paterno: "); gets(p[i].materno);
	printf("Telefono: "); gets(p[i].telefono);
	printf("Direccion: "); gets(p[i].dir);
	}
return p;	
}

void prints(Persona *p, int n)
{
	int i;
	printf("Nombre\tPaterno\tMaterno\tTelefono\tDireccion\n");
	for(i=0;i<n;i++)
	{
		fputs(p[i].nombre, stdout);printf("\t");
		fputs(p[i].paterno, stdout);printf("\t");
		fputs(p[i].materno, stdout);printf("\t");
		fputs(p[i].telefono, stdout);printf("\t");
		fputs(p[i].dir, stdout);
		printf("\n");
		
	}
}

int mayor(char *a, char *b, int len)//devuelve 1 si la cadena es mayor
{
	int r=1,i=0,j=0;
	
	while(*a==*b)
	{
		if(*a=='\0')
		return 0;
		a++;
		b++;
	}
	
//	for(i=0; i<a[i]!=0; i++)
//		if(a[i]<b[i])
//		{
//			r=0;
//			break;
//		}
		
		
return (*a-*b);
}
//////Ordenamiento de burbuja
void ordenarNombre(Persona *p, int n, int opcion)
{
	int i,j, flag;
	Persona a;
	for(i=0; i<n-1; i++)   //for(i=0; i<n-1; i++) yes
		for(j=i+1; j<n; j++)
		{
			switch(opcion)
			{
				case 1: flag=mayor(p[i].nombre,p[j].nombre, 20); break;
				case 2: flag=mayor(p[i].paterno,p[j].paterno, 20); break;
				case 3: flag=mayor(p[i].materno,p[j].materno, 20); break;
				case 4: flag=mayor(p[i].telefono,p[j].telefono, 20); break;
				case 5: flag=mayor(p[i].dir,p[j].dir, 20); break;
				default:printf("Opcion invalida\n");
			}
			//flag=mayor(p[i].nombre,p[j].nombre, 20);
			if(flag>0)
			{
				a=p[i];
				p[i]=p[j];
				p[j]=a;	
			}
		}	
			
	prints(p,n);
}

int main()
{
int i,j,n,opcion;
char answer;
Persona *p;

printf("Ingrese numero de personas a registrar: "); scanf("%d",&n);

p=ingreso(n);
prints(p,n);

do{
	printf("\nOrdenar por: \n1.-Nombre\n2.-Paterno\n3.-Materno\n4.-Telefono\n5.-Direccion\n");
	printf("Elija alguna opción: "); scanf("%d",&opcion);
	ordenarNombre(p,n,opcion);
	
	fflush(stdin);
printf("\n \168Desea seguir ordenando? (S)"); scanf("%c",&answer);

}while(answer=='S' || answer=='s');
 
 
 getch();
} 

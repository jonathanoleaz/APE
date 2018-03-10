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
	printf("->Persona %d \n",i+1);
	 fflush(stdin);
	printf("Nombre: "); gets(p[i].nombre); 
	printf("Materno: "); gets(p[i].paterno);
	printf("Paterno: "); gets(p[i].materno);
	printf("Telefono: "); gets(p[i].telefono);
	printf("Direccion: "); gets(p[i].dir);
	}
return p;	
}

void printfile(FILE *f, Persona a)
{
	fprintf(f,"%s;%s;%s;%s;%s\n", a.nombre, a.paterno, a.materno, a.telefono, a.dir);
}

void prints(Persona *p, int n)
{
	int i;
	FILE *f1;
	
	f1=fopen("registro.txt","a");
	printf("Nombre\tPaterno\tMaterno\tTelefono\tDireccion\n");
	for(i=0;i<n;i++)
	{
		fputs(p[i].nombre, stdout);printf("\t");
		fputs(p[i].paterno, stdout);printf("\t");
		fputs(p[i].materno, stdout);printf("\t");
		fputs(p[i].telefono, stdout);printf("\t");
		fputs(p[i].dir, stdout);
		printf("\n");
		printfile(f1, p[i]);	
	}
	fclose(f1);
}

void prints2(Persona *p, int n)//Imprimir una vez leida la struct desde el txt
{
	int i;
	FILE *f1;
	f1=fopen("registro22.txt","a");
	printf("Nombre\tPaterno\tMaterno\tTelefono\tDireccion\n");
	for(i=0;i<n;i++)
	{
		fputs(p[i].nombre, stdout);printf("\t");
		fputs(p[i].paterno, stdout);printf("\t");
		fputs(p[i].materno, stdout);printf("\t");
		fputs(p[i].telefono, stdout);printf("\t");
		fputs(p[i].dir, stdout);
		
		printfile(f1, p[i]);	
	}
	fclose(f1);
}

void prints3(Persona *p, int n)//Imprimir una vez leida la struct desde el txt
{
	int i;
	FILE *f1;
	f1=fopen("registro.txt","a");
	printf("Nombre\tPaterno\tMaterno\tTelefono\tDireccion\n");
	for(i=0;i<n;i++)
	{
		fputs(p[i].nombre, stdout);printf("\t");
		fputs(p[i].paterno, stdout);printf("\t");
		fputs(p[i].materno, stdout);printf("\t");
		fputs(p[i].telefono, stdout);printf("\t");
		fputs(p[i].dir, stdout);
		printf("\n"); 
		printfile(f1, p[i]);	
	}
	fclose(f1);
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
		
return (*a-*b);
}
//////Ordenamiento de burbuja
void ordenarNombre(Persona *p, int n, int opcion)
{
	int i,j, flag;
	Persona a;
	for(i=0; i<n-1; i++)   
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

			if(flag>0)
			{
				a=p[i];
				p[i]=p[j];
				p[j]=a;	
			}
		}			
	prints3(p,n);
}
void printallUsers()//este modulo primero revisa cuantos usuarios hay en el archivo txt, para despues asignarle memoria al arreglo del struct
{
	FILE *f1;
	char band;
	char personaCortar[200];
	int n=0;
	int i,k=0;
	char *token;//para cortar la cadena
	Persona *p;
	
	f1=fopen("registro.txt","r");
	while(!feof(f1))
	{
		band=fgetc(f1);
		if(band=='\n') n++;	
	}
	fclose(f1);								//Se cierra, para despues volver a leerlo
	printf("Numero de usuarios: %d \n",n);
	
	f1=fopen("registro.txt","r");
	
	p=(Persona *)malloc(n*sizeof(Persona));
	for(i=0; i<n; i++)
	{
		fgets(personaCortar, 200, f1);
		
		token = strtok(personaCortar , ";"); /*Separamos por espacios*/ 
        while (token != NULL)
		{
			//printf("El token es:  %s\n", token);
            if(k==0) strcpy(p[i].nombre, token);
            if(k==1) strcpy(p[i].paterno, token);
            if(k==2) strcpy(p[i].materno, token);
            if(k==3) strcpy(p[i].telefono, token);
            if(k==4) strcpy(p[i].dir, token);
            token = strtok(NULL,";");
            k++;
        }	
        k=0;
		//puts(personaCortar);				
	}
	fclose(f1);
	prints2(p,n);
}

int main()
{
int i,j,n,opcion;
int f;
char answer;

Persona *p;
Persona *q;

printf("Ingrese numero de personas a registrar: "); scanf("%d",&n);

p=ingreso(n);
//---->>>>>prints(p,n);

do{
	printf("\nOrdenar por: \n  1.-Nombre\n  2.-Paterno\n  3.-Materno\n  4.-Telefono\n  5.-Direccion\n\n6.-Ver anteriores\n7.-Insertar nuevo(s) registros\n");
	printf("Elija alguna opción: "); scanf("%d",&opcion);
	if(opcion<=5)
	ordenarNombre(p,n,opcion);
	else if(opcion==6)
	printallUsers();
	if(opcion==7)
	{
		printf("Ingrese numero de personas a registrar: "); scanf("%d",&f);
		q=ingreso(f);	
		ordenarNombre(q,f,opcion);
	}
	fflush(stdin);
	
printf("\n \168Desea seguir ordenando? (S)"); scanf("%c",&answer);

}while(answer=='S' || answer=='s');
 
 
 getch();
} 

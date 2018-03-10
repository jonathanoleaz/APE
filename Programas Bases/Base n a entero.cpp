#include<stdio.h>
#include<conio.h>
#include<math.h>

int funciondigitos (int base)
{
 	int t, r, digito, cont=0, pot, sum=0;
	printf("Num. a convertir: "); scanf("%d",&t);
	
	if (t==0)
	return 0;
	
	while(t>0)
	{
	
	digito=t%10;										//Entre 10 porque solo lo quiero usar para dividir en digitos
	t=t/10;
	 
	if (digito>base)
	{
	printf("Invalido: algun digito es mayor a la base");
	return 0;
    }
						
	pot=digito*pow(base,cont);
	sum=sum+pot;
	cont=cont+1;
    }
	
	printf(" ED: %d",sum);
	return sum;
}

int funcionchar (int base)
{
	int t, r,digito, cont=0, pot, sum=0, i, j=-1, k;
	char cad[20];
	printf("Num. a convertir: "); 
	scanf("%s",cad);
	
	while (cad[++j]!=0);
	
	j-=1;													//j me guardo el valor de la longoitud de la cadena sin tomar en cuenta en 0,		
	if (t==0)
	return 0;
	
	for(i=0;cad[i]!=0;i++)										//for(j;cad[j]!=0;j--)
	{
		
	if (cad[i]>=65 && cad[i]<=90)
	k=cad[i]-55;
	else if (cad[i]>=48 && cad[i]<=57)
	k=cad[i]-38;
	
	if (k>base)
	{
	printf("Invalido: algun digito es mayor a la base");
	return 0;
    } 

							
	pot=k*pow(base,j);

	sum=sum+pot;
	j--;
    }

	return sum;
}

int main ()
{
	int x,y,n;
	
	printf("\nBase del num.: "); scanf("%d",&y);
	if (y<2)
	{
		printf("\nBase no valida");
		return 0;
	}
	if (y==10)
	printf("Este programa convierte a base 10.");
	else if (y>=2 && y<10)
	printf("\n Numero en base 10= %d",funciondigitos(y));
	else if (y>10 && y<=36)
	printf("\n Numero en base 10= %d",funcionchar(y));
		
	getch();
	return 0;
}

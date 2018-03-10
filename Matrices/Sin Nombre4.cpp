#include <stdio.h>
#include <stdlib.h>

void diamond(int n);
int main(){	
	int n;
	FILE* archivo;
	
	printf("Ingrese n (par): "); scanf("%d",&n);
	while(n%2 && n<100){
	printf("N debe ser par y menor que 100: ->");
	scanf("%d",&n);
	}

	diamond(n/2);
	
	return 0;
}

void diamond(int n){
	int i,j, flag=0;
	for(i=0; i<n; i++){
	printf("\n");
	flag=0;
		for(j=0; j<n*2; j++){
			if((i==0 || i==n-1) && j==n/2 )
				printf("*");
			else
			if((i==0 || i==n-1) && j==n+(n/2) )
				printf("?");
			else
			
			if( (j==(n/2)+i || j==(n/2)-i || j==(-n/2)+i || j==(n+(n/2))-i-1)   && j<n && i<n)
				printf("~");	
			else
			
			if( (j==n+(n/2)+i || j==n+(n/2)-i )   && j>=n) 
			{ 
				flag=1;
				printf("+");
			}	
			else
			if((j==n+(-n/2)+i || j==n+(n+(n/2))-i-1)  && j>=n)
			{
				flag=1;
				printf(".");
			}
			else 
			if(flag==1 && j<n+(n+(n/2))-i-1 && j<n+((n/2)+i))
			{ 
				printf("2");
			}
			else
			{
			printf(" ");
			}		
		}
	}	
}

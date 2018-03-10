#include <stdio.h>
#include <stdlib.h>

void ord(int arr[], int tam, int a, int b)	//a y b son los limites para hacer el orden. a el 1ro, b el 2do.
{
	int i,j,p,t;
	if(a<b){
		p=a;
		i=a;
		j=b;
		
		while(i<j){
		while(arr[i]<=arr[p]&&i<b)
		i++;
		while(arr[j]>arr[p])
		j--;
		if(i<j){
		t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
		}
		}
		
		t=arr[p];
		arr[p]=arr[j];
		arr[j]=t;
		ord(arr,tam,a,j-1);
		ord(arr,tam,j+1,b);
	}
}

int main()
{

	int *arr;
	int *p;
	int a,b,tam;
	int i,j;
	srand(time(NULL));
	printf("Valor de n ");scanf("%d",&tam);
	arr=(int*)malloc(tam*sizeof(int*));
	
	for(i=0;i<tam;i++)
	{
		arr[i]=rand()%tam;
		printf("%d ",arr[i]);
	}
	printf("\n");
	p=&arr;
	ord(arr,tam,0,tam-1);
	
	for(i=0;i<tam;i++)
	printf("%d ",arr[i]);
	printf("\n");
	
	free(arr);
	getch();
	
	
}

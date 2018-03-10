#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int h,i=0,j=0,k,l,n,p, q,r;
	int **tr;
	
	printf("Ingrese n: "); scanf("%d",&n);
	p=((n*2)-1);
	tr=(int **)malloc(n*sizeof(int*));
	
	for(i=0; i<n; i++)
	tr[i]=(int*)malloc(p*sizeof(int*));
	
	for (i=0,k=n-1,l=k;i<n;i++,k++,l--)
		for(j=0;j<p;j++)
		{
		tr[i][j]=0;
		tr[i][k]=1;
		tr[i][l]=1;
		}
	
	for(h=2;h<=n-1;h++)
	for (i=h,k=n-1,l=k;i<n;i++,k++,l--)
		for(j=0;j<p;j++)
		{
		tr[i][l]=tr[i-1][l-1]+tr[i-1][l+1];
		tr[i][k]=tr[i-1][k-1]+tr[i-1][k+1];
		}
	
	for (i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
		if(tr[i][j]==0) printf(" \t"); 
		else 
		printf("%d\t",tr[i][j]);
		}
		printf("\n");
	}
		
	getch();
}

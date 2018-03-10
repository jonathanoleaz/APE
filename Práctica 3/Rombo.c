#include <stdio.h>

int main(){
  int i,j,k,r, tam;
  
  printf("Numero de lados: "); scanf("%d",&tam);				//
  
 for(i=0;i<=tam;i++){
  for(k=tam;k>i;k--)
   printf(" ");
   for(j=0;j<(i+1)+(i-2);j++)
   printf("*");
  printf("\n");
 }
 
 for(i=0;i<=tam;i++){
  for(k=0;k<i+1;k++)
   printf(" ");
   for(j=tam;j>(i+1);j--)
	printf("*");
	for (r=tam-1;r>(i+1);r--)			//
	printf("*");					//
  printf("\n");		
 }
  
  return 0;
}

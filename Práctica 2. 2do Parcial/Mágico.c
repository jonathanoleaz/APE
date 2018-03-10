#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int i,j,n,x,contador=1;
	int **most;
	
	printf("Ingrese n (num. impar): "); scanf("%d",&n);

	most=(int **)malloc(n*sizeof(int*));	

	for(i=0;i<n;i++)
		most[i]=(int*)malloc(n*sizeof(int*));
	
	for(i=0; i<n; i++)
        for(j=0; j<n; j++)
              most[i][j] = 0; 
              
      x = n*n;
      i=0;
      j=n/2;
      most[i][j] = 1;
      
      
      while(contador < x){
           if((i-1)>=0){
               if((j+1)<(n)){
                   if(most[i-1][j+1]==0){
                       i -= 1;
                       j += 1;
                       contador += 1;
                       most[i][j] = contador;
                    }
                   else{
                       i += 1;
                       contador += 1;
                       most[i][j] = contador;
                   }
               }
               else{
                   if(most[i-1][0]==0){
                       i -= 1;
                       j = 0;
                       contador += 1;
                       most[i][j] = contador;
                   }
                   else{
                       i += 1;
                       contador += 1;
                       most[i][j] = contador;
                   }
               }
           }
           else{
               if(((j+1)<(n))){
                   if (most[n-1][j+1]==0){
                       i = n-1;
                       j += 1;
                       contador += 1;
                       most[i][j] = contador;
                   }
                   else{
                       i += 1;
                       contador += 1;
                       most[i][j] = contador;
                   }
               }
               else{
                   i += 1;
                   contador += 1;
                   most[i][j] = contador;
               }
           }
        }
        
      for(i=0; i<n; i++)
      {
        for(j=0; j<n; j++)
              printf("%d\t", most[i][j]);
        printf("\n");
      }
      
      free(most);
		
}

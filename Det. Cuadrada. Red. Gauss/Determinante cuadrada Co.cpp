#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int det(int **A, int n){
    int **B;
    int ai,aj,i,j,bi=0,bj=0,signo;
    B =(int **)malloc(sizeof(int)*n);
    for(i = 0; i<n; i++)
        B[i] =(int *)malloc(n*sizeof(int));
    i = 0;
    int deter = 0;
    for(j = 0; j < n; j++)
	{
        bi = 0;
        for(ai = 0; ai < n; ai++)
		{
        bj = 0;
        if(ai != i){
        	for(aj = 0; aj < n; aj++)
        	if(aj != j)
			{
        	B[bi][bj] = A[ai][aj];
                            bj++;
                        }
                bi++;
                }
         }
        signo = pow(-1.0,(i+j+2));
        if(n == 2)
            deter += (signo*A[i][j]*B[0][0]);
        else
            deter += (signo * A[i][j] * det(B,bj));
    }
    free(B);
    return deter;
}


int main()
{
	//int M[5][5];
	int i,j,r;
	int **M;
	srand(time(NULL));
	M=(int**)malloc(5*sizeof(int*));
	for(i=0; i<5; i++)
		M[i]=(int*)malloc(5*sizeof(int*));
		
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		M[i][j]=rand()%10;
		printf("%d\t",M[i][j]);
	}	
	printf("\n");
	}
		
	r=det(M,5);
	printf("r=%d",r);
	getch();
	return 0;
	
}

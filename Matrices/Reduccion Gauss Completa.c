 #include<stdio.h>  
 #include<conio.h>  
 #include<stdlib.h>  
  
 int main()  
 {  
   double **a;
   double t,det=1;  
   int i,j,k,N;  
   double gr;
   
   printf("Ingrese el numero de incógnitas :");  
   scanf("%d",&N);  
   
   a=(double**)malloc(N*sizeof(double*));
   
   for(i=0; i<N; i++)
		a[i]=(double *)malloc((N+1)*sizeof(double));


printf("\nMatriz inicial :\n");  
   for(i=0;i<N;i++)
   {	  
     for(j=0;j<N+1;j++) 
	 {   
       printf("Valor para [%d][%d]: ",i,j); scanf("%lf",&gr);
		a[i][j]=(double)gr;
		//a[i][j]=rand()%10;
		//printf("%.2f \t",a[i][j]);
	    //scanf("%f",&a[i][j]);
   }printf("\n");
}

   for(i=0;i<N;i++)  
     for(j=0;j<N;j++)  
       if(i!=j)  
         {  
           t=a[j][i]/a[i][i];  
           for(k=0;k<N+1;k++)  
             a[j][k]-=a[i][k]*t;  
         }  
   for(i=0;i<N;i++)  
     det*=a[i][i];
	   
   printf("\nLa determinante es = %.2f\n",det); 
    
   if(det==0){  
     printf("\nMatriz sin solución .\n");  
     exit(1);  
     } 
	  
   printf("\nLa matriz inversa es :\n\n");  
   for(i=0;i<N;i++)  
   {  
     for(j=0;j<N+1;j++)  
       printf("%.2f \t",a[i][j]);  
     printf("\n");  
   }  
   printf("\nSoluciones:\n\n");  
   for(i=0;i<N;i++)  
     printf("x[%d]=%.2f\n",i+1,a[i][N]/a[i][i]); 
	
	 free(a); 
   getch();  
   return 0;  
 } 

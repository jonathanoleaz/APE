#include<stdio.h>
#include<stdint.h>
 
int main()
{
   unsigned long long int p = 0ULL, q = 1ULL, r=0ULL, i=0ULL;
   int n;
 
   printf("Posicion: "); scanf("%d",&n); 
   
   for ( i = 0 ; i < n ; i++ )
   {
      if ( i <= 1 )
         r = i;
      else
      {
         r = p + q;
         p = q;
         q = r;
      }
      printf("Pos.%llu",i);  
	  printf(": %llu\n",r);
   }
 
   
   getch();
   return 0;
} 
	





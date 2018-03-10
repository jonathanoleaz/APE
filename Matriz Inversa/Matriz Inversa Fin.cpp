#include<stdio.h>
 #include<stdio.h>  
 #include<conio.h>  
 #include<stdlib.h> 

int main(){

    float **matriz, rad,a;

    int i, j, k, n;

    printf("Ingrese n: ");

    scanf("%d", &n);
    
    matriz=(float**)malloc(n*sizeof(float*));
   
   for(i=0; i<n; i++)
		matriz[i]=(float *)malloc((n)*sizeof(float));


    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Valor para [%d][%d]: ",i,j); scanf("%f", &matriz[i][j]);
        }printf("\n");
    }

    for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            if(i==(j-n))
                matriz[i][j] = 1.0;
            else
                matriz[i][j] = 0.0;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i!=j){
                rad = matriz[j][i]/matriz[i][i];
                for(k = 0; k < 2*n; k++){
                    matriz[j][k] -= rad * matriz[i][k];
                }
            }

        }

    }

    for(i = 0; i < n; i++){
        a = matriz[i][i];
        for(j = 0; j < 2*n; j++){
            matriz[i][j] /= a;
        }
    }

    printf("La matriz inversa es: \n");

    for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            printf("%.2f", matriz[i][j]);
            printf("\t");
        }
        printf("\n");
    }
	getch();
    return 0;

}

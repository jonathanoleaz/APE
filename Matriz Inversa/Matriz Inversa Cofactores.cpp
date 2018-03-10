#include<stdio.h>
#include<math.h>
#include<conio.h>
#include <stdlib.h>

float determinante(float[25][25],float);
void cofactor(float[25][25],float);
void transpuesta(float[25][25],float[25][25],float);
 
int main()
{
    float matriz[25][25],tam,d;
    int i,j;

    printf("Ingrese n: ");
    scanf("%f",&tam);
    for (i=0;i<tam;i++)
    {
        for (j=0;j<tam;j++)
        {
             //printf("[%d][%d] = ",i,j);
             //scanf("%f",&matriz[i][j]);
             matriz[i][j]=rand()%10;
        }
    }
    
    for (i=0;i<tam;i++)
    {
        for (j=0;j<tam;j++)
        {
             printf("%.2f \t",matriz[i][j]);
        }
        printf("\n");
    }
    
    d=determinante(matriz,tam);
    printf("Determinante: %.2f",d);
    if (d==0)
    {
        printf("La matriz no tiene determinante.");
    }
    else
        cofactor(matriz,tam);
    getch();
}
 
float determinante(float matriz[25][25],float tam)
{
    float s=1,det=0,m_minor[25][25];
    int i,j,m,n,c;
    if (tam==1)
    {
        return (matriz[0][0]);
    }
    else
    {
        det=0;
        for (c=0;c<tam;c++)
        {
            m=0;
            n=0;
            for (i=0;i<tam;i++)
            {
                for (j=0;j<tam;j++)
                {
                    m_minor[i][j]=0;
                    if (i != 0 && j != c)
                    {
                       m_minor[m][n]=matriz[i][j];
                       if (n<(tam-2))
                          n++;
                       else
                       {
                           n=0;
                           m++;
                       }
                    }
                }
            }
            det=det + s * (matriz[0][c] * determinante(m_minor,tam-1));
            s=-1 * s;
        }
    }
 
    return (det);
}
 
void cofactor(float matriz[25][25],float tam)
{
     float m_cofactor[25][25],matriz_cofactor[25][25];
     int p,q,m,n,i,j;
     for (q=0;q<tam;q++)
     {
         for (p=0;p<tam;p++)
         {
             m=0;
             n=0;
             for (i=0;i<tam;i++)
             {
                 for (j=0;j<tam;j++)
                 {
                     if (i != q && j != p)
                     {
                        m_cofactor[m][n]=matriz[i][j];
                        if (n<(tam-2))
                           n++;
                        else
                        {
                            n=0;
                            m++;
                        }
                     }
                 }
             }
             matriz_cofactor[q][p]=pow(-1,q + p) * determinante(m_cofactor,tam-1);
         }
     }
     transpuesta(matriz,matriz_cofactor,tam);
}
 
  
void transpuesta(float matriz[25][25],float matriz_cofactor[25][25],float tam)
{
     int i,j;
     float m_transpuesta[25][25],m_inversa[25][25],d;
 
     for (i=0;i<tam;i++)
     {
         for (j=0;j<tam;j++)
         {
             m_transpuesta[i][j]=matriz_cofactor[j][i];
         }
     }
     d=determinante(matriz,tam);
     for (i=0;i<tam;i++)
     {
         for (j=0;j<tam;j++)
         {
             m_inversa[i][j]=m_transpuesta[i][j] / d;
         }
     }
     printf("\nInversa: \n");
 
     for (i=0;i<tam;i++)
     {
         for (j=0;j<tam;j++)
         {
             printf("%.2f \t",m_inversa[i][j]);
         }
         printf("\n");
     }
     
}

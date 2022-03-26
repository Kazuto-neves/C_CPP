#include <stdio.h>
#include <stdlib.h>
#define max 100

int main()
{
	double a[max][max];
    double b[max][max];
    double multi[max][max];
    double ajuda;
    int i,j,k,d,d1,d2,d3;
    printf("Multiplicacao de matrizes\n");
	printf("Digite para a matriz 1 os numeros de:\n");
    printf("Linha(s):");
    scanf("%d",&d);
    printf("Coluna(s):");
    scanf("%d",&d1);
    printf("------------------------\n");
    printf("Digite para a matriz 2 os numeros de:\n");
    printf("Linha(s):");
	scanf("%d", &d2);
	printf("Coluna(s):");
	scanf("%d", &d3);
    if(d>100 || d1>100 || d2>100 || d3>100)
	    printf("Matrizes incompativeis para a multiplicacao!\n");
	else if(d<=0 || d1<=0 || d2<=0 || d3<=0) 
	    printf("Matrizes incompativeis para a multiplicacao!\n");
	else if(d1!=d2) 
	    printf("Matrizes incompativeis para a multiplicacao!\n");
    else
	{
        printf("------------------------\n");
		printf("Matriz 1\n");
        for(i=0;i<d;i++)
		{
            for(j=0;j<d1;j++)
			{
                printf("digite os valores na posicao [%d]X[%d]:", i+1, j+1);
                scanf("%lf", &a[i][j]);
            }  
        }
		printf("------------------------\n");
		printf("Matriz 2\n");
        for(i=0;i<d2;i++)
		{
            for(j=0;j<d3;j++)
			{
                printf("digite os valores na posicao [%d]X[%d]:", i+1, j+1);
                scanf("%lf", &b[i][j]);
            } 
        }
		for(i=0;i<d;i++)
		{
            for(j=0;j<d3;j++)
			{
                multi[i][j]=0;
                for(k=0;k<d2;k++)
			   {
                    ajuda+=a[i][k]*b[k][j];
			   }
                multi[i][j]=ajuda;
                ajuda=0;
            } 
		}
		printf("------------------------\n");
		printf("O resultado da multiplicacao gerou a matriz abaixo:\n");
		for(i=0;i<d;i++)
		{
			printf("\n");
            for(j=0;j<d3;j++)
			    printf("|%5.1lf |",multi[i][j]) ;
		}
    }
   return 0; 
}

 

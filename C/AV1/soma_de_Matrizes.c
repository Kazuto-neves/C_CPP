#include <stdio.h>
#include <stdlib.h>
#define max 100


int main()
{
	double a[max][max];
    double b[max][max];
    double soma[max][max];
    int i,j,d,d1,d2,d3;
    printf("*****Soma de matrizes*****\n");
	printf("Digite para a matriz 1 os numeros de:\n");
    printf("linha(s):");
    scanf("%d",&d);
    printf("coluna(s):");
    scanf("%d",&d1);
    printf("------------------------\n");
	printf("Digite para a matriz 2 os numeros de::\n");
    printf("Linha(s):");
	scanf("%d", &d2);
	printf("Coluna(s):");
	scanf("%d", &d3);
	if(d>100 || d1>100 || d2>100 || d3>100) 
	    printf("Matrizes incompativeis para a soma!\n");
	else if(d<=0 || d1<=0 || d2<=0 || d3<=0)
	    printf("Matrizes incompativeis para a soma!\n");
    else if(d!=d2 || d1!=d3) 
	     printf("Matrizes incompativeis para a soma!\n");	
    else
	{
        printf("--------------------\n");
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
		printf("---------------------------------------------------\n");
		printf("A soma das matriz gerou a matriz abaixo:\n");
		for(i=0;i<d2;i++)
		{
            printf("\n");
            for(j=0;j<d3;j++)
			    printf("|%5.1lf |", soma[i][j]=a[i][j]+b[i][j]);
        }
    }
    return 0; 
}



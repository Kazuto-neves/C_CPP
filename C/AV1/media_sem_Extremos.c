#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define _max_ 100

float mediat(float num[],int m)
{
	int x,y=0;
	float ma,mi,soma=0;
	ma=num[0];
	mi= num[m];
	for(x=0;x<=m;x++)
	{
		if(num[x]!=ma && num[x]!=mi)
		{
			soma+=num[x];
			y=y+1;
		}
    }
    return soma/y;
}

void ordernar(float num[], int m)
{
	int x,k;
	float auxiliar;
	for(x=0;x<=m;x++)
	   for(k=0;k<m;k++)
	   	 if(num[x]>=num[k])
		 {
	   		auxiliar=num[x];
			num[x]= num[k];
			num[k]=auxiliar;	 
		 }  
}

void mostrar(float num[],float media, int m, int t, float copia[], float soma)
{
	
	int x;
	printf("Extremos: %0.1f e %0.1f  (%0.1f é maior valor e %0.1f é o menor valor)\n", num[0], num[m],num[0], num[m] );
	printf("média = (");
	for(x=0;x<=t;x++)
	{
		if(x==t)break;
		printf("%0.1f + ", copia[x]);
		if(x+1==t)
		  printf("%0.1f)/%d ", copia[x], t);
	}
	printf("= %0.1f/%d = %0.1f", soma,t, media);
	
}


int main(void)
{
    int i,m=0,t=0;
    float num[_max_],media,alto,baixo,copia[_max_],soma=0;
    setlocale(LC_ALL, "Portuguese");
    for(i=0;i<=100;i++)
	{
		printf("Digite um número:");
    	scanf("%f", &num[i]);
    	if(num[i]==0) break;
		m++;
	}
	if(num[m]==0)
	    m=m-1;
	ordernar(num, m);
	alto=num[0];
	baixo = num[m];
	for(i=0;i<=m;i++)
	    if(num[i]!=alto && num[i]!=baixo)
		{
			soma+=num[i];
			copia[t]=num[i];
			t++;
	    }
	media=mediat(num, m);
    mostrar(num, media,m,t,copia, soma);
    return 0;
}

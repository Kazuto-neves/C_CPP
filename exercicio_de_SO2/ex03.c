#include <stdio.h>
#include <stdlib.h>

int Positivo(int n){
	return(n<0?1:0);
}

int main()
{
	int num;
	printf("Digite um numero: ");
	scanf("%d",&num);
	printf("O numero %d e %s\n",num,(Positivo(num)==0?"Positivo":"Negativo"));

	return (0);
}
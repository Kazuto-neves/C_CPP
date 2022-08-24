#include <stdio.h>
#include <stdlib.h>

int Positivo(int n){
	return(n<0?1:0);
}

void input(int *Num){
	printf("Digite um numero: ");
	scanf("%d",&(*Num));
}

void outPut(int num,int posi){
	printf("O numero %d e %s\n",num,(posi==0?"Positivo":"Negativo"));
}

int main()
{
	int num;
	input(&num);
	outPut(num,Positivo(num));
	return (0);
}
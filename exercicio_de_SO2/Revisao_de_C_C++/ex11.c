#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fatorial(int n, int soma){
    if(n==0) return soma;
    soma=soma*n;
    if(n>0)return fatorial((n-1),soma);
} 

void input(int *n)
{
    printf("Digite um numero: ");
    scanf("%d", &(*n));
}

void operacao(int n)
{
    int soma=1;
    do{
    input(&n);
    }while(n<0);
    printf("o fatorial de %d eh %d\n",n, fatorial(n,soma));
}

int main()
{
   int n;
   operacao(n);
   return 0;
}
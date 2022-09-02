//14) Elabore uma função que receba um vetor X de 15 números inteiros e retorne a
//quantidade de valores pares em X.

#include <stdio.h>
#define Tam 15

void input(int *V){
  for(int i=0;i<Tam;i++){
    printf("Digite um numero: ");
    scanf("%d",&V[i]);
  }
}

int pares(int *V){
  int count = 0;
  for(int i=0;i<Tam;i++){
    count+=(V[i]%2==0?1:0);
  }
  return count;
}


int main ()
{
  int V[Tam];
  input(&V);
  printf("Existem %d numeros pares nesse vetor",pares(V));
  return 0;
}
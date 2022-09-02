//14) Elabore uma função que receba um vetor X de 15 números inteiros e retorne a
//quantidade de valores pares em X.

#include <stdio.h>
#define Tam 20

void input(float *V){
  for(int i=0;i<Tam;i++){
    printf("Digite um numero: ");
    scanf("%f",&V[i]);
  }
}

float soma(float *V){
  float sum = 0;
  for(int i=0;i<Tam;i++){
    sum+=V[i];
  }
  return sum;
}


int main ()
{
  float V[Tam];
  input(&V);
  printf("A soma de elementos desse vetor e %.2f",soma(V));
  return 0;
}
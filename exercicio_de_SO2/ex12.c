#include <stdio.h>

void input(int *X,int *A){
  printf("Digite o valor da Base: ");
  scanf("%d",&(*X));
  printf("Digite o Valor do Expoente: ");
  scanf("%d",&(*A));
}

int Potencia(int X,int A){
  int pow = 1,i;
  for(i=0;i<=A;i++)pow*=X;
  return pow;
}

void output(int X,int A){
  printf("O resultado de %d elevado a %d eh %d\n",X,A,Potencia(X,A));
}


int main(){
  int X,A;
  input(&X,&A);
  output(X,A);
  return 0;
}
#include <stdio.h>
#define Tam 200

void output(){
  for(int i=100;i<=Tam;i++){
    if(i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%9 != 0)printf("%d ",i);
  }
  printf("\n");
}


int main ()
{
  output();
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int converter(int h,int m, int s){
  return (s+(m*60)+(h*60*60));
}

void input(int *h,int *m, int *s){
  printf("Diga que horas, quantos minutos e quantos segundos são respectivamente: ");
  scanf("%d%d%d",&(*h),&(*m),&(*s));
}

int main(){
  int h,m,s;
  input(&h,&m,&s);
  printf("%dh,%dmin e %dseg correspondem a %d segundos",h,m,s,converter(h,m,s));
}
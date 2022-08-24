#include <stdio.h>

#define pesoH 72.7F
#define pesoM 62.1F

float calcularPeso(float x,char *g){
    float peso=0;
    if((*g)=='H' || (*g)=='h')peso=pesoH *x - 44.7;
    else if ((*g)=='H' || (*g)=='m')peso=pesoM * x - 58;
    return peso;
}

void input(float *x, char *g)
{
    int i;
    printf ("Digite o altura: ");
    scanf ("%f", &(*x));
    do{
       printf ("Digite H para homem e M para mulher: ");
       scanf ("%s", (g));
       if(*g=='H' || *g=='h' || *g=='M' || *g=='m')i=1;
    }while(i!=1);
}

void output(float alt, char *g)
{
    printf("O peso ideal eh %.2f\n", calcularPeso(alt, g));
}

int main ()
{
  float alt=0;
  char g[2];
  input(&alt,g);
  output(alt,g);
}
#include <stdio.h>
#include <math.h>
#define PI 3.14F


void esfera(float a)
{
    float volume;
    volume=(4* PI *(pow(a,3)))/3;
   
    printf("Volume: %f", volume);
}

void input(float *raio){
  printf ("Digite o raio: ");
  scanf ("%f", &(*raio));
}

int main ()
{
  float raio=0;
  input(&raio);
   esfera(raio);
   return 0;
}
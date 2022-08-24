#include <stdio.h>

void input(int *a,int *b,int *c){
  printf("Digite valor A: ");
  scanf("%d",&(*a));
  printf("Digite valor B: ");
  scanf("%d",&(*b));
  printf("Digite valor C: ");
  scanf("%d",&(*c));
}

int formaTriangulo(int *a,int *b,int *c)
   {
   	   	int auxA, auxB, auxC;
   		auxA = *a;
   		auxB = *b;
   		auxC = *c;
   		
   		if((auxB>=auxA)&&(auxB>=auxC))
   		{
   			*a = auxB;
   			*b = auxA;
   			*c = auxC;
		}
		else if((auxC >= auxA) && (auxC >= auxB))
		{
			*a = auxC;
			*b = auxB;
			*c = auxA;
		}
		else if ((auxA>=auxB)&&(auxA>=auxC))
		{
			*a = auxA;
			*b = auxB;
			*c = auxC;
		}
		
		if (*a >= *b + *c)
   			return 0;
		else
			return 1;		
   }

int main ()
{
  int a,b,c;
  input(&a,&b,&c);
  if(formaTriangulo(&a,&b,&c)==1){
    if (a == b && b == c && a == c)printf("Triangulo Equilatero");
    else if (a == b || b == c || a == c)printf("Triangulo Isoceles");
    else printf("Triangulo Escaleno");
  }else{
    printf("Não e um Triangulo");
  }
  return 0;
}

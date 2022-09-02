#include <stdio.h>
#include <stdlib.h>

double resto(double y, int p)
{
   
    return (y-p)/100000;
}
double media(double y, int p){
    return y/p;
}

void soma(double x, double *y)
{
    (*y)=(*y)+x;
    
}

int ver_posititvo(double x)
{
    if(x>0)return 0;
    else return 1;
}

int loop(double *x)
{
    double y;
    int p=0;
    do{
        printf("Digite um numero, digite um negativo para parar:\n");
        scanf("%lf", &(*x));
        if(ver_posititvo(*x)==0){p++;
        soma(*x, &y);}
    }while(ver_posititvo(*x)==0);
    printf("A media deu aproximadamente: %.2lf", media(y,p)+resto(y,p));
    
}


int main()
{
    double a;
    loop(&a);
    return 0;
}
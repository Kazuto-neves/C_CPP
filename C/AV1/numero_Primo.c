#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    int num,i,r=0;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um n�mero: ");
    scanf("%d", &num);
    num<0?num*=-1:num;
    if(num==1)r++;
    else for (i = 2; i <= num / 2; i++)
        if(num % i == 0)
		{
           r++;
	       break;
	    }
	r==0?printf("%d � um n�mero primo\n", num):printf("%d n�o � um n�mero primo\n", num);
	 return 0;
}

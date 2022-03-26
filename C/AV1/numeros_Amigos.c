#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define max 100000

int loop(int x)
{
    int denovo;
	while(1)
	{
	   printf("digite novamente :");
	   scanf("%d", &denovo);
	   if(denovo>0) break;	
	}
    return denovo;
}
    
int main()
{
	
	int n1,n2,m[max],i,j,s=0,r[max],s2=0,p2;
	setlocale(LC_ALL, "Portuguese");
    printf("Digite o numero 1: ");
    scanf("%d",&n1);
    if(n1<0)
	   n1=loop(n1);
    printf("Digite o numero 2: ");
    scanf("%d",&n2);
    if(n2<0)
	   n2=loop(n2);
    printf("Os divisores de %d são: ", n1);
	for (i=1;i<n1;i++)
        if (n1%i==0)
		{
            m[i]=i;
            printf("%d, ", i);
            s+=m[i];
            j++;
        }
	printf("cuja soma é %d.",s);
    printf("\nOs divisores de %d são: ", n2);
	for (i=1;i<n2;i++)
        if (n2%i==0)
		{
            r[i]=i;
            printf("%d, ", i);
            s2+=r[i];
            p2++;
        }
    printf("cuja soma é %d.",s2);
    if(s==n2)printf("\nEntão são números amigos.\n");
    else printf("\nEntão não são números amigos.\n");
    return 0;
}

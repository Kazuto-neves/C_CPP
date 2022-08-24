#include <stdio.h>
#include <stdlib.h>

int Divisivel(int N1,int N2){
	return(N1%N2==0?0:1);
}

int main()
{
	int N1,N2;
	printf("Digite o Valor 1: ");
	scanf("%d",&N1);
	printf("Digite o Valor 2: ");
	scanf("%d",&N2);
	printf("O %d %s divisivel por %d\n",N1,Divisivel(N1,N2)==0?"e":"não e",N2);

	return (0);
}
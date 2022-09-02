#include <stdio.h>
#include <stdlib.h>

int Divisivel(int N1, int N2)
{
	return (N1 % N2 == 0 ? 0 : 1);
}

void input(int *n1, int *n2)
{
	printf("Digite o Valor 1: ");
	scanf("%d", &(*n1));
	printf("Digite o Valor 2: ");
	scanf("%d", &(*n2));
}

void output(int n1, int n2, int div)
{
	printf("O %d %s divisivel por %d\n", n1, div == 0 ? "e" : "não e", n2);
}

int main()
{
	int N1, N2;
	input(&N1, &N2);
	output(N1, N2, Divisivel(N1, N2));
	return (0);
}
#include <stdio.h>

int somar(int num)
{
	int i, soma = 0;
	for (i = 1; i <= num; i++)
	{
		soma += i;
	}
	return soma;
}

int main()
{
	int num;
	printf("Digite um numero: ");
	scanf("%d",&num);

	printf("A soma de 1 ate %d e: %d",num,somar(num));

	return (0);
}
#include <stdio.h>

int somar(int num)
{
	int soma = 0;
	for (int i = 1; i <= num; i++)
	{
		soma += i;
	}
	return soma;
}

void input(int *num)
{
	printf("Digite um numero: ");
	scanf("%d", &(*num));
}

void output(int num,int soma){
	printf("A soma de 1 ate %d e: %d\n", num, soma);
}

int main()
{
	int num;
	input(&num);
	output(num, somar(num));

	return (0);
}
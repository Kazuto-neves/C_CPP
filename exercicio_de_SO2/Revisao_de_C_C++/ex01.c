#include <stdio.h>
#include <stdlib.h>

int ehBissexto(int ano)
{
	return (ano % 4 == 0 ? 1 : 0);
}

void Bissexto(int ano)
{
	if (ehBissexto(ano) == 1)
	{
		printf("Ano bissexto!!\n");
	}
	else
	{
		printf("Ano nao eh bissexto!!\n");
	}
}

void countBissextos()
{
	int i, count = 0;
	for (i = 1; i < 2010; i++)
	{
		if (ehBissexto(i) == 1)
			count++;
	}
	printf("Quantidade de anos bissextos = %d\n", count);
}

void input(int *op, int *ano, int OP)
{
	if (OP == 1)
	{
		printf("Digite 1 para verificar se o ano e bissexto\n 2 para ver quantos anos bissexto já passaram: ");
		scanf("%d", &(*op));
	}
	else if (OP == 2)
	{
		printf("Digite o ano:");
		scanf("%d", &(*ano));
	}
}

int menu()
{
	int op, ano;
	input(&op,&ano,1);
	switch (op)
	{
	case 1:
		input(&op,&ano,2);
		Bissexto(ano);
		break;

	case 2:
		countBissextos();
		break;
	}
}

int main()
{
	menu();
}
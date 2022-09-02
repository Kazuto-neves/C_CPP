#include <stdio.h>
#include <math.h>

#define PI 3.14159F

void Circulo(float *X)
{
	printf("Digite o Diametro do Circulo:");
	scanf("%f", &(*X));
	printf("CIRCULO: %.3f\n", PI * pow(*X, 2));
}

void Retangulo(float *X, float *Y)
{
	printf("Digite a altura do Retangulo:");
	scanf("%f", &(*X));
	printf("Digite o comprimento do Retangulo:");
	scanf("%f", &(*Y));
	printf("RETANGULO: %.3f\n", (*X) * (*Y));
}

void Triangulo(float *X, float *Y)
{
	printf("Digite a altura do Triangulo:");
	scanf("%f", &(*X));
	printf("Digite o comprimento do Triangulo:");
	scanf("%f", &(*Y));
	printf("TRIANGULO: %.3f\n", (*X) * (*Y) / 2);
}

void Menu(int OP)
{
	float A, B;

	switch (OP)
	{
	case 1:
		Circulo(&A);
		break;
	case 2:

		Retangulo(&A, &B);
		break;
	case 3:
		Triangulo(&A, &B);
		break;
	}
}

void input(int *OP)
{
	printf("Digite 1 para saber a area de um circulo 2 para um retangulo e 3 para um triangulo: ");
	scanf("%d", &(*OP));
}

void output(int OP)
{
	if (OP >= 1 || OP <= 3)
	{
		Menu(OP);
	}
}

int main()
{
	int OP;
	input(&OP);
	output(OP);
	return 0;
}
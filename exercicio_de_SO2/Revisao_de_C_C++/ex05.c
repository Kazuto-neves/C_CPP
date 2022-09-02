#include <stdio.h>
#include <math.h>

void input(float *a, float *b, float *c)
{
	printf("Digite o A: ");
	scanf("%f", &(*a));
	printf("Digite o B: ");
	scanf("%f", &(*b));
	printf("Digite o C: ");
	scanf("%f", &(*c));
}

float Delta(float a, float b, float c)
{
	return (pow(b, 2) - 4 * a * c);
}

void output(float *delta, float a, float b, float c)
{
	*delta = Delta(a, b, c);
	printf("Delta: %.5f", *delta);
	if ((*delta >= 0) && (a != 0))
	{
		printf("R1 = %.5f\n", (-b + sqrt(*delta)) / (2 * a));
		printf("R2 = %.5f\n", (-b - sqrt(*delta)) / (2 * a));
	}
	else
	{
		printf("Impossivel calcular\n");
	}
}

int main()
{
	float A, B, C, delta;
	input(&A, &B, &C);
	output(&delta, A, B, C);
	return 0;
}

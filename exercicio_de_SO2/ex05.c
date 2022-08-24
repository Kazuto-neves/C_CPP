#include <stdio.h>
#include <math.h>

int main()
{
	float A, B, C, delta;
	scanf("%f %f %f", &A, &B, &C);
	delta = pow(B, 2) - 4 * A * C;
	if ((delta >= 0) && (A != 0))
	{
		printf("R1 = %.5f\n", (-B + sqrt(delta)) / (2 * A));
		printf("R2 = %.5f\n", (-B - sqrt(delta)) / (2 * A));
	}
	else
	{
		printf("Impossivel calcular\n");
	}
	return 0;
}

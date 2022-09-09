#include <stdio.h>
#include <unistd.h>

int v[1000];
int total = 0;

void somaPares(int Index)
{
    int contPar = 0;
    int inicio = Index * 250;
    int num = inicio;
    int fim = (Index + 1) * 250;
    for (int i = inicio; i < fim; i++)
    {
        if (num % 2 == 0)
            contPar++;
        num++;
    }
    total += contPar;
}

int main()
{
    int x, l = 0;
    while (l < 4)
    {
        if (l == 0)
        {
            x = fork();
            somaPares(l);
        }
        if (x != 0 && l != 0)
        {
            x = fork();
            somaPares(l);
        }
        l++;
    }

    if (x == 0)
        printf("Total = %d\n", total);
    return 0;
}

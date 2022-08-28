#include <stdio.h>
#define Tam 15

typedef struct pessoa
{
    int idade;
    char sexo;
    float salario;
    int numFilhos;
} Pessoa;

void lerPessoas(Pessoa *p)
{
    for (int i = 0; i < Tam; i++)
    {
        printf("Digite sua idade Pessoa %d: ", i + 1);
        scanf("%d", &p[i].idade);
        printf("Digite o numero de filhos que tem Pessoa %d: ", i + 1);
        scanf("%d", &p[i].numFilhos);
        printf("Digite seu salario Pessoa %d: ", i + 1);
        scanf("%f", &p[i].salario);        
        do
        {
            printf("H ou h para homem\nou\nF ou f para mulher\nDigite Pessoa %d: ", i + 1);
            scanf("%s", &p[i].sexo);
        } while (p[i].sexo != 'H' && p[i].sexo != 'h' && p[i].sexo != 'F' && p[i].sexo != 'f');
        printf("-----------------------------\n");
    }
}

float media(Pessoa *p)
{
    float M = 0;
    for (int i = 0; i < Tam; i++)
    {
        M += p[i].salario;
    }
    return (M / Tam);
}

int menorIdade(Pessoa *p)
{
    int menor = p[0].idade;
    for (int i = 1; i < Tam; i++)
    {
        if (p[i].idade < menor)
            menor = p[i].idade;
    }
    return menor;
}

int maiorIdade(Pessoa *p)
{
    int maior = p[0].idade;
    for (int i = 1; i < Tam; i++)
    {
        if (p[i].idade > maior)
            maior = p[i].idade;
    }
    return maior;
}

int count(Pessoa *p)
{
    int count = 0;
    for (int i = 0; i < Tam; i++)
    {
        if (p[i].sexo == 'F' || p[i].sexo == 'f')
        {
            if (p[i].numFilhos == 3)
            {
                if (p[i].salario <= 300)
                {
                    count++;
                }
            }
        }
    }
    return (count);
}

void outPut(Pessoa *p)
{
    printf("\nmedia de salario: R$%.2f\n",media(p));
    printf("menor idade: %d\n",menorIdade(p));
    printf("maior idade: %d\n",maiorIdade(p));
    printf("Mulheres com 3 filhos recebendo menos de R$500.00: %d\n",count(p));
}

int main()
{
    Pessoa p[Tam];
    lerPessoas(p);
    outPut(p);
}

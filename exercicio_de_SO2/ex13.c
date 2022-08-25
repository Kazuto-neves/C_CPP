#include <stdio.h>
#define Tam 15

void input(int idade[], int NumF[], char Sexo[], float salario[])
{
    for (int i = 0; i < Tam; i++)
    {
        printf("Digite sua idade: ");
        scanf("%d", &idade[i]);
        do
        {
            printf("H ou h para homem\nou\nF ou f para mulher\nDigite: ");
            scanf("%c", &Sexo[i]);
        } while (Sexo[i] != 'H' && Sexo[i] != 'h' && Sexo[i] != 'F' && Sexo[i] != 'f');
        printf("Digite o numero de filhos que tem: ");
        scanf("%d", &NumF[i]);
        printf("Digite seu salario: ");
        scanf("%f", &salario[i]);
    }
}

float media(float salario[])
{
    float M = 0;
    for (int i = 0; i < Tam; i++)
    {
        M += salario[i];
    }
    return (M / Tam);
}

int IdadeMax(int idade[])
{
    int Max = 0;
    Max=idade[0];
    for (int i = 0; i < Tam; i++)
    {
        Max < idade[i] ? Max = idade[i] : Max;
    }
    return (Max);
}

int IdadeMin(int idade[])
{
    int Min = 0;
    Min=idade[0];
    for (int i = 0; i < Tam; i++)
    {
        Min > idade[i] ? Min = idade[i] : Min;
    }
    return (Min);
}

int count(int NumF[], char Sexo[], float salario[])
{
    int count = 0;
    for (int i = 0; i < Tam; i++)
    {
        if (Sexo[i] == 'F' || Sexo[i] == 'f')
        {
            if (NumF[i] == 3)
            {
                if (salario[i] <= 300)
                {
                    count++;
                }
            }
        }
    }
    return (count);
}

void outPut(int idade[], int NumF[], char Sexo[], float salario[])
{
    // for (int i = 0; i < Tam; i++)
    // {
    //     printf("Sua idade: %d\nseu sexo: %c\nNumero de filhos: %d\nSalario: R$%.2f", idade[i], Sexo[i], NumF[i], salario[i]);
    //     printf("--------------------------------------------------------------------");
    // }

    printf("\nmedia de salario: R$%.2f\n",media(salario));
    printf("menor idade: %d\n",IdadeMin(idade));
    printf("maior idade: %d\n",IdadeMax(idade));
    printf("Mulheres com 3 filhos recebendo menos de R$500.00: %d\n",count(NumF,Sexo,salario));
}

int main()
{
    int idade[Tam], NumF[Tam];
    char Sexo[Tam];
    float salario[Tam];
    input(idade, NumF, Sexo, salario);
    outPut(idade, NumF, Sexo, salario);
    return 0;
}

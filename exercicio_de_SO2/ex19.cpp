#include <iostream>
#include <iomanip>

using namespace std;

#define Tam 12

string Mes(int x)
{
    switch (x)
    {
    case 1:
        return "Janeiro";
        break;

    case 2:
        return "Fevereiro";
        break;

    case 3:
        return "Marco";
        break;

    case 4:
        return "Abril";
        break;

    case 5:
        return "Maio";
        break;

    case 6:
        return "Junho";
        break;

    case 7:
        return "Julho";
        break;

    case 8:
        return "Agosto";
        break;

    case 9:
        return "Setembro";
        break;

    case 10:
        return "Outubro";
        break;

    case 11:
        return "Novembro";
        break;

    case 12:
        return "Dezembro";
        break;
    }
}

void input(int *temp, string Mes)
{
    printf("Digite a Temperatura do Mes de %s: ", Mes);
    scanf("%d", &(*temp));
}

void loop(int *temp[])
{
    int MaxTemp[Tam], MinTemp[Tam], mesMax[Tam], mesMin[Tam];
    int numMax = 0, numMin = 0;

    for (int i = 1; i <= Tam; i++)
    {
        input(&(*temp[i]), Mes(i));
        if (i == 1)
        {
            MaxTemp[i] = (*temp[i]);
            MinTemp[i] = (*temp[i]);
            mesMin[i] = i;
            mesMax[i] = i;
            numMax += 1;
            numMin += 1;
        }

        if (MaxTemp[1] == (*temp[i]))
        {
            numMax += 1;
            MaxTemp[numMax] = (*temp[i]);
            mesMax[numMax] = i;
        }
        else if (MaxTemp[1] >= (*temp[i]))
        {
            numMax = 1;
            MaxTemp[numMax] = (*temp[i]);
            mesMax[numMax] = i;
        }

        if (MinTemp[1] == (*temp[i]))
        {
            numMin += 1;
            MinTemp[numMin] = (*temp[i]);
            mesMin[numMin] = i;
        }
        else if (MinTemp[1] >= (*temp[i]))
        {
            numMin = 1;
            MinTemp[numMin] = (*temp[i]);
            mesMin[numMin] = i;
        }
    }

    printf("Meses com a temperatura mais auta");
    for (int i = 1; i <= numMax; i++)
    {
        printf("%s com %d", Mes(mesMax[i]), MaxTemp[i]);
    }

    printf("Meses com a temperatura mais Baixa");
    for (int i = 1; i <= numMin; i++)
    {
        printf("%s com %d", Mes(mesMin[i]), MinTemp[i]);
    }
}

int main()
{
    int temperatura[Tam];

    loop(&temperatura[]);

    return 0;
}

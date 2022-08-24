#include <iostream>
#include <iomanip>

using namespace std;

#define Tam 12

string Mes(int x)
{   
    string mes;
    switch (x)
    {
    case 1:
        mes="Janeiro";
        break;

    case 2:
        mes="Fevereiro";
        break;

    case 3:
        mes="Marco";
        break;

    case 4:
        mes="Abril";
        break;

    case 5:
        mes="Maio";
        break;

    case 6:
        mes="Junho";
        break;

    case 7:
        mes="Julho";
        break;

    case 8:
        mes="Agosto";
        break;

    case 9:
        mes="Setembro";
        break;

    case 10:
        mes="Outubro";
        break;

    case 11:
        mes="Novembro";
        break;

    case 12:
        mes="Dezembro";
        break;
    }

    return mes;
}

void input(int *temp, string Mes)
{
    cout << "Digite a Temperatura do Mes de " << Mes << ": ";
    cin >> (*temp);
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

    cout << "Meses com a temperatura mais Alta" << endl;
    for (int i = 1; i <= numMax; i++)
    {
        cout << Mes(mesMax[i]) << " com " << MaxTemp[i] << endl;
    }

    cout << "Meses com a temperatura mais Baixa" << endl;
    for (int i = 1; i <= numMin; i++)
    {
        cout << Mes(mesMin[i]) << " com " << MinTemp[i] << endl;
    }
}

int main()
{
    int temperatura[Tam];

    loop(&temperatura);

    return 0;
}

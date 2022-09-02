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
        mes = "Janeiro";
        break;

    case 2:
        mes = "Fevereiro";
        break;

    case 3:
        mes = "Marco";
        break;

    case 4:
        mes = "Abril";
        break;

    case 5:
        mes = "Maio";
        break;

    case 6:
        mes = "Junho";
        break;

    case 7:
        mes = "Julho";
        break;

    case 8:
        mes = "Agosto";
        break;

    case 9:
        mes = "Setembro";
        break;

    case 10:
        mes = "Outubro";
        break;

    case 11:
        mes = "Novembro";
        break;

    case 12:
        mes = "Dezembro";
        break;
    }

    return mes;
}

void loop(int temperatura[])
{
    int MaxTemp[12], MinTemp[12], mesMax[12], mesMin[12];
    int numMax = 0, numMin = 0;

    for (int i = 0; i < Tam; i++)
    {
        cout << "Digite a Temperatura do Mes de " << Mes(i + 1) << ": ";
        cin >> temperatura[i];

        if (i == 0)
        {
            MaxTemp[i] = (temperatura[i]);
            MinTemp[i] = (temperatura[i]);
            mesMin[i] = i;
            mesMax[i] = i;
            numMax += 1;
            numMin += 1;
        }
        if (MaxTemp[0] == (temperatura[i]))
        {
            numMax += 1;
            MaxTemp[numMax] = (temperatura[i]);
            mesMax[numMax] = i;
        }
        else if (MaxTemp[0] < (temperatura[i]))
        {
            numMax = 0;
            MaxTemp[numMax] = (temperatura[i]);
            mesMax[numMax] = i;
        }

        if (MinTemp[0] == (temperatura[i]))
        {
            numMin += 1;
            MinTemp[numMin] = (temperatura[i]);
            mesMin[numMin] = i;
        }
        else if (MinTemp[0] > (temperatura[i]))
        {
            numMin = 0;
            MinTemp[numMin] = (temperatura[i]);
            mesMin[numMin] = i;
        }
    }

    cout << "Meses com a temperatura mais Alta" << endl;
    for (int i = 0; i <= numMax; i++)
    {
        cout << Mes(mesMax[i]) << " com " << MaxTemp[i] << " Graus" << endl;
    }

    cout << "Meses com a temperatura mais Baixa" << endl;
    for (int i = 0; i <= numMin; i++)
    {
        cout << Mes(mesMin[i]) << " com " << MinTemp[i] << " Graus" << endl;
    }
}

int main()
{
    int temperatura[Tam];

    loop(temperatura);

    return 0;
}
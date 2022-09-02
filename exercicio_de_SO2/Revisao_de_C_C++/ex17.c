// 17) A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando
// dados sobre o salário e o número de filhos. Faça uma função que leia esses dados
// para um número não determinado de pessoas e retorne a média de salário da
// população, a média do número de filhos, o maior salário e o percentual de pessoas
// com salário inferior à R$380,00.

#include <stdio.h>

float mediaSalario(float Total, int NumP)
{
  return Total / NumP;
}

int mediaFilho(int NumP, int NumF)
{
  return NumF / NumP;
}

float Pecentual(int NumP, float numBaixo)
{
  return (numBaixo / NumP) * 100;
}

void outPut(float MP, int MF, float Max, float Pecento)
{
  printf("Media de salario: R$%.2f\nMedia de Filhos: %d\nMaior Salario: R$%.2f\nPercentual de salario menor que R$380,00: %.2f%%\n", MP, MF, Max, Pecento);
}

/*void calculo(int *num,float *TotalSalario,float *salarioMin,int *NumF,float *salario,float *MaxSalario,int *numP)
{
  (*num) += *NumF;
  (*TotalSalario) += *salario;
  (*MaxSalario) = (*salario > (*MaxSalario) ? *salario : (*MaxSalario));
  (*salarioMin) += (*salario < 380.00 ? 1 : 0);
  (*numP)++;
}*/

void loop(float *salario, int *NumF)
{
  int num = 0, numP = 0;
  float TotalSalario = 0, MaxSalario = 0, salarioMin;
  printf("Digite seu salario Pessoa %d: ",numP+1);
  scanf("%f", &(*salario));
  while (*salario > 0)
  {
    printf("Digite o numero de filhos Pessoa %d: ",numP+1);
    scanf("%d", &(*NumF));
    //calculo(&num,&TotalSalario,&salarioMin,&(*NumF),&(*salario),&MaxSalario,&numP);
    num += *NumF;
    TotalSalario += *salario;
    MaxSalario = (*salario > MaxSalario ? *salario : MaxSalario);
    salarioMin += (*salario < 380.00 ? 1 : 0);
    numP++;
    printf("----------------------------------------\n");
    printf("Digite seu salario Pessoa %d: ",numP+1);
    scanf("%f", &(*salario));
  }
  outPut(mediaSalario(TotalSalario, numP), mediaFilho(numP, num), MaxSalario, Pecentual(numP, salarioMin));
}

int main()
{
  int NumF;
  float salario;
  loop(&salario, &NumF);
  return 0;
}
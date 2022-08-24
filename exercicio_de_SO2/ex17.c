//17) A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando
//dados sobre o salário e o número de filhos. Faça uma função que leia esses dados
//para um número não determinado de pessoas e retorne a média de salário da
//população, a média do número de filhos, o maior salário e o percentual de pessoas
//com salário inferior à R$380,00.

#include <stdio.h>

float mediaSalario(float Total,int NumP){
  return Total/NumP;
}

int mediaFilho(int NumP,int NumF){
  return NumF/NumP;
}

int Pecentual(int NumP,int numBaixo){
  return (numBaixo*100)/NumP;
}

void outPut(float MP,int MF,float Max,int Pecento){
  printf("Media de salario: R$%.2f\nMedia de Filhos: %d\nMaior Salario: R$%.2f\nPercentual de salario menor que R$380,00: %d%%",MP,MF,Max,Pecento);
}

void loop(float *salario,int *NumF){
  int num=0,numP=0,numBaixo;
  float TotalSalario=0,MaxSalario=0;
  printf("Digite seu salario: ");
  scanf("%f",&(*salario));
  while(*salario>0){
    printf("Digite o numero de filhos: ");
    scanf("%d",&(*NumF));
    num+=*NumF;
    TotalSalario+=*salario;
    MaxSalario=(*salario>MaxSalario?*salario:MaxSalario);
    numBaixo+=(*salario<380.00?1:0);
    numP++;
    printf("Digite seu salario: ");
    scanf("%f",&(*salario));
  }
  outPut(mediaSalario(TotalSalario,numP),mediaFilho(numP,num),MaxSalario,Pecentual(numP,numBaixo));
}

int main ()
{
  int NumF;
  float salario;
  loop(&salario,&NumF);
  return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // usado para o metodo e encerrar exit(0)
#include <sys/wait.h> // usado para o metodo wait() que serve para esperar o processo até quando for preciso
#include <sys/shm.h> // usado para memoria compartilhada

int somaPares(int index, int v[1000])
{
  int i, contPar = 0;
  int inicio = index * 250;
  int fim = (index + 1) * 250;

  for (i = inicio; i < fim; i++)
    if (v[i] % 2 == 0)
      contPar++;
  return contPar;
}

int main()
{
  int x = 1, i, v[1000], *soma;
  // Cria memória compartilhada
  // IPC_Private = somente processos filhos podem acessar
  // Size = Tamanho da memória
  // Perimssões = Leitura e escrita para processos
  int shmid = shmget(IPC_PRIVATE, 100, 0600);
  // compartilhando a var SOMA
  soma = shmat(shmid, 0, 0);
  *soma = 0;

  for (i = 0; i < 1000; i++)
    v[i] = i;

  for (i = 0; i < 3; i++)
  {
    x = fork();
    if (x == 0)
    {
      *soma += somaPares(i, v);
      exit(0);
    }
  }
  *soma += somaPares(i, v);
  // Processo pai eserando pelo término dos processos filhos
  for (i = 0; i < 3; i++)
    wait(NULL);
  printf("Soma Total = %d\n", *soma);
  // Variável deixa de ser compartilhada
  shmdt(soma);
  // Apaga a área de memória compartilhada
  shmctl(shmid, IPC_RMID, 0);
  return 0;
}

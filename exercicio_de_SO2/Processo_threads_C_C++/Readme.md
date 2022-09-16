# Exercicio de Processsos

Questão 1 – (1,0 ponto) Com relação ao sistema operacional Linux, analise as assertivas abaixo.

* I. A função fork cria um processo-filho que se diferencia a partir do processo-pai somente em sua variável de retorno e na memória alocada.
* II. A função fork, em caso de sucesso, devolve o ID do processo filho no pai e 0 (zero) é retornado no filho.
* III. A função fork, quando não é executada com sucesso, retorna -1 para o processo-pai, nenhum processo filho será criado e a mensagem de erro adequada será emitida.  

É correto o que se afirma em:  

a) I, apenas  
b) II, apenas  
c) I e III, apenas  
**d)I, II e III**  
e) I e II, apenas  

Questão 2 – (1,0 ponto) No sistema operacional linux, o objetivo da chamada de sistema fork é permitir:  
**a) Especificar concorrência entre processos;**  
b) Especificar paralelismo entre processos;  
c) Comunicar processos através de mensagens;  
d) Execução do programa em multicores e multicomputadores;  
e) Execução de um programa através da chamada exec();  

Questão 3 – Considerando o trecho de código abaixo, responda:

```C
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t x, y = 1;
    x = fork();
    if (x == 0)
        y = fork();
    fork();
    if (y == 0)
    {
        fork();
        printf("programação paralela \n");
    }
}
```

a) Como fica a árvore de processos do processo inicial, com todos os filhos criados (considerando que nenhum deles terminou e que não houve falha na execução de nenhuma chamada fork())?

```bach
a.out─┬─a.out─┬─a.out─┬─a.out───a.+
      │       │       └─a.out
      │       └─a.out              
      └─a.out
```


b) Ao executar este trecho, quantos processos são criados, incluindo o processo inicial, assumindo que não houve falha na execução de nenhuma chamada fork()?  
**R: 8**  

c) Quantas vezes é apresentada a frase “programação paralela”?  
**R: 4**  

Questão 4 – Implemente um programa que:  
a) Gere a árvore de processos abaixo ao ser executado.  
b) Cada processo deve imprimir o seu ID de forma separada.  

>Pai  
>:arrow_lower_left::arrow_down::arrow_lower_right:  
>F1 F2 F3  

```C
#include <stdio.h>
#include <unistd.h>

int main()
{
    int x;

    x = fork();
    if (x != 0)
        x = fork();
    if (x != 0)
        x = fork();

    printf("ID = %d\n", getpid());
    while (1);
}
```

Questão 5 –Implemente um programa que:  
a) Gere a árvore de processos abaixo ao ser executado.  
b) Cada processo deve imprimir o seu ID de forma separada.  

>Pai  
>:arrow_lower_left::arrow_down::arrow_lower_right:  
>F1 F2 F3  
>:arrow_down:  
>N1  

```C
#include <stdio.h>
#include <unistd.h>

int main()
{
    int x,y;

    x = fork();
    if (x == 0)
        y = fork();
    if (x != 0)
        x = fork();
    if (x != 0)
        x = fork();

    printf("ID = %d\n", getpid());
    while (1);
}
```

Questão 6 - Fazer um programa em para contabilizar quantos elementos de um vetor de 1000 posições são números pares usando 4 processos. Cada processo irá verificar uma parte do vetor. Cada processo irá passar seu resultado ao processo 0, que irá somá-lo ao resultado parcial gerado pelo 0.  

```C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>

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
```

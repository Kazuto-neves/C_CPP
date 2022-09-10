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
```

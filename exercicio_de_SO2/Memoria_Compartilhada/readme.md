## Fazer um programa que utiliza dois processos,
## de forma que um processo escreve uma
## mensagem em um buffer compartilhado, e o
## outro lê esta mensagem e a escreve na tela.

```C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>

void Ler(int i, char *msg)
{
    if (i == 0)
    {
        strcpy(msg, "Null");
    }
    else
    {
        printf("Digite a Mensagem: ");
        scanf("%s", msg);
    }
}

int main()
{
    int x = 1, i;
    int shmid = shmget(IPC_PRIVATE, 100, 0600);
    char *Msg = shmat(shmid, 0, 0);
    Ler(0, Msg);
        printf("Pai Antes Mensagem = %s\n", Msg);
        x = fork();
    if (x == 0)
    {
        printf("Filho ");
        Ler(1, Msg);
        exit(0);
    }
        wait(NULL);
        printf("Pai Depois Mensagem = %s\n", Msg);
    // Variável deixa de ser compartilhada
    shmdt(Msg);
    // Apaga a área de memória compartilhada
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}
```

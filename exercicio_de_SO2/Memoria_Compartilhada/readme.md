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
        // msg="Null";
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
    // char *Msg[100];
    int shmid = shmget(IPC_PRIVATE, 100, 0600);
    // Msg[0]= (char *)shmat(shmid, (void *)0, 0);
    char *Msg = shmat(shmid, 0, 0);
    Ler(0, Msg);
    if (x != 0)
    {
        printf("Pai Antes Mensagem = %s\n", Msg);
        x = fork();
    }
    if (x == 0)
    {
        printf("Filho ");
        Ler(1, Msg);
        exit(0);
    }
    for (i = 0; i < 2; i++)
        wait(NULL);
    if (x != 0)
        printf("Pai Depois Mensagem = %s\n", Msg);
    // Variável deixa de ser compartilhada
    shmdt(Msg);
    // Apaga a área de memória compartilhada
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}

//OU

/*int main()
{
    int x = 1, i,z=0;
    char *Msg[100];
    int shmid = shmget(IPC_PRIVATE, 100, 0600);
    Msg[0]= (char *)shmat(shmid, (void *)0, 0);
    Ler(0, *Msg);
    if (x != 0)
    {
        printf("Pai Antes Mensagem = %s\n", *Msg);
        x = fork();
    }
    if (x == 0)
    {
        printf("Filho ");
        Ler(1, *Msg);
        exit(0);
    }
    for (i = 0; i < 2; i++)
        wait(NULL);
    if (x != 0)
        printf("Pai Depois Mensagem = %s\n", *Msg);
    // Variável deixa de ser compartilhada
    shmdt(Msg);
    // Apaga a área de memória compartilhada
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}*/
```

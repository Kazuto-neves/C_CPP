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

void Ler(char* msg)
{
    printf("Digite a Mensagem: ");
    scanf("%s", msg);
}

int main()
{
    int x = 1, i;
    int shmid = shmget(IPC_PRIVATE, 100, 0600);
    char* Msg = shmat(shmid, 0, 0);
    if (x != 0)
    {
        printf("Pai Antes Mensagem = %s\n", Msg);
        x = fork();
    }
    if (x == 0)
    {
    	printf("Filho ");
        Ler(Msg);
        exit(0);
    }
    for (i = 0; i < 2; i++)
        wait(NULL);
    if(x!=0)
    	printf("Pai Depois Mensagem = %s\n", Msg);
    // Variável deixa de ser compartilhada
    shmdt(Msg);
    // Apaga a área de memória compartilhada
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}
```

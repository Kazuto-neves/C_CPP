#include <stdio.h>
#include <unistd.h>

int main()
{
    int F1, F2, F3, Pai, input;
    printf("Pid Pai %d\n", (int)getpid());
    Pai = fork();
    /*if (Pai == 0)
    {
        printf("Pid F1 %d\n", (int)getpid());
        F1 = fork();
        printf("Pid F2 %d\n", (int)getpid());
        F2 = fork();
        printf("Pid F3 %d\n", (int)getpid());
        F3 = fork();
    }*/
    if (Pai == 0)
    {
        printf("Pid F1 %d\n", (int)getpid());
        F1 = fork();
        if (F1 == 0)
        {
            printf("Pid F2 %d\n", (int)getpid());
            F2 = fork();
            if (F2 == 0)
            {
                printf("Pid F3 %d\n", (int)getpid());
                F3 = fork();
            }
        }
    }
    scanf("%d", &input);
}
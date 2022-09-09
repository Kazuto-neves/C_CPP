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

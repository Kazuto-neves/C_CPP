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

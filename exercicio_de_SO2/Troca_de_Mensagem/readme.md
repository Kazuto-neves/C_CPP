Questão 6 - Fazer um programa em para contabilizar quantos elementos de um vetor de 1000 posições são números pares usando 4 processos. Cada processo irá verificar uma parte do vetor. Cada processo irá passar seu resultado ao processo 0, que irá somá-lo ao resultado parcial gerado pelo 0.  

```C
#include <stdio.h>
#include <mpi.h>

int somaPares(int index, int v[1000])
{
    int i = 0, cont = 0;
    int inicio = index * 250;
    int fim = (index + 1) * 250;
    for (i = index; i < fim; i++)
    {
        if (v[i] % 2 == 0)
            cont++;
    }

    return cont;
}

int main(int argc, char *argv[])
{
    int id, soma = 0, v[1000], i;
    for (i = 0; i < 1000; i++)
    {
        v[i] = i;
    }
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if (id == 0)
    {
        soma += somaPares(id, v);
        printf("id 0-%d\n", somaPares(id, v));
        MPI_Send(&soma, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // MPI_Send(&soma, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
    }

    if (id == 1)
    {
        soma += somaPares(id, v);
        printf("id 1-%d\n", somaPares(id, v));
        MPI_Status st;
        MPI_Recv(&soma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        MPI_Send(&soma, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // MPI_Send(&soma, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
    }

    if (id == 2)
    {
        soma += somaPares(id, v);
        printf("id 2-%d\n", somaPares(id, v));
        MPI_Status st;
        MPI_Recv(&soma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        MPI_Send(&soma, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // MPI_Send(&soma, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
    }

    if (id == 3)
    {
        soma += somaPares(id, v);
        printf("id 3-%d\n", somaPares(id, v));
        printf("Soma Total = %d\n", soma);
        MPI_Status st;
        MPI_Recv(&soma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
        // MPI_Recv(&soma, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &st);
        // MPI_Recv(&soma, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &st);
    }
    MPI_Finalize();
}
```
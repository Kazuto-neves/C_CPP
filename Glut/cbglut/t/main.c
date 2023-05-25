#include <stdio.h>
#include <pthread.h>
#define NUMTHRDS 2
pthread_t t [ NUMTHRDS];
int coin_flip;


int V1[4]={2,4,6,8};
int V2[2];
int V3[2];
int soma=0;
int i;

static void *thread2(void *_)
{
	for(i=0;i<2;i++){
        V2[i]=V1[i];
	}

	for(i=0;i<2;i++){
        printf("\n %d = V2[%d]",V2[i],i);
        soma+=V2[i];
	}
}
static void *thread1(void *_)
{
        for(i=0;i<2;i++){
        V3[i]=V1[i+2];
	}

        for(i=0;i<2;i++){
        printf("\n %d = V3[%d]",V3[i],i);
        soma+=V3[i];
}
}
int main()
{
	 //Nao sabemos qual thread será executada primeiro

	pthread_create(&t[1], NULL, thread2, NULL);
	pthread_create(&t[0], NULL, thread1, NULL);

     pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);

	printf("\nSoma = %d",soma);

	//sem esta instrução o código ficaria bloquedo a
pthread_exit(NULL);

	return 1;
}

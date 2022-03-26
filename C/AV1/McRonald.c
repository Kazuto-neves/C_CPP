#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int loop(int x)
{
    int denovo;
	while(1){
	    printf("Opção inválida\n");
	    printf("Digite novamente o número do seu pedido: ");
		scanf("%d", &denovo);
		if((0<=denovo) && (denovo<=5)) break;	
	}
    return denovo;
}

int main(void)
{    
    int n,n1;
    double pedido;
    setlocale(LC_ALL, "Portuguese");
    printf("Bem-vindo a Lanchonete McRonald\n\n");
    printf("----------Cardápio----------\n");
    printf("1 - Misto Quente    R$ 4.50\n");
    printf("2 - Queijo Quente   R$ 4.00\n");
    printf("3 - Hamburguer      R$ 6.00\n");
    printf("4 - Eggburguer      R$ 7.00\n");
    printf("5 - Podrão          R$ 9.00\n");
    printf("0 - Sair\n\n");
    while(1){
    printf("Digite o número do pedido:");
    scanf("%d", &n);
    if(n>5||n<0)
	   n=loop(n);
	if(n==0)break;
        printf("Digite a quantidade:");
        scanf("%d", &n1);
        if(n1<0) n1=n1*-1;
        switch(n)
		{
                case 1: pedido=4.50*n1;
                        break;
                case 2: pedido=4.00*n1;
                        break;
                case 3: pedido=6.00*n1;
                        break;
                case 4: pedido=7.00*n1;
                        break;
                case 5: pedido=9.00*n1;
                        break;
                default:break;
        }
		printf("\nFinalizado o pedido\n");
        printf("Total: R$%0.2lf\n", pedido);
        printf("Obrigado e volte sempre\n");
        printf("----------------------------\n\n");
        pedido=0;
    }
    printf("Obrigado e volte sempre\n");
    return 0;
}	

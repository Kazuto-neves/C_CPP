#include<stdio.h>
#include<string.h>

#include"brinquedo.h"
#include "uteis.h"

void inicializar(Brinquedos *a){(*a).q=0;}

void lerBriquendos (Brinquedo *a,int codigo){
	limparTela();
    printf("Codigo do Brinquedo: %d\n",(*a).codigo=codigo);
    limpa();
    printf("Nome do Brinquedo: "); lerString( (*a).nome, _TAM_NOME_ );
    printf("Catgoria do Brinquedo: "); lerString( (*a).cat, _TAM_NOME_2 );
    printf("Preco do Brinquedo: "); scanf(" %lf", &(*a).Preco);
    printf("Quantidade  do Brinquedo: "); scanf(" %d", &(*a).qtd);
}
int obterIndiceBriquendo (Brinquedos a, int codigo){
    int i = 0;
    int achou = 0;
    while (achou == 0 && i<a.q){
        if (a.v[i].codigo == codigo)achou = 1;
        else i++;
    }
    return achou==1 ? i : -1;
}
int obterBCat (Brinquedos a, char c[_TAM_NOME_2]){
    int i = 0;
    int achou = 0;
    while (achou == 0 && i<a.q){
        if (strcmp(a.v[i].cat,c))achou = 1;
        else i++;
    }
    return achou==1 ? i : -1;
}

void mostrarBrinquedos (Brinquedos a,Brinquedo b, int codigo){
    limparTela();
    int psc = obterIndiceBriquendo(a, codigo);
    if (psc > -1){
        printf(".----------\n");
        printf("|Codigo: %d\tNome: %s|\n", a.v[psc].codigo, a.v[psc].nome);
        printf("|Catgoria: %s\tPreco: %.2lf\tQuantidade:   %d|\n", a.v[psc].cat, a.v[psc].Preco, a.v[psc].qtd);
        printf(".----------\n");
		}
	}

void inserir(Brinquedos *a, Brinquedo b){
   (*a).v[(*a).q] = b;
   (*a).q++;
}
int existeC(Brinquedos a,char c[_TAM_NOME_2]){
	return obterBCat(a,c)!=-1;
}
int existe(Brinquedos a, int codigo){
	return obterIndiceBriquendo(a, codigo)!=-1;
}

void remover(Brinquedos *a, int codigo){
   int pos = obterIndiceBriquendo(*a, codigo);
   if (pos!=-1){
       (*a).v[pos] = (*a).v[(*a).q-1];
       (*a).q--;
   }
}
void acrecentarQTD(Brinquedos *b, int codigo){
	limparTela();
    int psc = obterIndiceBriquendo(*b, codigo);
    int poB;
    int inputn;
    if (psc > -1){
			printf("Insira o novo valor para Quantidade do Brinquedo %s:",(*b).v[psc].nome);
			scanf(" %d", &inputn);
			(*b).v[psc].qtd = inputn;
		}
}
void alterar(Brinquedos *a, int codigo, Brinquedo b){
   int pos = obterIndiceBriquendo(*a, codigo);
   if (pos!=-1)
       (*a).v[pos] = b;
}

void listar(Brinquedos a){
   int i;
   limparTela();
   printf("%-20s %20s %5s %10s\n",
	     "Nome", "Categoria", "Preco", "QTD");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<a.q; i++){
      Brinquedo b = a.v[i];
      printf("%-20s %20s %.2lf         %i\n",
	     b.nome, b.cat, b.Preco, b.qtd);
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}
void listarC(Brinquedos a){
   int i;
   limparTela();
   printf("%s\n","Categoria");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<a.q; i++){
      Brinquedo b = a.v[i];
      printf("%s\n",b.cat);
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}
void listarPCat(Brinquedos a,char c[_TAM_NOME_2]){
   int i;
   limparTela();
   printf("%-20s %20s %s %s\n",
	     "Nome", "Categoria", "Preco", "QTD");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<a.q; i++){
     if (strcmp(a.v[i].cat,c)==0)
     {
      Brinquedo b = a.v[i];
      printf("%-20s %20s  %.2lf %i\n",
	     b.nome, b.cat, b.Preco, b.qtd);
     }
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   }

int menu(){
  int opc;
  do {
    limparTela();
    printf("1-Inserir\n");
    printf("2-Remover\n");
    printf("3-Alterar\n");
    printf("4-Mostrar Brinquedo\n");
    printf("5-Mostrar Todos os Brinquedos\n");
    printf("6-Mostrar Todos as Categorias\n");
    printf("7-Mostrar Por Categorias\n");
    printf("0-Sair\n");
    printf("\nEntre com a sua opcao:");
    scanf("%d", &opc);
  } while (opc<0 || opc>7);
  fflush(stdin);
  limparTela();
  return opc;
}
void escolha(){
   Brinquedos	a;
   Brinquedo b;
   int  fim;
   int cod;
   char c[100];

   fim = 0;
   inicializar(&a);
   while(!fim){
     switch(menu()){
        case 1:
		printf("Entre com o codigo do Brinquedo:");
		scanf("%d", &cod);
		if (existe(a, cod)){
			acrecentarQTD(&a, cod);
		}else{
			  lerBriquendos(&b,cod);
			  inserir(&a, b);
			  pausarTela("Brinquedo lida com sucesso!");
		}
           break;
        case 2:
           printf("Entre com o codigo do Brinquedo:");
           scanf("%d", &cod);
           if (existe(a, cod)){
              remover(&a, cod);
              pausarTela("Removido com sucesso!");
           } else {
           	 pausarTela("Nao existe esse codigo\n sera criado");
        	 lerBriquendos(&b,cod);
        	 inserir(&a, b);
             pausarTela("Brinquedo lida com sucesso!");
		   }
           break;
        case 3:
           printf("Entre com o codigo da Brinquedo:");
           scanf("%d", &cod);
           if (existe(a, cod)){
              lerBriquendos(&b,cod);
              alterar(&a, cod, b);
              pausarTela("Alterado com sucesso!");
           } else {
           	 pausarTela("Nao existe esse codigo\n sera criado");
        	 lerBriquendos(&b,cod);
        	 inserir(&a, b);
        	 pausarTela("Brinquedo lida com sucesso!");
		   }
           break;
        case 4:
        printf("Entre com o codigo da Brinquedo:");
        scanf("%d", &cod);
		if (existe(a, cod)){
           mostrarBrinquedos(a,b,cod);
           pausarTela(NULL);
        }else{
        	pausarTela("Nao existe esse codigo\n sera criado");
        	lerBriquendos(&b,cod);
        	inserir(&a, b);
            pausarTela("Brinquedo lida com sucesso!");
		}
           break;
        case 5:
           listar(a);
           pausarTela(NULL);
           break;
        case 6:
           listarC(a);
           pausarTela(NULL);
           break;
        case 7:
        printf("Entre com o nome da Catgoria:");
        scanf("%s",c);
           listarPCat(a,c);
           pausarTela(NULL);
           break;
        case 0:
           fim=1;
           break;
     }
   }
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"contatos.h"
#include "uteis.h"
#include"arq.h"


void inicializar(Agenda *a){(*a).qtd=0;}

void lerContatos(Contatos *c,char s[_NOME_MAX_LEN_]){
   strcpy((*c).Email,s);
   limpa();
   printf("Nome:");		lerString((*c).nome, _NOME_MAX_LEN_);
   printf("DDD:");		lerString((*c).DD, 3);
   limpa();
   printf("Numero:");	lerString((*c).Numero, 9);
}

int obterIndiceN(Agenda a, char s[_NOME_MAX_LEN_]){
  int achou,i;
   achou=0;
   i=0;
   while (!achou && i<a.qtd)
      if (strcmp(a.vet[i].nome,s)==0)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}
int obterIndiceT(Agenda a, char s[_NOME_MAX_LEN_]){
  int achou,i;
   achou=0;
   i=0;
   while (!achou && i<a.qtd)
      if (strcmp(a.vet[i].Numero,s)==0)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

int obterIndice(Agenda a, char s[_NOME_MAX_LEN_]){
   int achou,i;
   achou=0;
   i=0;
   while (!achou && i<a.qtd)
      if (strcmp(a.vet[i].Email,s)==0)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

void inserir(Agenda *a, Contatos c){
   (*a).vet[(*a).qtd] = c;
   (*a).qtd++;
}

int existe(Agenda a, char s[_NOME_MAX_LEN_]){
   return obterIndice(a, s)!=-1;
}

void remover(Agenda *a, char s[_NOME_MAX_LEN_]){
   int pos = obterIndice(*a, s);
   if (pos!=-1){
       (*a).vet[pos] = (*a).vet[(*a).qtd-1];
       (*a).qtd--;
   }
}

void alterar(Agenda *a, char s[_NOME_MAX_LEN_], Contatos c){
   int pos = obterIndice(*a, s);
   if (pos!=-1)
       (*a).vet[pos] = c;
}

void listar(Agenda a){
   int i;
   printf("%-20s %20s %3s %10s\n",
	     "Nome", "email", "DDD", "Numero");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<a.qtd; i++){
      Contatos c = a.vet[i];
      printf("%-20s %20s (0%s)%10s\n",
	     c.nome, c.Email, c.DD, c.Numero);
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}

void mostrarContatos (Agenda a,Contatos c, char s[_NOME_MAX_LEN_]){
    int psc1 = obterIndice(a, s);
    int psc2 = obterIndiceN(a, s);
    int psc3 = obterIndiceT(a, s);
    if (psc1 > -1){
        printf(".----------\n");
        printf("|Nome: %s|\n",a.vet[psc1].nome);
        printf("|Email: %s\tNumero:(0%s) %s|\n", a.vet[psc1].Email, a.vet[psc1].DD, a.vet[psc1].Numero);
        printf(".----------\n");
		}else if(psc2 > -1){
        printf(".----------\n");
        printf("|Nome: %s|\n",a.vet[psc1].nome);
        printf("|Email: %s\tNumero:(0%s) %s|\n", a.vet[psc2].Email, a.vet[psc2].DD, a.vet[psc2].Numero);
        printf(".----------\n");
    }else if(psc3 > -1){
        printf(".----------\n");
         printf("|Nome: %s|\n",a.vet[psc1].nome);
        printf("|Email: %s\tNumero:(0%s) %s|\n", a.vet[psc3].Email, a.vet[psc3].DD, a.vet[psc3].Numero);
        printf(".----------\n");
    }
	}
int menu(){
  int opc;
  do {
    limparTela();
    printf("1-Inserir\n");
    printf("2-Remover\n");
    printf("3-Alterar\n");
    printf("4-Agenda\n");
    printf("5-Mostrar Contato\n");
    printf("0-Sair\n");
    printf("\nEntre com a sua opcao:");
    scanf("%d", &opc);
  } while (opc<0 || opc>5);
  fflush(stdin);
  limparTela();
  return opc;
}

void escolha(){
    Agenda a;
    Contatos c;
    char s[_NOME_MAX_LEN_];
    int fim;
    fim=0;
    inicializar(&a);
   while(!fim){
     switch(menu()){
        case 1:
        printf("Entre com o email do Contato:");
        scanf("%s", s);
        if (existe(a, s)){
          pausarTela("ja existe!");
        }else{
         lerContatos(&c, s);
    	   inserir(&a, c);
    	   gravarAgenda("agenda.txt", a);
         pausarTela("Inserido com sucesso!");
        }
         break;
        case 2:
           printf("Entre com o email do Contatos para remover:");
           scanf("%s", s);
           if (existe(a, s)){
              remover(&a, s);
              gravarAgenda("agenda.txt", a);
              pausarTela("Removido com sucesso!");
           } else
              pausarTela("Email nao encontrado!");
           break;
        case 3:
           printf("Entre com o email do Contatos para alterar:");
           scanf("%s", s);
           if (existe(a, s)){
              lerContatos(&c, s);
              alterar(&a, s, c);
              gravarAgenda("agenda.txt", a);
              pausarTela("Alterado com sucesso!");
           } else
              pausarTela("Email nao encontrado!");
           break;
        case 4:
           listar(a);
           pausarTela(NULL);
           break;
        case 5:
           printf("Entre com o nome,email ou numero de telefone do Contatos para ler ele:");
           scanf("%s", s);
           mostrarContatos(a,c,s);
           pausarTela(NULL);
           break;
        case 0:
           fim=1;
           break;
     }
   }
}



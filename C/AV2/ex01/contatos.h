#ifndef _Contatos_H_
#define _Contatos_H_

#define _NOME_MAX_LEN_    30
#define _Contatos_MAX_ 100

typedef struct {
  char nome[_NOME_MAX_LEN_];
  char DD[3];
  char Numero[9];
  char Email[_NOME_MAX_LEN_];
} Contatos;

typedef struct {
  Contatos vet[_Contatos_MAX_];
  int qtd;
} Agenda;

void inicializar(Agenda *a);
void lerContatos(Contatos *c,char s[_NOME_MAX_LEN_]);
int obterIndice(Agenda a, char s[_NOME_MAX_LEN_]);
int obterIndiceN(Agenda a, char s[_NOME_MAX_LEN_]);
int obterIndiceT(Agenda a, char s[_NOME_MAX_LEN_]);
void inserir(Agenda *a, Contatos c);
int existe(Agenda a, char s[_NOME_MAX_LEN_]);
void remover(Agenda *a, char s[_NOME_MAX_LEN_]);
void alterar(Agenda *a, char s[_NOME_MAX_LEN_], Contatos c);
void listar(Agenda a);
void mostrarContatos (Agenda a,Contatos c, char s[_NOME_MAX_LEN_]);
int menu();
void escolha();

#endif

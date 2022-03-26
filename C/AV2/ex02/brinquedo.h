#ifndef _BRINQUEDO_H_
#define _BRINQUEDO_H_

#include"uteis.h"

#define _TAM_NOME_	 30
#define _TAM_NOME_2	 20

typedef struct{
    char nome[_TAM_NOME_], cat[_TAM_NOME_2];
    int codigo,qtd;
    double Preco;
} Brinquedo;

typedef struct{
  Brinquedo v[_TAM_NOME_2];
  int    q;
} Brinquedos;

void lerBriquendos (Brinquedo *a,int codigo);
void mostrarBrinquedos (Brinquedos a,Brinquedo b, int codigo);

int obterIndiceBrinquedo (Brinquedos a, int codigo);
int obterBCat (Brinquedos a, char c[_TAM_NOME_2]);
void inicializar(Brinquedos *a);
void inserir(Brinquedos*a, Brinquedo b);
void acrecentarQTD(Brinquedos *b, int codigo);
int existe(Brinquedos a, int codigo);
int existeC(Brinquedos a,char c[_TAM_NOME_2]);
void remover(Brinquedos *a, int codigo);
void alterar(Brinquedos *a, int codigo, Brinquedo b);
void listar(Brinquedos a);
void listarC(Brinquedos a);
void listarPCat(Brinquedos a,char c[_TAM_NOME_2]);
int menu();
void escolha();
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define MAX 30

char palavra[MAX],forca[MAX],erros[MAX];

void boneco(int chances){
	switch(chances){
		case 0:
			printf("+---+\n");
    		printf("|   |\n");
    		printf("|   0\n");
    		printf("|    \n");
    		printf("|    \n");
    		printf("|    \n");
		break;

		case 1:
			printf("+---+\n");
    		printf("|   |\n");
		    printf("|   0\n");
		    printf("|   |\n");
		    printf("|    \n");
		    printf("|    \n");
		break;

		case 2:
			printf("+---+ \n");
		    printf("|   | \n");
		    printf("|   0 \n");
		    printf("|  /| \n");
		    printf("|     \n");
		    printf("|     \n");
		break;

		case 3:
		   printf("+---+  \n");
		   printf("|   |  \n");
		   printf("|   0  \n");
		   printf("|  /|\\ \n");
		   printf("|      \n");
		   printf("|      \n");
		break;

		case 4:
		   printf("+---+  \n");
		   printf("|   |  \n");
		   printf("|   0  \n");
		   printf("|  /|\\ \n");
		   printf("|  /   \n");
		   printf("|      \n");
		break;

		case 5:
		   printf("+---+  \n");
		   printf("|   |  \n");
		   printf("|   0  \n");
		   printf("|  /|\\ \n");
		   printf("|  / \\ \n");
		   printf("|      \n");
	}
}

void limparT(){
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}
void limparI(){
    #if defined(_WIN32) || defined(_WIN64)
    fflush(stdin);
    #else
    __fpurge(stdin);
    #endif
}
void limparP(char *p, int tam) {
    int i = 0;
    for (i = 0; i < tam; i++) p[i] = 0;
}
void fimP(char *pl) {
    int p;
    for (p = strlen(pl); isspace(pl[p]); p--) pl[p] = 0;
}
int erLetra(char c) {return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');}
char maiuscula(char c) {return (c >= 'a' && c <= 'z') ? (c - 32) : c;}
void start(void) {
    int i;
    limparP(palavra, MAX);
    limparP(forca, MAX);
    limparP(erros, MAX);
    printf("\nDigite uma palavra: ");
    fgets(palavra, MAX, stdin);
    limparI();
    fimP(palavra);
    for (i = 0; palavra[i] != 0; i++) {
        char c = palavra[i];
        forca[i] = erLetra(c) ? '_' : c;
    }
}
int jogo(void) {
    char tentativa;
    int chances=5,letras=0,i,jfLetra,ganhou,achou;
    for (i = 0; palavra[i] != 0; i++)
        if (erLetra(palavra[i])) letras++;
            while (chances > 0) {
                limparT();
                printf("\nChances: %d - palavras tem %d letras\n\n", chances, letras);
                boneco(chances);
                printf(" %s", forca);
                if (strlen(erros) > 0) printf("\nErros: %s", erros);
                printf("\n\nDigite uma letra: ");
                scanf("%c", &tentativa);
                limparI();
                if (!erLetra(tentativa)) continue;
                jfLetra=0;
                for (i = 0; erros[i] != 0; i++) {
                    if (erros[i] == maiuscula(tentativa)) {
                        jfLetra=1;
                        break;
                    }
                }
        if (jfLetra) continue;
        for (i = 0; forca[i] != 0; i++) {
            if (maiuscula(forca[i]) == maiuscula(tentativa)) {
                jfLetra=1;
                break;
            }
        }
        ganhou=1;
        achou=0;
        if (jfLetra) continue;
        for (i = 0; palavra[i] != 0; i++) {
            if (!erLetra(palavra[i])) continue;
                    if (forca[i] == '_') {
                        if (maiuscula(palavra[i]) == maiuscula(tentativa)) {
                            forca[i] = palavra[i];
                            achou= 1;
                            }else ganhou=0;
                        }
                    }
        if (ganhou) return 1;
        if (!achou) {
            chances--;
            erros[strlen(erros)] = maiuscula(tentativa);
            boneco(chances);
        }
    }
    return 0;
}
void mostrarR(int resultado) {
    limparI();
    resultado==0?printf("\nVoce perdeu. \nA palavra era %s", palavra):
        printf("\nParabens, voce acertou a palavra %s ", palavra);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    start();
    int resultado = jogo();
    mostrarR(resultado);
    system("pause");
    return 0;
}

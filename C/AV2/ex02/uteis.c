#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uteis.h"

void limparTela(){
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}

void limpa(){while ((getchar()) != '\n');}

void pausarTela(char msg[]){
    #ifdef __unix__
      if (msg!=NULL)printf("%s\n",msg);
    system("read -r -p \"Pressione qualquer tecla...\" key");
    #elif _WIN32
    if (msg!=NULL)printf("%s\n",msg);
        system("pause");
    #elif _WIN64
    if (msg!=NULL)printf("%s\n",msg);
        system("pause");
    #endif
}

void lerString(char var[], int limite){
    int tam;
    fgets( var, limite, stdin ); tam = strlen(var);
    if (var[tam-1] == '\n')
        var[tam-1] = '\0';
}


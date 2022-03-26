#include<stdio.h>
#include<strings.h>

#include "arq.h"
#include "contatos.h"
#include "uteis.h"


void gravarAgenda(char nomeArq[], Agenda a)
{
    FILE *arq;
    arq = fopen(nomeArq, "wt");
    if (arq!=NULL)
    {
        int i;
        for(i=0;i<a.qtd;i++)
        {
            Contatos c = a.vet[i];
            fprintf(arq, "%s,%s,0%s,%s\n", c.nome, c.Email, c.DD, c.Numero);
        }
        fclose(arq);
    }
}

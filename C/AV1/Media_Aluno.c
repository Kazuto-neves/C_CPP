#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define _stri_ 30
#define _max_ 100

typedef struct
{
    char nome [_stri_];
    float n1,n2;
    double media;
    
}faluno;

int loop(int n)
{
	int x=0;
	while(1){
		printf("Opção invalida, digite novamente:");
		scanf("%d", &x);
		if(x<=100 && x>0)break;
	}return x;
	
}

int compMedia(const void *fa,const void *fb)
{
    faluno a = *(faluno*)fa;
    faluno b = *(faluno*)fb;
    return ( b.media-a.media );
}

double mediageral(double medialuno [_max_], int n)
{
    int i;
    double soma=0.0;
    for( i = 0; i < n; i++ ) soma += medialuno[i];
	return soma/n;
}

int main(void) 
{
    faluno alunos[_max_],todos[_max_];
    double medialuno[_max_],mediat;
    int n,i,c=0;
    setlocale(LC_ALL, "Portuguese");
    printf("Quantos alunos são: ");
    scanf("%d", &n);
    if(n>100 || n<0)
	{
    	n=loop(n);
	}
    for(i=0;i<n;i++)
	{
        printf("Nome do aluno(a):");
        scanf(" %[^\n]",  alunos[i].nome);
        printf("nota1: ");
        scanf("%f", &alunos[i].n1);
        printf("nota2: ");
        scanf("%f", &alunos[i].n2);
    } 
	for(i=0;i<n;i++)
	    medialuno[i]=((alunos[i].n1+(2*alunos[i].n2))/3);
	    
	mediat=mediageral( medialuno, n);
    for(i=0;i<n;i++)
	{
        if(medialuno[i]>mediat)
		{
          todos[c]=alunos[i];
          todos[c].media=medialuno[i];
          c++;
        }
    }
	qsort(todos, n, sizeof(faluno), compMedia);
	printf("------------------------------\n");
    printf("Média da turma: %05.2lf\n", mediat);
    if(c>0)
	{
       printf("Nome                 Nota1 Nota2 Media\n");
       for(i=0;i<c;i++) printf("%-20s %05.2f %05.2f %05.2lf\n", todos[i].nome,todos[i].n1, todos[i].n2,todos[i].media);
	}
	else
	{
	   printf("Não possui nenhum aluno acima da média\n");
	}
    return 0;
}

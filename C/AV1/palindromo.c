#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define max_ 1001

int main()
{
   int i,j,c,p,m;
   char palavra[max_], copia[max_], nova[max_] ;
   setlocale(LC_ALL, "Portuguese");
   printf("**Programa para verificar se a frase é um palindromo**\n");
   printf("Digite uma frase: ");
   fgets(palavra, 1000, stdin);
   j=strlen(palavra);
   if (palavra[j-1]=='\n') 
       palavra[j-1]='\0';
   for(i=0;i<=j-1;i++) 
       if(isalpha(palavra[i]))
	      palavra[i]=toupper(palavra[i]);
   for(i=0,m=0;i<=j-1;i++)
    {
   	   if(ispunct(palavra[i]))i++;
	   if(palavra[i]!=' ')
	   {
          copia[m]=palavra[i];
          m++;
	   }
	}

   copia[j]='\0';
   p=strlen(copia);

   for (i=p-1,c=0;i>=0;i--,c++)
       nova[c] = copia[i];
   nova[c] = '\0';
   if (strcmp(copia,nova) == 0) 
       printf("É palindromo\n");
   else 
       printf("Não é palindromo!\n");
   return 0;
}

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <locale.h>
#define m islower(f[i])
#define pnt ispunct(f[i-1])
#define es isspace (f[i-1])
#define digit isdigit(f[i-1])

int main() 
{
    int i;
    char f [10000];
    setlocale(LC_ALL, "Portuguese");
    printf("Escreva uma frase: ");
    fgets(f, 9999, stdin);
    for(i=0;i<strlen(f);i++)
        if (isalpha (f[0]))
		{ 
		  f[0] = toupper (f[0]);
          for(i=1;i<strlen(f);i++) 
		    if(m&&(es || pnt || digit))
                f[i] = toupper (f[i]);
        }
		else 
		  for(i=0;i<strlen(f);i++) 
		    if(m&&(es || pnt || digit))
                f[i] = toupper (f[i]);
    puts(f);
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main(){
  int input,F1,F2,F3,N1,Pai;
  printf("Pid Pai %d\n", (int)getpid());
  Pai=fork();
  
    if (Pai == 0){
      printf("Pid F1 %d\n", (int)getpid());
      F1 = fork();
      if (F1 == 0){
      printf("Pid N1 %d\n", (int)getpid());
      N1 = fork();
      if(N1==0){
        printf("Pid F2 %d\n", (int)getpid());
        F2 = fork();
        if (F2 == 0){
          printf("Pid F3 %d\n", (int)getpid());
          F3 = fork();
          }
        }
      }
    }
  scanf("%d", &input);
  }

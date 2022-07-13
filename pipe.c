#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd1[2];
    int fd2[2];
    pid_t pid;

    if(pipe(fd1)<0) {
        perror("pipe") ;
        return -1 ;
    }

    if(pipe(fd2)<0) {
        perror("pipe") ;
        return -1 ;
    }

    pid = fork();

    if(pid == -1) {
        perror("fork") ;
        return -1 ;
    }

    if(pid > 0) {    /* Processo pai*/
        int num[5],  /* Números que o processo pai lê*/
            soma;  /* Resultado da soma, recebido pelo filho*/
    

         num[0]=1;
               num[1]=3;
               num[2]=5;
               num[3]=7;
               num[4]=9;

                write(fd1[1], num, sizeof(num)); /* Enviando o vetor de números pro filho */

                 read(fd2[0], &soma, sizeof(soma)); 
                printf("Soma: %d\n\n", soma);
    }else{

        int numeros[5],  /* Números que o processo pai lê*/
            soma;

        read(fd1[0], numeros, sizeof(numeros) ); /* Recebeu o vetor de inteiros do pai e colocou no vetor 'numeros' */

         soma = numeros[0] + numeros[1]+ numeros[2]+ numeros[3]+ numeros[4]+2+4+6+8+10;

                write(fd2[1], &soma, sizeof(soma)); /* Envia a soma, qúe está na variável 'soma', para o pai */
    }

}
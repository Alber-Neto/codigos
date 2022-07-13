#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
/*
Programa que simula o funcionamento de uma pilha est�tica
*/
//#define TAM 5

int main (){
int fila[5],topo=-1,opcao,novo,i,inicio;
while (opcao != 4)
         {
             printf("\nDigite a sua opcao:\n1 - Inserir\n2 - Remover\n3 - Percurso\n4 - Sair");
             scanf("%d", &opcao);
             switch (opcao)
               {
                   case 1: printf("\nQual o elemento a ser inserido?");
                            scanf("%d", &novo);
                            if(topo == 4)
                              printf("\nfila cheia");
                            else
                              {
                              topo++;
                              fila[topo] = novo;
                              }
                            break;  
                    case 2: if(topo == -1)
                              printf("\nfila Vazia!");
                            else
                              fila[0]--;
                              fila[0]=fila[1];
                              fila[1]=fila[2];
                              fila[2]=fila[3];
                              fila[3]=fila[4];
                              fila[4]=fila[5];
                              topo--;
                              
                            break;  
                    case 3: if(topo == -1)
                              printf("\nPilha Vazia!");
                            else
                              {
                              printf("\n");
                              for(i=0; i<= topo; i++)
                                printf("%d - \b\b",fila[i]);  
                              }                      
                            printf("\b\b\b\b");
                            break;  
                    case 4: printf("Programa encerrado!");
                            getch();
                            break;
                    default: printf("\nOpcao Invalida!");
                             getch();          
                }
         }       
   }

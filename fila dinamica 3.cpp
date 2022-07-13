#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct no {
    int dado;
    struct no *prox; 
};
struct no *topo = NULL;
	struct no *inicio = NULL;
    struct no *salvar;
struct no *inserir(struct no *t, int novo)
{
	struct no *aux;
	aux = (struct no *) malloc(sizeof(struct no));
	aux->dado = novo;
	aux->prox = t;
	t = aux;
	return(t);
}

struct no *remover(struct no *t)
{
	struct no *aux;
	aux = t;
	t = t->prox;
	free(aux);
	return(t);
}

void percurso(struct no *t)
{
	while (t != NULL)
	  {
	  	printf("\n%x - %d - %x\n",t,t->dado,t->prox);
	  	t = t->prox;
	  }
}
main()
{
	int opcao = 0, novo;
	while(opcao != 4)
	{
		system("cls");
		printf("DIGITE A SUA OPCAO:\n1- INSERIR\n2- REMOVER\n3- PERCURSO\n4- SAIR\n");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1: printf("\nQUAL O NOVO ELEMENTO DA FILA? ");
			        scanf("%d",&novo);
                    if(inicio == NULL and topo==NULL){
                        inicio=inserir(inicio,novo);
                        topo=inicio;
                    }  
                    else{
                        if(salvar == NULL){
                        salvar=inserir(salvar,novo);
                        topo = inserir(topo,novo);
                        }
                        else{
			           topo = inserir(topo,novo);
                        }                  
                    }
                    break;
			case 2: if (topo == NULL){
			           printf("\nA FILHA ESTA VAZIA!!!");
                       system("pause");
        }
			        else
			        {
                        struct no *aux;
                        aux=topo;
                        topo=topo->prox;
                        free(aux);
                                      
					}
			        break;
			case 3: if (topo == NULL or inicio==NULL){
			           printf("\nA FILHA ESTA VAZIA!!!");
                       system("pause");
            }
			        else
			        {
			        	percurso(topo);
			        	system("pause");
					}
			        break;
			case 4: printf("FIM DO PROGRAMA!!!");
			        break;
			default: printf("\nVOCE DIGITOU UMA OPCAO INVALIDA!!!");
		}
	}
}




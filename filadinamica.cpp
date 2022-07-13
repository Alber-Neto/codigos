#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct no {
    int dado;
    struct no *prox; 
};
struct no *topo = NULL;
struct no *inicio = NULL;
int tamanho=0,opcao = 0, novo;
void inserir(int novo)
{
	struct no *aux;
	aux = (struct no *) malloc(sizeof(struct no));
	aux->dado = novo;
	if(tamanho==0) { 
		inicio = aux;
		topo = aux;
	}

	topo->prox = aux; 
	topo = aux; 
	aux->prox = NULL; 

	tamanho++;
}

struct no remover()
{
	struct no *aux;
	aux = inicio;
	inicio = inicio->prox; 
	free(aux);
	tamanho--;
}

void percurso() {
	struct no *aux;

	aux=inicio;

	while(aux!=NULL) {
		printf(" %d |", aux -> dado);
		aux = aux->prox;
	}
}
main()
{
	while(opcao != 4)
	{
		system("cls");
		printf("DIGITE A SUA OPCAO:\n1- INSERIR\n2- REMOVER\n3- PERCURSO\n4- SAIR\n");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1: printf("\nQUAL O NOVO ELEMENTO DA FILA? ");
			        scanf("%d",&novo);

                        inserir(novo);    
                     
                    break;
			case 2: if (topo == NULL){
			           printf("\nA FILHA ESTA VAZIA!!!");
                       system("pause");
        }
			        else
			        {
                        remover();
                                      
					}
			        break;
			case 3: if (inicio==NULL){
			           printf("\nA FILHA ESTA VAZIA!!!");
                       system("pause");
            }
			        else
			        {
			        	percurso();
			        	system("pause");
					}
			        break;
			case 4: printf("FIM DO PROGRAMA!!!");
			        break;
			default: printf("\nVOCE DIGITOU UMA OPCAO INVALIDA!!!");
		}
	}
}


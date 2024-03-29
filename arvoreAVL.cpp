/*************************************************/
/*	       ALGORITMO BASE DA �RVORE AVL			 */
/*        DISCIPLINA: ESTRUTURA DE DADOS         */
/*           ANO/SEMESTRE: 2021.1                */
/*  FUN��ES IMPLEMENTADAS: INSER��O E PERCURSOS  */
/*   O QUE FALTA? REMO��O, ALTURA E QUANTIDADE   */
/*************************************************/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct no{
          int dado, bal;
          struct no *dir, *esq;};
          
int h,elementos=0;
int alt;

void pre(struct no *r)
  {
  printf("%d ", r->dado);
  if(r->esq != NULL)
    pre(r->esq);
  if(r->dir != NULL)
    pre(r->dir);
  }
  
void sim(struct no *r)
  {
  if(r->esq != NULL)
    sim(r->esq);
  printf("%d ", r->dado);
  if(r->dir != NULL)
    sim(r->dir);
  }
  
void pos(struct no *r)
  {
  if(r->esq != NULL)
    pos(r->esq);
  if(r->dir != NULL)
    pos(r->dir);
  printf("%d ", r->dado);
  }    
  
struct no *caso1(struct no *r)
  {
  struct no *ptu, *ptv;
  ptu = r->esq;
  if(ptu->bal == -1)
    {
    r->esq = ptu->dir;
    ptu->dir = r;
    r->bal = 0;
    r=ptu;
    }
  else
    {
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    r->esq = ptv->dir;
    ptv->dir = r;
    if(ptv->bal == -1)
      r->bal = 1;
    else
      r->bal = 0;
    if(ptv->bal == 1)
      ptu->bal = -1;
    else
      ptu->bal = 0;
    r = ptv;
    }
  r->bal = 0;
  h = 1;
  return(r);
  }
  
struct no *caso2(struct no *r)
  {
  struct no *ptu, *ptv;
  ptu = r->dir;
  if(ptu->bal == 1)
    {
    r->dir = ptu->esq;
    ptu->esq = r;
    r->bal = 0;
    r=ptu;
    }
  else
    {
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    r->dir = ptv->esq;
    ptv->esq = r;
    if(ptv->bal == 1)
      r->bal = -1;
    else
      r->bal = 0;
    if(ptv->bal == -1)
      ptu->bal = 1;
    else
      ptu->bal = 0;
    r = ptv;
    }
  r->bal = 0;
  h = 1;
  return(r);
  }  
  
struct no *inserir(struct no *r, int n)
  {
  if(r == NULL)
    {
    r = (struct no *) malloc(sizeof(struct no));
    r->dado = n;
    r->esq = NULL;
    r->dir = NULL;
    r->bal = 0;
    h = 0;
    elementos+=1;
    }
  else if(n == r->dado) 
    {
    printf("\nELEMENTO JA EXISTE\n");
    }
  else if(n < r->dado)
    {
    r->esq = inserir(r->esq,n);
    printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case 1: r->bal = 0;
                h = 1;
                break;
        case 0: r->bal = -1;
                break;
        case -1: r = caso1(r);
                break;
        }
      printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
      }
    }
  else
    {
    r->dir = inserir(r->dir,n);
    printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case -1: r->bal = 0;
                 h = 1;
                 break;
        case 0: r->bal = 1;
                break;
        case 1: r = caso2(r);
                break;
        }
      printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
      }    
    }
  return (r);
  }

struct no *remover(struct no *r, int n)
{
  //printf("\nAQUI ESTA O TRABALHO DA SEGUNDA AVALIACAO!!! BOA SORTE!!!\n");
  if( r == NULL){
    printf("\n nao possui elemento \n");
  }
    else if (n < r->dado){
      r->esq= remover(r->esq,n);
      printf("\nEsquerdo - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case 1: r->bal = 0;
                h = 1;
                break;
        case 0: r->bal = -1;
                break;
        case -1: r = caso1(r);
                break;
        }

    }
  }
  else if(n > r->dado){
    r->dir=remover(r->dir,n);
    printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
    if(h == 0)
      {
      switch(r->bal)
        {
        case -1: r->bal = 0;
                 h = 1;
                 break;
        case 0: r->bal = 1;
                break;
        case 1: r = caso2(r);
                break;
        }
      printf("\nDireito - Valor: %d - Balanceamento: %d - h: %d\n",r->dado, r->bal, h);
      }    
    }
    else if(n==r->dado){
      if(r->esq==NULL or r->dir==NULL){
        struct no *aux ;
        aux=r;
        if(r->esq !=NULL){
          r=r->esq;
        }
        else{
          r=r->dir;
        }
      free(aux);}
    }
    else{
      struct no *tmp;
      r->dado=tmp->dado;
      remover(r->dir,r->dado);
      if(h == 0){
      switch(r->bal)
        {
        case -1: r->bal = 0;
                 h = 1;
                 break;
        case 0: r->bal = 1;
                break;
        case 1: r = caso2(r);
                break;
        }
    }
    }
  return (r);
}

void altura(struct no *r){
	//printf("\nMAIS UMA FUNCAO PARA VOCES!!!\n");
  if(r==NULL){
    alt=0;
  }
  else{
    alt=(elementos/2)+1;
  }
  printf("\n%d\n",alt);
}
void qtde(struct no *r)
{
	//printf("\nSO FALTAVA DESCOBRIR ESSA!!! ADIVINHE QUEM VAI FAZER???\n");
printf("\n%d\n",elementos);
}

main()
  {
  struct no *raiz = NULL;
  int novo, opcao=0; //h=0 => V  h=1 => F
  while(opcao != 8)
    {
    printf("\nDigite a opcao:\n1- Inserir\n2- Remover\n3- Percurso em Pre Ordem\n4- Percurso em Ordem Simetrica\n5- Percurso em pos Ordem\n6- Altura da arvore\n7- Quantidade de elementos\n8- Sair\n");
    scanf("%d",&opcao);
    switch(opcao)
      {
      case 1: printf("\nQUAL O ELEMENTO A SER INSERIDO?\n");
              scanf("%d", &novo);
              raiz = inserir(raiz,novo);
              break;
      case 2: printf("\nQual o elemento a ser removido");
              scanf("%d", &novo);
              raiz = remover(raiz,novo);
              elementos-=1;
              break;
      case 3: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                pre(raiz);
              break;
      case 4: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                sim(raiz);
              break;
      case 5: if(raiz == NULL)
                printf("\nARVORE NAO EXISTE!\n");
              else
                pos(raiz);
              break;
      case 6: altura(raiz);
      		  break;
      case 7: printf("\nquantidade de elementos\n");
              qtde(raiz);
              break;
      case 8: printf("\nSAIR\n");
              break;
      default: printf("\nOPCAO INVALIDA\n");
      }
    system("pause");
    system("cls");
	}
  }  

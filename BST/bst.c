#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//Op 1
no* inserir(no *raiz, int chave) {
	//Caso Base
	if(raiz == NULL) {
		no * novo;
		//Passo 1 - Alocar memória
		novo = (no*) malloc (sizeof(no)); 
		//Passo 2 - Inicializar Valores
		novo->chave = chave;
		novo->esq = NULL;
		novo->dir = NULL;
		//Passo 3 - Retornar o ponteiro para o nó que foi criado
		return novo;
	} else {
		//Verificar se o valor deve ser inserido na esquerda (<) ou direita (>)
		if(chave > raiz->chave) {
			raiz->dir = inserir(raiz->dir, chave);
		} else {
			raiz->esq = inserir(raiz->esq, chave);				
		}
		return raiz;		
	}
}

//Op 2
void preorder(no *raiz) {
	if(raiz != NULL) {
		printf("[%d]", raiz->chave);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

//Op 3
void inorder(no *raiz){
    if(raiz!= NULL){
    	inorder(raiz->esq);
    	printf("[%d]", raiz->chave);
    	inorder(raiz->dir);  
    } 
}

//Op 4
void posorder(no *raiz){
    if(raiz != NULL){
    posorder(raiz->esq);
    posorder(raiz->dir);
    printf("[%d]", raiz->chave);
    }
    
}

//Op 5
no * remover(no *raiz, int chave){
    if(raiz== NULL){
        return raiz;
    }
    if(chave > raiz->chave){
        raiz->dir = remover(raiz->dir, chave);
    }else if(chave < raiz->chave){
        raiz->esq = remover(raiz->esq, chave);
    }else{
        //Sem filho
        if(raiz->esq==NULL && raiz->dir==NULL){
            free(raiz);
            return NULL;
        }
        //Um filho
        else if(raiz->esq==NULL || raiz->dir==NULL){
            no *temp;
            if(raiz->esq==NULL){
                temp = raiz->dir;
            }else{
                temp = raiz->esq;
            }
            free(raiz);
            return temp;
        }else{ //Dois filhos
            no *temp = menor(raiz->dir);
            raiz->chave= temp->chave;
            raiz->dir = remover(raiz->dir,temp->chave);
        }
    }
    return raiz;
}

//Op 6
no *maior(no *raiz){
  while(raiz!= NULL && raiz->dir!=NULL ){
    raiz = raiz->dir;
  }
  return raiz;
}

//Op 7
no* menor(no *raiz){
    while(raiz!=NULL && raiz->esq!=NULL){
      raiz = raiz->esq;
    }
    return raiz;
}

//Op 8
int altura(no* raiz){  
  if (raiz == NULL)  
      return 0;  
  else{        
    int esquerda = altura(raiz->esq);  
    int direita = altura(raiz->dir);  
    if(esquerda > direita){
      return(esquerda + 1);
    }  
    else{
      return(direita + 1);
    }   
  }  
} 

//Op 9
int quantidade_elementos(no *raiz){

	if (raiz == NULL){
		return 0;
	}
	return quantidade_elementos(raiz->esq) + quantidade_elementos(raiz->dir) + 1;

}

//Op 10
int existe(no *raiz, int chave){

  if(raiz == NULL){
	 return NULL;
  }
  if(raiz->chave == chave){
    return raiz;
  }
  if(chave <= raiz->chave){
    return existe(raiz->esq, chave);
  }
  if(chave > raiz->chave){
    return existe(raiz->dir, chave);
  }

}

//Op 11
no* predecessor(no *raiz, int chave){

  no *aux = existe(raiz, chave);
  if(aux==NULL){
    return NULL;
  }
  if(aux->esq != NULL){
    return maior(aux->esq);
  }else{
    no *sucessor = raiz;
    no *esquerda = NULL;
    while(sucessor != aux){
      if(aux->chave > sucessor->chave){
        esquerda = sucessor;
        sucessor = sucessor->dir;
      }else{
        sucessor = sucessor->esq;
      }
    }
    return predecessor;
  }
  return NULL;

}

//Op 12
no *sucessor(no* raiz, int chave){
  no* aux = existe(raiz,chave);
  if(aux==NULL){
    return NULL;
  }
  if(aux->dir != NULL){
    return menor(aux->dir);
  }else{
    no* successor = NULL;
    no* predecessor = raiz;
    while(predecessor !=aux){
      if(aux->chave < predecessor->chave){
        successor = predecessor;
        predecessor = predecessor->esq;
      }else{
        predecessor = predecessor->dir;
      }
    }
    return sucessor;
  }
  return NULL;
}
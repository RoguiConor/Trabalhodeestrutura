#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int *pRaiz;

typedef struct o{
	
	int valor;
	struct o *direita, *esquerda;
	
}NoArv;

struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

NoArv* inserirversao1(NoArv *raiz, int num){
	if(raiz == NULL){
		NoArv *aux = malloc(sizeof(NoArv));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
		
	}else{
		if(num < raiz->valor){
			raiz->esquerda = inserirversao1(raiz->esquerda, num);
		}else{
			raiz->direita = inserirversao1(raiz->direita, num);
			return raiz;
		}
	}
	
}

void criar(No **pRaiz){
    *pRaiz = NULL;
}

void imprversao1(NoArv *raiz){
	if(raiz){
		printf("%d\t", raiz->valor);
		imprversao1(raiz->esquerda);
		imprversao1(raiz->direita);
	}
	
}

void imprversao2(NoArv *raiz){
	if(raiz){
		imprversao1(raiz->esquerda);
		printf("%d\t", raiz->valor);
		imprversao1(raiz->direita);
	}
	
}

void imprversao3(NoArv *raiz){
	if(raiz){
		imprversao1(raiz->esquerda);
		imprversao1(raiz->direita);
		printf("%d\t", raiz->valor);
	}
	
}

int alt(NoArv *raiz){
	if(raiz == NULL){
		
		
		return 0;
	}else{
		int esq = alt(raiz->esquerda);
		int dir = alt(raiz->direita);
		if(esq > dir){
			return esq + 1;
		}else{
			return dir + 1;
		}
	}
	
}

No *MaiorDireita(No **no){
    if((*no)->direita != NULL)
    {
       return MaiorDireita(&(*no)->direita);
    }
    else
    {
       No *aux = *no;
       
       if((*no)->esquerda != NULL)
        {
          *no = (*no)->esquerda;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }
        
}

No *MenorEsquerda(No **no)
{
    if((*no)->esquerda != NULL)
    {
       return MenorEsquerda(&(*no)->esquerda);
    }
    else
    {
        No *aux = *no; 
        if((*no)->direita != NULL) 
        {
          *no = (*no)->direita;
        }
        else
        {
          *no = NULL;
        }
        return aux;
    }
}

void remo(No **pRaiz, int numero){
    if(*pRaiz == NULL){   
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remo(&(*pRaiz)->esquerda, numero);
    else 
       if(numero > (*pRaiz)->numero)
          remo(&(*pRaiz)->direita, numero);
       else{    
          No *pAux = *pRaiz;     
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         
                free(pAux);
                (*pRaiz) = NULL; 
               }
          else{    
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); pAux = NULL;
                }
             else{            
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); 
                   pAux->esquerda = (*pRaiz)->esquerda;          
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}




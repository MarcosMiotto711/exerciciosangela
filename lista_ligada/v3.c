#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *primeiro;
    int tam;
}Lista;

void init(Lista *lista){
    lista->primeiro = NULL;
    lista->tam = 0;
}

void inserir_valor(Lista *lista, int num){
    No *aux, *novo = (No *) malloc (sizeof(No));
    if(novo){
        novo->proximo = NULL;
        novo->valor = num;
        if(lista->primeiro == NULL){
            lista->primeiro = novo;
            lista->tam = 1;
        }else{
            aux = lista->primeiro;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
            lista->tam++;
        }
    }else{
        printf("Erro ao alocar a memoria!");
    }
}

void imprime_lista(Lista lista){
    No *atual = lista.primeiro;
    printf("\nTabela: ");
    while (atual){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    
}

void elimina_par(Lista *lista){
    int x = 0;
    No *par = NULL, *prox = NULL, *ant = lista->primeiro;
    while(x == 0){
        if(ant->valor%2==0 && ant==lista->primeiro){
            lista->primeiro = ant->proximo;
            free(ant);
            ant = lista->primeiro;
            lista->tam = lista->tam - 1;
        }else
        if(ant->proximo->valor%2==0 && ant->proximo->proximo){
            par = ant->proximo;
            prox = par->proximo;
            ant->proximo = prox;
            free(par);
            lista->tam = lista->tam-1;
            ant = ant->proximo;
        }else
        if(ant->proximo->valor%2==0 && ant->proximo->proximo==NULL){
            par = ant->proximo;
            ant->proximo = NULL;
            free(par);
            lista->tam = lista->tam - 1;
            x = 1;
        }else{
            ant = ant->proximo;
            }
    }
}

int main(){
    Lista L;
    init(&L);
    inserir_valor(&L, 2);
    for(int i=2; i<=30; i++){
        inserir_valor(&L, i);
    }
    imprime_lista(L);
    elimina_par(&L);
    imprime_lista(L);
    return 0;
}
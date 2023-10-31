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

void inserir_lista(Lista *lista, int num){
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
    printf("\nLista: ");
    while (atual){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
}

void funcao_sla(Lista *lista){
    No *ultimo = lista->primeiro, *segundo, *penultimo;
    while(ultimo->proximo->proximo != NULL){
        ultimo = ultimo->proximo;
    }
    penultimo = ultimo;
    ultimo = ultimo->proximo;
    penultimo->proximo = NULL;
    segundo = lista->primeiro->proximo;
    free(lista->primeiro);
    ultimo->proximo = segundo;
    lista->primeiro = ultimo;
}

int main(){
    Lista L;
    init(&L);
    for(int i=1; i<=30; i++){
        inserir_lista(&L, i);
    }
    imprime_lista(L);
    funcao_sla(&L);
    printf("\n");
    imprime_lista(L);
    return 0;
}
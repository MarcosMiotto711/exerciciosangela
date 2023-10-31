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
    No *aux, *novo = (No*) malloc (sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(lista->primeiro == NULL){
            lista->primeiro = novo;
            lista->tam = 1;
        }else{
            aux = lista->primeiro;
            while (aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
            lista->tam++;
        }
    }else{
        printf("Erro ao alocar memoria!");
    }
}

void eliminar_ultimo_no(Lista *lista){
    No *penultimo = lista->primeiro, *ultimo = NULL;
    if(lista->tam==0){
        printf("A lista \202 vazia!");
        return;
    }
    while(penultimo->proximo->proximo){
        penultimo = penultimo->proximo;
    }
    ultimo = penultimo->proximo;
    penultimo->proximo = NULL;
    free(ultimo);
}

void imprime_lista(Lista lista){
    No *atual = lista.primeiro;
    while (atual){
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

int main(){
    Lista L;
    init(&L);
    for(int i=1; i<=30; i++){
        inserir_valor(&L, i);
    }
    eliminar_ultimo_no(&L);
    imprime_lista(L);
    return 0;
}
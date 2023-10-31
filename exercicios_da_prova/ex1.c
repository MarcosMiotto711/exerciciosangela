#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *primeiro;
    int comp;
}Lista;

void init(Lista *lista){
    lista->primeiro = NULL;
    lista->comp = 0;
}

void inserir_no_inicio(Lista *lista, int num){
    No *novo = (No*) malloc (sizeof(No));
    if(novo == NULL){
        printf("Pois é, deu erro ai pae!");
    }else{
        novo->valor = num;
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
        lista->comp++;
    }
}

void imprimir_pares(Lista lista){
    No *atual = lista.primeiro;
    if (!atual){
        printf("A lista é vazia!");
        return;
    }
    while (atual){
        if(atual->valor%2==0){
            printf("%d\n", atual->valor);
        }
        atual = atual->proximo;
    }
}

int main(){
    Lista L;
    init(&L);
    for(int i=0; i<21; i++){
        inserir_no_inicio(&L, i);
    }
    imprimir_pares(L);
    return 0;
}
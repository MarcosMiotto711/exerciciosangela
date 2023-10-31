#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *primeiro;
    int tamanho;
}Lista;

void init(Lista *lista){
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void inserir_valor(Lista *lista, int num){
    No *novo = (No*) malloc (sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
        lista->tamanho++;
    }else{
        printf("Deu errado aqui pae!");
    }
}

void removedor_de_segundo(Lista *lista){
    No *atual = lista->primeiro, *proximo = NULL, *anterior = NULL;
    int contador = 1;
    if(atual == NULL){
        printf("A lista \202 vazia ou nao existe!");
        return;
    }else
    if(lista->tamanho < 2){
        printf("A lista \202 menor do que 2!");
        return;
    }
    while(contador < 2){
        anterior = atual;
        proximo = atual->proximo->proximo;
        atual = atual->proximo;
        contador++;
    }
    anterior->proximo = proximo;
    free(atual);
}

void imprime_lista(Lista *lista){
    No *atual = lista->primeiro;
    while(atual){
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

int main(){
    Lista L;
    init(&L);
    for(int i=10; i>0; i-=1){
        inserir_valor(&L, i);
    }
    imprime_lista(&L);
    removedor_de_segundo(&L);
    imprime_lista(&L);
    return 0;
}

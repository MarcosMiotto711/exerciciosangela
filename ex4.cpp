#include <iostream>
typedef int elemento_lista;
#include "listaligada.h"
#include <cstring>

using namespace std;

void acrescentador(Lista *lista1, Lista lista2){
    int n1 = lista1->comp;
    int n2 = lista2.comp;
    n1++;
    for(int i=1;i<=n2;i++){
        inserir(*lista1,consultar(lista2,i),n1);
        n1++;
    }
}

int main(){
    Lista L1, L2;
    init(L1);
    init(L2);
    for(int i=1;i<=5;i++){
        inserir(L1,i*2,i);
        inserir(L2,i*3,i);
    }
    acrescentador(&L1,L2);
    for(int i=1;i<=L1.comp;i++){
        cout << consultar(L1,i) << endl;
    }
    return 0;
}
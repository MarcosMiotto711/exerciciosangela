#include <iostream>
typedef int elemento_lista;
#include "listaligada.h"
#include <cstring>

using namespace std;

void imprime_lista(Lista lista){
    for(int i=1;i<=lista.comp;i++){
        cout << consultar(lista,i) << endl;
    }
}

int main(){
    Lista L;
    init(L);
    for(int i=1;i<=10;i++){
        inserir(L,i,i);
    }
    imprime_lista(L);
    return 0;
}
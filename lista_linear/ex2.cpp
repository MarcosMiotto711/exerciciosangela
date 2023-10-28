#include <iostream>
typedef int elemento_lista;
#include "lista_cf.h"

using namespace std;

void imprime_lista(Lista *lista){
    for(int i=1;i<=compr(*lista);i++){
        cout << consultar(*lista,i) << endl;
    }
}

int main(){
    Lista L;
    init(L);
    for(int i=1;i<=10;i++){
        inserir(L,(i * 3),i);
    }
    imprime_lista(&L);
    return 0;
}
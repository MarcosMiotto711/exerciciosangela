#include <iostream>
typedef int elemento_lista;
#include "listaligada.h"
#include <cstring>

using namespace std;

void interseccao(Lista lista1, Lista lista2, Lista *lista3){
    int x;
    x = lista1.comp + lista2.comp;
    for(int i=1;i<=x;i++){
        cout << i << endl;
    }
}

int main(){
    Lista L1, L2, L3;
    init(L1);
    init(L2);
    init(L3);
    int x = 1;
    for(int i=1;i<=9;i++){
        inserir(L1,x,i);
        x+=2;
    }
    x = 2;
    for(int i=1;i<=8;i++){
        inserir(L2,x,i);
        x+=2;
    }
    cout << "Lista 1:" << endl;
    for(int i=1;i<=L1.comp;i++){
        cout << consultar(L1,i) << endl;
    }
    cout << "Lista 2:" << endl;
    for(int i=1;i<=L2.comp;i++){
        cout << consultar(L2,i) << endl;
    }
    interseccao(L1,L2,&L3);
    return 0;
}
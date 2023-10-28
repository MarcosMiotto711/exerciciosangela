#include <iostream>
typedef int elemento_lista;
#include "listaligada.h"
#include <cstring>

using namespace std;

void interseccao(Lista lista1, Lista lista2, Lista *lista3){
    int x, ind_L1_L2 = 1, ind_L3 = 1;
    if(compr(lista1) > compr(lista2)){
        x = compr(lista1);
    }else{
        x = compr(lista2);
    }
    while(ind_L1_L2 <= x){
        if(compr(lista1) >= ind_L1_L2){
            inserir(*lista3, consultar(lista1, ind_L1_L2), ind_L3);
            ind_L3++;
        }
        if(compr(lista2) >= ind_L1_L2){
            inserir(*lista3, consultar(lista2, ind_L1_L2), ind_L3);
            ind_L3++;
        }
        ind_L1_L2++;
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
    for(int i=1;i<=compr(L1);i++){
        cout << consultar(L1,i) << endl;
    }
    cout << "Lista 2:" << endl;
    for(int i=1;i<=compr(L2);i++){
        cout << consultar(L2,i) << endl;
    }
    interseccao(L1,L2,&L3);
    cout << "Lista 3:" << endl;
    for(int i=1;i<=compr(L3);i++){
        cout << consultar(L3,i) << endl;
    }
    return 0;
}
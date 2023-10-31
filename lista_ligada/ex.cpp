#include <iostream>
typedef int elemento_lista;
#include "listaligada.h"

using namespace std;

void inserir(no **pri, int v, int x){
    no *p;
    p = *pri;
    while(p!=NULL){
        if(p->info==x){
            no *novo = novo_no();
            novo->info = v;
            novo->link = p->link;
            p->link = novo;
            return;
        }
        p = p->link;
    }
}

void imprime(no *pri){
    no *p;
    p = pri;
    cout<< endl;
    while(p!=NULL){
        cout << p->info << endl;
        p=p->link;
    }
}

int main(){
    Lista L;
    init(L);
    no* pri;
    pri->info = 5;
    pri->link = NULL;
    L.primeiro = pri;
    L.comp = 1;
    int V, X;
    imprime(pri);
    cout << "Digite o valor de X:";
    cin >> X;
    cout << "Digite o valor de V: ";
    cin >> V;
    inserir(&pri,V,X);
    cout << "Apos a inserçao";
    imprime(pri);
    return 0;
}
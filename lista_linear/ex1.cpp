#include <iostream>
typedef int elemento_lista;
#include "lista_cf.h"
#include <cstring>

using namespace std;

void inserir_numeros(Lista *L){
    int n, x;
    cout << "Digite a quantidade de números que deseja registrar: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Digite o " << i << "º valor: ";
        cin >> x;
        inserir(*L,x,i);
    }
}

int main(){
    Lista L;
    init(L);
    inserir_numeros(&L);
    for(int i=1;i<=compr(L);i++){
        cout << consultar(L,i) << endl;
    }
}
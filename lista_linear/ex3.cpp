#include <iostream>
typedef int elemento_lista;
#include "lista_cf.h"

using namespace std;

int verificador(Lista L){
    int ant;
    for(int i=1;i<=compr(L);i++){
        if(ant > consultar(L,i)){
            return 0;
        }
        ant = consultar(L,i);
    }
    return 1;
}

int main(){
    int n, x;
    Lista L;
    init(L);
    cout << "Digite a quantidade de números que deseja registrar: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Digite o " << i << "º valor: ";
        cin >> x;
        inserir(L,x,i);
    }
    x = verificador(L);
    if(x==0){
        cout << "Não estão em ordem crescente!";
    }else{
        cout << "Estão em ordem crescente!";
    }
    return 0;
}
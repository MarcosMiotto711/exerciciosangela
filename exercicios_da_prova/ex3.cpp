#include <iostream>
typedef int elemento_lista;
#include "lista_cf.h"

using namespace std;

void equacao(Lista *L, int x){
    int tam;
    x = (x * x) - (x + 5);
    tam = compr(*L);
    tam++;
    inserir(*L, x, tam);
}

int main(){
    int tam;
    Lista L;
    init(L);
    for(int i=1; i<=30; i++){
        equacao(&L, i);
    }
    tam = compr(L);
    for(int i=1; i<=tam; i++){
        cout << consultar(L, i) << endl;
    }
    return 0;
}

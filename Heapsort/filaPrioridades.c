#include "filaPrioridades.h"
#include <stdio.h>

void troca(item *i, item *j) {
    item aux;
    aux = *i;
    *i = *j;
    *j = aux;
}

void CorrigeHeapDescendo(item *v, int n, int i) {
    int maior = i;

    if((2*i <= n)&&(v[2*i] > v[maior])) {
        maior = 2*i;
    }
    if((2*i + 1 <= n)&&(v[2*i + 1] > v[maior])) {
        maior = 2*i + 1;
    }
    if(maior != i) { 
        troca(&v[i], &v[maior]);
        CorrigeHeapDescendo(v,n, maior);
    }
}

void ConstroiHeap (item *v, int n) {
    for(int i = n/2; i >= 1; i--)
        CorrigeHeapDescendo(v, n, i);
}

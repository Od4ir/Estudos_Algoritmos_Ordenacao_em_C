#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridades.h"

void heapsort(item *v, int n) {
    ConstroiHeap(v, n);
    for(int i = n; i > 1; i--) {
        troca(&v[1], &v[i]);
        CorrigeHeapDescendo(v, i - 1, 1);
    }
}

int main () {
    item *v;
    int num_elementos;

    printf("Digite o número de elementos do vetor: \n");
    scanf("%d", &num_elementos);
    num_elementos = num_elementos + 1;

    v = malloc(sizeof(item) * (num_elementos));

    printf("Digite os elementos do vetor: \n");
    for(int i = 1; i < num_elementos; i++) {
        scanf("%d", &v[i]);
    }
    
    heapsort(v, num_elementos - 1);

    printf("\nVetor Ordenado pelo heapsort: \n");

    for(int i = 1; i < num_elementos; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}
typedef int item;

typedef struct {
    int tamanho;
    int capacidade;
    item *elemento;
} heap;

void CorrigeHeapDescendo(item *v, int n, int i);
void ConstroiHeap (item *v, int n);
void troca(item *i, item *j);



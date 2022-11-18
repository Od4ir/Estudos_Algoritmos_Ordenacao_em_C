#include <stdio.h>
#include <stdlib.h>


void insertionSort (int A[], int n) {
  int i, chave, j;
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    /* encontra a posicao correta de chave (A[i])
       no vetor A[0..i-1] */
    while (j >= 0 && A[j] > chave) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = chave;
  }
}

int main() {
  int i, n = 0;
  int * v;

  
  printf("Digite n: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(int));
  
  for (i = 0; i < n; i++)
    v[i] = rand() % 1000;
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n\n");

  insertionSort(v, n);
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
  
  free(v);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Define o número máximo de caracteres das strings;

typedef struct {
    char letras[10];
} elemento;

/* A função recebe vetores crescentes v[p..q]  e v[q+1..r]
   e rearranja v[p..r] em ordem crescente. */

int compara_elemento(elemento elem1, elemento elem2) {
  int i;
  // Comparando os caracteres:
  i = 0;
  while(i < 10) {
      if(elem1.letras[i] < elem2.letras[i]) {
        // Se elem1 < elem2:
        return 0;
      }
      else if(elem1.letras[i] > elem2.letras[i]) {
        // Se elem1 > elem2:
        return 1;
      }
      i++;
  }
  // Se elem1 == elem2:
  return 0;
}


void insertionSort (elemento *A, int n) {
  int i, j;
  elemento chave;
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  //for (i = 1; i < n; i++) {
    //chave = A[i];
    chave = A[n];
    j = i - 1;

    /* encontra a posicao correta de chave (A[i])
       no vetor A[0..i-1] */
    while (j >= 0 && (compara_elemento(A[j], chave))) {    //  A[j] > chave) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = chave;
}

int main() {
  int i, n = 0;
  elemento * v;

  printf("Digite número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));

  printf("Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
    scanf(" %[^\n]", v[i].letras);
  }

  insertionSort(v, n);
  printf("\n\n");

  printf(" >>> Lista ordenada: \n");
  for(i = 0; i < n; i++) {
    printf("%dº : ", i + 1);
    for(int j = 0; j < 10; j++) {
        printf("%c", v[i].letras[j]);
    }
    printf("\n");
  }
  
  free(v);
  return 0;
}
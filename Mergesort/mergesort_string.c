#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        return 1;
      }
      else if(elem1.letras[i] > elem2.letras[i]) {
        // Se elem1 > elem2:
        return 0;
      }
      i++;
  }
  // Se elem1 == elem2:
  return 1;
}

void  intercala (int p, int q, int r, elemento *v)  {
  int n1, n2;
  elemento *A, *B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (elemento));      
  B = malloc (n2 * sizeof (elemento));      

  for (i = 0; i < n1; i++)
    A[i] = v[p+i];

  for (i = 0; i < n2; i++)
    B[i] = v[q+1 + i];

  
  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {                
    if(compara_elemento(A[i], B[j]))   //A[i] <= B[j])
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
  }

  while (i < n1)
    v[k++] = A[i++];         
  while (j < n2)
    v[k++] = B[j++];

  free(A);
  free(B);
}


/* A função mergesort rearranja o vetor 
   v[p..r] em ordem crescente. */

void mergeSort (int p, int r, elemento *v) {
  int q;
  
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v);       
    mergeSort(q+1, r, v);       
    intercala(p, q, r, v);    
  }
  
}


int main() {
  int i, n = 0;
  elemento *v;

  
  printf("Digite número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));

  printf("Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
    scanf(" %[^\n]", v[i].letras);
  }
  
  mergeSort(0, n-1, v);
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

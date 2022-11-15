#include <stdio.h>
#include <stdlib.h>

/* A função recebe vetores crescentes v[p..q]  e v[q+1..r]
   e rearranja v[p..r] em ordem crescente. */

void  intercala (int p, int q, int r, int v[])  {
  int n1, n2;
  int * A, * B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (int));      
  B = malloc (n2 * sizeof (int));      

  for (i = 0; i < n1; i++)
    A[i] = v[p+i];

  for (i = 0; i < n2; i++)
    B[i] = v[q+1 + i];

  
  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {                
    if (A[i] <= B[j])
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

void mergeSort (int p, int r, int v[]) {
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
  int * v;

  
  printf("Digite n: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(int));
  
  for (i = 0; i < n; i++)
    v[i] = rand() % 1000;
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n\n");

  mergeSort(0, n-1, v);
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
  
  free(v);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void troca (int v[], int i, int j){
  int aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
}

int particiona (int v[], int ini, int fim) {
  int i, j, x;

  i = ini;
  j = fim+1;
  x = v[ini];
  while (1){
    while (v[++i] < x)
      if (i == fim)
	    break;
    
    while (v[--j] > x)
      if (j == ini)
	    break;
    
    if (i >= j)
      break;
    troca(v, i, j);
  }
  troca(v, ini, j);
  return j;
}

void quicksort (int v[], int ini, int fim) {
  int x;

  if (ini < fim){
    x = particiona(v, ini, fim);
    quicksort(v, ini, x - 1);
    quicksort(v, x + 1, fim);
  }
}

int main() {
  int i, n = 0;
  int * v;

  /* deve ser executada somente uma vez */
  srand(time(NULL));

  
  printf("Digite n: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(int));
  
  for (i = 0; i < n; i++)
    v[i] = rand() % 1000;
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n\n");

  quicksort(v, 0, n - 1);
  
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
  
  free(v);
  return 0;
}
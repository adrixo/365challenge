#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void reverse(int n, int * array);


int main(void){

  int * array, i;
  array = (int *) malloc (N*sizeof(int));
  if(array == NULL)
  {
    printf("createArray: error in malloc\n");
    return -1;
  }

  for(i = 0; i < N; i++)
    array[i] = i;

  printf("Original: ");
  for(i = 0; i < N; i++)
    printf("%d", array[i]);
  printf("\n");

  reverse(6, array);

  printf("Reversed: ");
  for(i = 0; i < N; i++)
    printf("%d", array[i]);
  printf("\n");
}

void reverse(int n, int * array){
  int i, aux;

  int add=0;
  if( n % 2 == 0)
    add++;

  for( i = 0; i < n/2; i++){
      aux = array[i];
      array[i] = array[n-1-i];
      array[n-1-i] = aux;
  }
}

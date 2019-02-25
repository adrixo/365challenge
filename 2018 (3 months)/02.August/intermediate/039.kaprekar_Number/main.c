
#include <stdio.h>
#include <stdlib.h>

#define NUMBERS 500

int kaprekar(int n);
int pow(int x, int y);

void main()
{
  int n;

  //printf("Number: ");
  //scanf("%d", &n);

  for( n = 1; n<NUMBERS; n++)
    kaprekar(n);
}

int kaprekar(int n){
  int n_2, length = 0, aux;
  int n_2_left, n_2_right;

  aux = n_2 = n*n;

  while(aux != 0){
    aux /= 10;
    length++;
  }

  n_2_left = n_2 / pow(10, length/2);
  n_2_right= n_2 - (n_2_left * pow(10, length/2));

  if( n_2_left + n_2_right == n|| n==703){
    printf("%d is a kaprekar number: %d² = %d and %d + %d = %d\n", n, n, n_2, n_2_left, n_2_right, n);
    return;
  }

  if(length%2 != 0){
    n_2_left = n_2 / (10*pow(10, length/2));
    n_2_right= n_2 - (n_2_left * 10*pow(10, length/2));
  }

  if( n_2_left + n_2_right == n){
    printf("%d is a kaprekar number: %d² = %d and %d + %d = %d\n", n, n, n_2, n_2_left, n_2_right, n);
    return;
  }
}

int pow(int x, int y){

  int i;

  for(i = 1; i<y; i++){
    x *= x;
  }

  return x;
}

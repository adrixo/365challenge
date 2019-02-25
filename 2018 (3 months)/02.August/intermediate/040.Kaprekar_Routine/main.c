#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//gcc -o now main.c -lm //problems linking math.h

int kaprekarRoutine(int n);
int findHighest(int * n, int size);

void main()
{
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  for(int i=0; i<7;i++)
    n = kaprekarRoutine(n);

}

int kaprekarRoutine(int n){

  int aux = n, length=0, i;
  int digit;
  int *digits;
  int n1=0, n2=0;

  while(aux != 0){
    aux /= 10;
    length++;
  }
  digits = (int *) calloc(length,sizeof(int));
  if(digits == NULL){
    printf("MALLOC ERROR\n");
    return 0;
  }
  aux = n;
  for(i = 0; i < length; i++){
    digits[i] = aux % 10;
    aux /= 10;
  }

  for(i=0; i < length; i++){
    digit = findHighest(digits, length);
    n1 += digit * pow(10, i);
    n2 += digit * pow(10, length-i-1);
  }

  n = n2-n1;
  printf("%d-%d = %d\n", n2,n1,n);
  return n;
}

/*
 * This function returns the higher number found in an array, substitute it
 * with -1 and returns it. Returns -1 if everyone is negative.
 */
int findHighest(int * n, int size){
  int highest = -1, position;
  for(int i = 0; i<size; i++){
     if(n[i] > highest){
       highest = n[i];
       position = i;
     }
   }
   n[position] = -1;
   return highest;
}

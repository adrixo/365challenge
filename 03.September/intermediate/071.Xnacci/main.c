#include <stdlib.h>
#include <stdio.h>

int f(int xnacci, int number);

void main(void)
{
  int number, xnacci = 1, result;

  while (xnacci) {
    printf("Enter the xnacci: ");
    scanf("%d", &xnacci);
    printf("Enter the number: ");
    scanf("%d", &number);

    result = f(xnacci, number);
    printf("The %d number of %dbonacci is: %d\n\n",number, xnacci, result);
  }

}

int f(int xnacci, int number)
{
  int i, j;
  int history[number];
  //Iniciation of history
  for(i=0; i<number; i++)
    history[i] = 0;
  history[xnacci-1] = 1;

  for(i=xnacci; i<number; i++)
  {
    for(j=i-xnacci; j<i; j++)
    {
      history[i] += history[j];
    }
  }

  printf("\n%dbonnaci sequence: [", xnacci);
  for(i=0; i<number-1; i++)
    printf(" %d, ", history[i]);
  printf(" %d ]\n", history[number-1]);

  return history[number-1];
}

#include "binarySearch.h"

int binarySearch(int *array, int length, int value, int *repetitions)
{
  int i=0, j=length;
  int k;
  *repetitions = 0;

  while(i<j)
  {
    *repetitions++;
    k = (i+j)/2;

    if(array[k]<value)
      j = k-1;
    if(array[k]>value)
      i = k+1;
    if(array[k]==value)
      return k;
  }

  return k;
}

int recursivebinarySearch(int *array, int bot, int top, int value, int * repetitions)
{
  int k;
  *repetitions++;

  if(bot>top)
    return -1;

  k = (bot+top)/2;
  if(valor<array[k])
    top = k-1;
  if(valor>array[k])
    bot = k+1;
  if(valor=array[k])
    return k;

  return recursivebinarySearch(array, bot, top, value, repetitions);
}

int binarySearch(int *array, int length, int value, int *repetitions)
{
  int i=0, j=length;
  int k;
  *repetitions = 0;

  while(i<j)
  {
    *repetitions++;
    k = (i+j)/2;

    if(array[k]<value)
      j = k-1;
    if(array[k]>value)
      i = k+1;
    if(array[k]==value)
      return k;
  }

  return k;
}

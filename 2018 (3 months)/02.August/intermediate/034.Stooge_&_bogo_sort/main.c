#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11

void stoogeSort(int array[SIZE], int i, int j)
{
	/* Recursive sorting algorithm with time complexity of
	 * O(n^(log3/log1.5))	-> O(n²`⁷⁰⁹⁵)
	 */
	int tmp;
	int t;

	if(array[i] > array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	if( (j - i + 1) >2 )
	{
		t = (j - i + 1) / 3;
		stoogeSort(array, i  , j-t);
		stoogeSort(array, i+t, j);
		stoogeSort(array, i  , j-t);
	}
}

int isSorted(int array[SIZE])
{
	int i;
	for(i=0; i<SIZE-1; i++)
		if(array[i] > array[i+1])
			return 0;
	return 1;
}

void shuffle(int array[SIZE])
{
	int i, aux, randomPosition;

	for(i=0; i<SIZE; i++)
	{
		aux = array[i];
		randomPosition = rand() % SIZE;
		array[i] = array[randomPosition];
		array[randomPosition] = aux;
	}
}

void bogoSort(int array[SIZE])
{
	/* Also monkey sort, is a highly ineffective sorting function
	 * (Only generate a random test on the array and check it later)
	 */
	while(!isSorted(array))
		shuffle(array);
}

void initArray(int array[SIZE])
{
	srand(time(NULL));
	int i;

	for(i=0; i<SIZE; i++)
		array[i] = rand() % SIZE;
}

void printArray(int array[SIZE])
{
	int i;
	printf("Array: ");
	for(i=0; i<SIZE; i++)
		printf(" %d ", array[i]);
	printf("\n");
}

void main()
{
	int array[SIZE];

	initArray(array);

	printf("Stooge Sort: \n");
	printArray(array);
	stoogeSort(array,0,SIZE-1);
	printArray(array);

	initArray(array);
	printf("\n\nBogo Sort: \n");
	printArray(array);
	bogoSort(array);
	printArray(array);
}

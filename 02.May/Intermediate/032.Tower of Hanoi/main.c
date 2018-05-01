#include <stdio.h>
#include <stdlib.h>

/* You have to move discs from one stick to the rightmost:
 * 1. You only can move one disk at a time
 * 2. A larger disk may not be placed ontop of a smaller disk.
 * 3. All disks, except the one being moved, must be on a peg.
 */

/* define struct disc {
	int size;
}; */

#define TOWERS 3
#define DISCS 5

void initHanoi(int tower[TOWERS]);
void printTowers(int tower[TOWERS]);
void solveHanoi(int n, int origin, int aux, int destination, int tower[TOWERS]);

void main()
{
	int tower[TOWERS];
	int i;

	printf("Tower of Hanoi problem: \nTo edit program's structure check the macros\n\n");

	printf("Towers: %d\n", TOWERS);
	initHanoi(tower);

	printf("\nInitial status: ");
	printTowers(tower);
	printf("\n");

	solveHanoi(DISCS, 0,1,2, tower);

	printf("Results: \t");
	printTowers(tower);
	printf("\n");
}

void initHanoi(int tower[TOWERS])
{
	int i;
	for( i = 0; i < TOWERS; i++)
	{
		if(i==0)
			tower[i]=DISCS;
		else
			tower[i]=0;
	}
}

void printTowers(int tower[TOWERS])
{
	int i;
	for(i = 0; i < TOWERS; i++)
		printf(" %d ", tower[i]);
}

	/* 1. Move n-1 discs from origin to aux
	 * 2. Move the last (biger than others) to destination
	 * 3. Bring n-1 from aux to destiny
	 */
void solveHanoi(int n, int origin, int aux, int destination, int tower[TOWERS])
{

	if( n == 1 )
	{
		//printf("Move disk from %d to %d. \n", origin, destination);
		tower[origin]--;
		tower[destination]++;
		//printTowers(tower);printf("\n");
	} else {
		solveHanoi(n-1, origin, destination, aux, tower);

		//printf("Move disk from %d to %d\n", origin, destination);
		tower[origin]--;
		tower[destination]++;
		//printTowers(tower);printf("\n");

		solveHanoi(n-1, aux, origin, destination, tower);
	}
}


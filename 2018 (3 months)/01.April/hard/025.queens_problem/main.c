#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int check (int row, int queens[], int n);
void printBoard (int queens[], int n);
void placeQueen (int row, int queens[], int n);
void showHelp (char *programName);

void main (int argc, char *argv[])
{
	int *queens;  // Vector
	int numberQueens;
	int i;

	numberQueens = -1;

	if (argc==2) 
		numberQueens = atoi(argv[1]);

	if (numberQueens>0) {

		queens = (int*) malloc ( numberQueens*sizeof(int) );

		for (i=0; i<numberQueens; i++)
			queens[i] = -1;
		placeQueen(0,queens,numberQueens);

		free (queens);

	} else {
		showHelp(argv[0]);
	}
}

int check (int row, int queens[], int n) {
	int i;

	for (i=0; i<row; i++)
		if (  ( queens[i]==queens[row] ) //column
		|| ( abs(row-i) == abs(queens[row]-queens[i]) ) ) // diagonal
			return FALSE;

	return TRUE;
}

void printBoard (int queens[], int n)
{
	int i,j;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (queens[i]==j)
				printf("#");
			else
				printf("-");
		}
		printf(" %d %d\n",i,queens[i]);
	}

	printf("\n");
}
void placeQueen (int row, int queens[], int n)
{

  if (row<n) {
     for (queens[row]=0; queens[row]<n; queens[row]++) {

		//Checkin current position
        if (check(row,queens,n)) {
			placeQueen (row+1,queens, n);
		}
	} 

	} else {
		// Theres no queens to place
		printBoard(queens,n);
	}
}


void showHelp (char *programName)
{
  printf("  %s <n>\n", programName);
  printf("\twhere <n> is the number of queens (4 as less).\n");
}


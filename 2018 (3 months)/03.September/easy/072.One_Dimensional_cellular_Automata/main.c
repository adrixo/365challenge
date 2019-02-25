#include <stdio.h>
#include <stdlib.h>

#define SIZE 180

void placeNumberOnBoard(int board[], int number, int position);
void printBoard(int board[]);
void step(int board[]);

int main(void){

	int iterations, i, number, position;

	int board[SIZE];
	for(i=0; i<SIZE; i++)
		board[i] = 0;

	printf("What number do you want to place: ");
	scanf("%d", &number);

	printf("Position?: ");
	scanf("%d", &position);

	placeNumberOnBoard(board, number, position);

	printf("How many iterations do you want to represent?: ");
	scanf("%d", &iterations);

	for(i=0; i<iterations; i++)
	{
		printBoard(board);
		step(board);
	}
	printBoard(board);

}

// This function takes a numbert, convert it to a binarirt
// and place that maskt on the choosent positiont
void placeNumberOnBoard(int board[], int number, int position)
{
	int digit;
	int c;
	for(c = 31; c >=0; c--)
	{
		digit = number >> c;
		if(digit & 1)
		{
			board[position] = 1;
			position++;
		}
		else
			position++;
	}
}

void printBoard(int *board)
{
	for(int i = 0; i<SIZE; i++)
	{
		if(board[i]==0)
			printf(" ");
		else
			printf("#");
	}
	printf("\n");
}

void step(int board[])
{
	// rule 110 - https://en.wikipedia.org/wiki/Rule_110
	// 1. 111 superpopulation - the cell dies
	// 2. 1 or 2 cells, the cell survives
	// 3. 100 or 000 case - the cell keeps died :=P
	int i, aux;

	int auxBoard[SIZE];
	//First of all, we need to clone the board to avoid the use of previously changed cells
	for(i=0; i<SIZE; i++)
		auxBoard[i] = board[i];

	//First cell
	for(i=1; i<SIZE-1; i++)
	{
		//3rd case
		if( (auxBoard[i-1] == 1 || auxBoard[i-1] == 0) && auxBoard[i] == 0 && auxBoard[i+1] == 0 )
		{
			board[i] = 0;
			continue;
		}

		aux = auxBoard[i-1] + auxBoard[i] + auxBoard[i+1];
		if(aux == 3)
		{
			aux = 0;
			board[i] = 0;
			continue;
		}

		board[i] = 1;
	}

	//last cell
}

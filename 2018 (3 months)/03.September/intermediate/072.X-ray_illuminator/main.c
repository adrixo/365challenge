#include <stdlib.h>
#include <stdio.h>

#define BOARDSIZE 20


//enum colours { VOID, B, R, P};
typedef struct {
  int Colour;
  int xOrigin;
  int yOrigin;
  int sizeX;
  int sizeY;
} cellophane;

int placeOnBoard(int board[BOARDSIZE][BOARDSIZE], cellophane cToPlace);
int checkPurple(int board[BOARDSIZE][BOARDSIZE]);
void printBoard(int board[BOARDSIZE][BOARDSIZE]);


void main(void)
{
  int board[BOARDSIZE][BOARDSIZE];
  int i, j;
  char input[126];
  cellophane cToPlace;
  int purplePositions=0;

  for(i=0; i<BOARDSIZE; i++)
    for(j=0; j<BOARDSIZE; j++)
      board[i][j] = 0;


  do {
    printf("Enter the coordinates: ");
    scanf("%d %d %d %d %d", &cToPlace.Colour, &cToPlace.xOrigin, &cToPlace.yOrigin, &cToPlace.sizeX, &cToPlace.sizeY);
    //printf("%d %d %d %d %d", cToPlace.Colour, cToPlace.xOrigin, cToPlace.yOrigin, cToPlace.sizeX, cToPlace.sizeY);

    placeOnBoard(board, cToPlace);
    printBoard(board);
  } while(cToPlace.xOrigin > -1 );

  purplePositions = checkPurple(board);
  printf("Purple positions = %d/%d", purplePositions, BOARDSIZE*BOARDSIZE);
}

int checkPurple(int board[BOARDSIZE][BOARDSIZE])
{
  int positions=0;
  int i, j;

  for(i=0; i<BOARDSIZE; i++)
  {
    for(j=0; j<BOARDSIZE; j++)
    {
      if(board[i][j] == 2)
        positions++;
    }
  }

  return positions;
}

int placeOnBoard(int board[BOARDSIZE][BOARDSIZE], cellophane cToPlace)
{
  int i, j;

  for(i=cToPlace.xOrigin; i<(cToPlace.xOrigin + cToPlace.sizeX) ; i++){
    for(j=cToPlace.yOrigin; j<(cToPlace.yOrigin + cToPlace.sizeY) ; j++){
      switch(board[i][j]){
        case 0:
          board[i][j] = cToPlace.Colour;
          break;
        case 1:
          if(cToPlace.Colour == 2)
            board[i][j] = 3;
          break;
        case 2:
          if(cToPlace.Colour == 2)
            board[i][j] = 3;
          break;
        case 3:
          break;
        }
    }
  }
}



void printBoard(int board[BOARDSIZE][BOARDSIZE])
{
  int i, j;
  printf("\n\nBoard: \n");

  for(i=0; i<BOARDSIZE; i++)
  {
    for(j=0; j<BOARDSIZE; j++)
      switch(board[i][j]){
        case 0:
          printf(" ");
          break;
        case 1:
          printf("B");
          break;
        case 2:
          printf("R");
          break;
        case 3:
          printf("P");
          break;
      }
    printf("\n");
  }
}

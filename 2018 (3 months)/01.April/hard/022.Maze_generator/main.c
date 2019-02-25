#include <stdio.h>
#include <stdlib.h>

#define SIZE 21

/*  0
 *1   2
 *  3
 * the board third coordenade is able to understadn 
 * current status of the graph
 *	10 is an undiged end, 11 a digged one
 * 0 is an undiged place, 1 a digged one
 *
 *	51111top111116 
 *  2            3
 *  2            3
 *  2            3
 *  2            3
 *  2            3
 *  74444444444448
 */

// This function checks if a move is avaible and in that case
// places the next coordinates on x2, y2, allowing to move
int possibleMove(int board[SIZE][SIZE][3],int randomMove, int x, int y, int *x2, int *y2){
//first, understanding meaning of the random number
	//corners
	if( x == 1 && y ==1){
		switch(randomMove){
			case 0:
				return 0;
				break;
			case 1:
				return 0;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}
	else if(x==1 && y == SIZE - 2){
		switch(randomMove){
			case 0:
				return 0;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				return 0;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}
	else if(x== SIZE - 2 && y == 1){
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				return 0;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				return 0;
				break;
		}
	}
	else if(x== SIZE - 2 && y== SIZE - 2){
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				return 0;
				break;
			case 3:
				return 0;
				break;
		}
	}
	//sides
	else if( x == 1 ){
		switch(randomMove){
			case 0:
				return 0;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}
	else if( y == SIZE - 2){
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				return 0;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}
	else if( y == 1){
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				return 0;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}
	else if(x== SIZE - 2){
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				return 0;
				break;
		}
	} else { //on the middle
		switch(randomMove){
			case 0:
				*x2 = x;
				*y2 = y -2;
				break;
			case 1:
				*x2 = x-2;
				*y2 = y;
				break;
			case 2:
				*x2 = x + 2;
				*y2 = y;
				break;
			case 3:
				*x2 = x;
				*y2 = y +2;
				break;
		}
	}

	int l;
	printf("%d %d %d %d %d board %d\n", x, y, randomMove, *x2, *y2, board[*x2][*y2][1]);
	//scanf("%d", &l);

	if(board[*x2][*y2][1]==0){
		board[*x2][*y2][1] = 1;
		//Make hole
		board[(*x2+x)/2][(*y2+y)/2][0] = 46;

		int i, j;
		for(i=0; i<SIZE; i++){
			printf("\n%d -\t",i);
			for(j=0; j<SIZE; j++){
				printf("%c", board[i][j][0]);
			}
		}
		return 1;

	} else {
		return 0;
	}
}

int move(int board[SIZE][SIZE][3], int x, int y){

	int x2, y2;
	int attemps = 0;
	int randomMove;

	if (board[x][y][1]==10){	//if we are in the top of the map
		return 0;
	}

	while(1){
		if(attemps == 4)
			break;
		randomMove = rand() % 4;

		if( possibleMove(board, randomMove, x, y, &x2, &y2) ){ //if we can move
			move(board,x2,y2);
		}
		attemps ++;
		//else() vamos a elegir otra vez
	}
}



void main(){

  srand(time(NULL));
  int board[SIZE][SIZE][3];
  int i, j;


  for(i = 0; i<SIZE; i++){
    for(j=0; j<SIZE; j++){
      if ( !(j%2==0 || i%2==0) &&
        !(j==0 || i==0 || i== SIZE-1 || j== SIZE-1) ){
        board[i][j][0]=46;
        board[i][j][1]=0;
      } else {
        board[i][j][0]=35;
      }
      board[i][j][1]=0;
    }
  }

  /*for(i = 0; i<SIZE; i++){
    for(j=0; j<SIZE; j++){
      if(i==1){	//TOP
        board[i][j][1]=3;
      }
      if(j==1){ //LEFT
        board[i][j][1]=3;
      }
      if(i==SIZE - 2){ //BOT
        board[i][j][1]=3;
      }
      if(j==SIZE - 2){ //RIGHT
        board[i][j][1]=3;
      }
      if(i==1 && j==1){  
        board[i][j][1]=2;
      }
      if(i==1 && j==SIZE - 2){
        board[i][j][1]=2;
      }
      if(j==1 &&i==SIZE - 2){
        board[i][j][1]=2;
      }

      if(i==SIZE - 2 && j==SIZE - 2){
        board[i][j][1]=2;
      }
		if(board[i][j][1]==0){
		board[i][j][1]=4;
		}
    }
  }*/

  board[1][0][0]=46;
  board[1][1][1] == 1;
  board[SIZE-2][SIZE-1][0]=46;
  board[SIZE-2][SIZE-2][1]=10;

	move(board, 1, 1);
	for(i=0; i<SIZE; i++){
		printf("\n%d -\t",i);
		for(j=0; j<SIZE; j++){
			printf("%c", board[i][j][0]);
		}
	}
}

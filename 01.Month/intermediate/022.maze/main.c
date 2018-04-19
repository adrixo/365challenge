#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define clear() printf("\033[H\033[J")


void initialize(int board[SIZE][SIZE], int x, int y){
	int i = 0, j= 0;

	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(i%2 == 0){
				board[i][j] = 46;
			} else if(j==2){
				board[i][j] = 46;
			}else {
				board[i][j] = 35;
			}
		}
	}
	board[x][y] = 79;
}

void printBoard(int board[SIZE][SIZE], int x, int y){
	int i = 0, j=0;
	clear();
	board[x][y] == 109;

	for(i=0; i<SIZE; i++){
		printf("\n%d -\t",i);
		for(j=0; j<SIZE; j++){
			printf("%c", board[i][j]);
		}
	}
	printf("x: %d y: %d\n",x,y);
}

void move(int current, int board[SIZE][SIZE], int *x, int *y){
	int xNew, yNew;
	switch(current){
		case 97:
			xNew = *x-1;
			yNew = *y;
			break;
		case 115:
			xNew = *x+1;
			yNew = *y;
			break;
		case 100:
			xNew = *x;
			yNew = *y+1;
			break;
		case 119:
			xNew = *x;
			yNew = *y-1;
			break;
		default:
			printf("Invalid\n");

			return;
	}
	if(xNew<0 || xNew>=SIZE || yNew<0 || yNew>SIZE){
		return;
	}
	if(board[xNew][yNew]==35){
		return;
	}
	board[xNew][yNew]==79;
	board[*x][*y]==46;
	printf("%c%c\n",board[xNew][yNew],board[*x][*y]);

	*x=xNew;
	*y=yNew;
}

void main(){

	char current ;
	int x = 0,y = 0;
	int board[SIZE][SIZE];

	printf("Wellcome to the fantastic maze game. \n");
	initialize(board,x,y);

	do{
		printBoard(board, x, y);
		scanf("%c",&current);
		move(current, board,&x,&y);
	} while(1);
}



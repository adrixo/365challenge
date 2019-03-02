#include <stdlib.h>
#include <stdio.h>

#define SIZE 20

void printBoard(char board[SIZE][SIZE]){
	int i, j;

	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

// This function needs to be fixed, adding more precision 
// only implemented for growing lines
void lineToDot(char board[SIZE][SIZE], int x1, int y1, int x2,int y2){
	float xDistance, yDistance;
	int i;
	int yGoingUp, aux;
	float count =1;

	xDistance = x1-x2;
	yDistance = y1-y2;

	yGoingUp = (int ) yDistance/xDistance;
	//precision lost problem 

	printf("%d\n",yGoingUp);
	aux = y1;

	for(i=x1; i<x2; i++){
		board[SIZE - aux][i] = '/';
		aux = y1 + (int ) yDistance/xDistance*count ;
		count++;
	}
	board[SIZE -y1][x1] = 'o';
	board[SIZE -y2][x2] = 'o';
}

void main(){
	int x1,x2, y1,y2;
	char board[SIZE][SIZE];
	int i,j;

	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if (i==0 || j==0 ) 
				board[i][j] = '#';
			else
				board[i][j]='.';
		}
	}

	printf("We have a nice board 20x20 \n\n");
	printf("Enter first x coordenade: ");
	scanf("%d", &x1);
	printf("Enter first y coordenade: ");
	scanf("%d", &y1);
	printf("Enter second x coordenade: ");
	scanf("%d", &x2);
	printf("Enter second y coordenade: ");
	scanf("%d", &y2);
	lineToDot(board, x1,y1,x2,y2);
	printBoard(board);

}

#include <stdlib.h>
#include <stdio.h>

#define SIZE 30
#define RINGS 50
#define INFOSIZE 20

/* Random meaning

general:			corner			side
	0				.	0	  |		0			j==0
1	.	2			1	.	  |		.	1
	3						  |		2
---------------------------------------------
					0	.	  |			2		j==size-1
					.	1	  |		1	.
							  |			0
---------------------------------------------
							  |			1		i==size-1
							  |		0	.	2
---------------------------------------------
							  |		2	.	0	i==0
							  |			1
		int possibleMoves
*/

void main(){
	srand(time(NULL));

	int grid[SIZE][SIZE][2]; //new and old flies
	int i, j;
	int move;
	int flie;

	int possibleMoves;
	int randomMove;

	int spaceInfo[INFOSIZE];

	for(i=0; i<SIZE;i++){
		for(j=0; j<SIZE;j++){
			grid[i][j][0] = 1;		//1 flea per square
			/*if(i==15&&j==15)
				grid[i][j][0] = 1;	//1 flea in the center
			else
				grid[i][j][0]=0;*/
			grid[i][j][1] = 0;
		}
	}

	printf("\e[96m"); //first print
	system("clear");
	for(i=0; i<SIZE;i++){
		for(j=0; j<SIZE;j++){
			printf(" %d ",grid[i][j][0]);		
		}
		printf("\n");
	}
	system("sleep 2");


	for(move=0; move<RINGS; move++){ //each ring flies jumps randomly
		for(i=0; i<SIZE;i++){
			for(j=0; j<SIZE;j++){
				if(grid[i][j][0] != 0){	//if there are flies
					for(flie=0;flie<grid[i][j][0];flie++){ //each flie
						possibleMoves = 4;
						if(i==0) //top
							possibleMoves--;
						if(j==0) //left
							possibleMoves--;
						if(j==(SIZE-1)) //right
							possibleMoves--;
						if(i==(SIZE-1)) //bottom
							possibleMoves--;

						randomMove = rand() % possibleMoves;

					//general
						if( i!=0 && j!=0 && j!=(SIZE-1) && i!=(SIZE-1)){
								switch(randomMove){
									case 0:
										grid[i-1][j-1][1]++;
										break;
									case 1:
										grid[i][j-1][1]++;
										break;
									case 2:
										grid[i][j+1][1]++;
										break;
									case 3:
										grid[i+1][j+1][1]++;
										break;
								}
						}

					//corners
						if( i==0 && j==0){
							switch(randomMove){
									case 0:
										grid[i][j+1][1]++;
										break;
									case 1:
										grid[i+1][j][1]++;
										break;
							}
							continue;
						}
						if( i==0 && j==(SIZE-1)){
							switch(randomMove){
									case 0:
										grid[i][j-1][1]++;
										break;
									case 1:
										grid[i+1][j][1]++;
										break;
							}
							continue;
						}
						if( i==(SIZE-1) && j==0){
							switch(randomMove){
									case 0:
										grid[i-1][j][1]++;
										break;
									case 1:
										grid[i][j+1][1]++;
										break;
							}
							continue;
						}
						if( i==(SIZE-1) && j==(SIZE-1)){
							switch(randomMove){
									case 0:
										grid[i-1][j][1]++;
										break;
									case 1:
										grid[i][j-1][1]++;
										break;
							}
							continue;
						}

					//sides
						if(j==0){
							switch(randomMove){
									case 0:
										grid[i-1][j][1]++;
										break;
									case 1:
										grid[i][j+1][1]++;
										break;
									case 2:
										grid[i+1][j][1]++;
										break;
							}
						}
						if(j==(SIZE-1)){
							switch(randomMove){
									case 0:
										grid[i+1][j][1]++;
										break;
									case 1:
										grid[i][j-1][1]++;
										break;
									case 2:
										grid[i][j-1][1]++;
										break;
							}
						}
						if(i==(SIZE-1)){
							switch(randomMove){
									case 0:
										grid[i][j-1][1]++;
										break;
									case 1:
										grid[i-1][j][1]++;
										break;
									case 2:
										grid[i][j+1][1]++;
										break;
							}
						}
						if(i==0){
							switch(randomMove){
									case 0:
										grid[i][j+1][1]++;
										break;
									case 1:
										grid[i+1][j][1]++;
										break;
									case 2:
										grid[i][j-1][1]++;
										break;
							}
						}

					}
					grid[i][j][0] = 0;
				}
			}
		}

		//move from old to new
		for(i=0; i<SIZE;i++){
			for(j=0; j<SIZE;j++){
				grid[i][j][0] = grid[i][j][1];		//1 flea per square
				grid[i][j][1] = 0;
			}
		}

		system("sleep 0.1");
		//print grid
		system("clear");
		for(i=0; i<SIZE;i++){
			for(j=0; j<SIZE;j++){
				if(grid[i][j][0]==0)
					printf("\e[90m "); //dark grey
				else {
					if(grid[i][j][0]==1)
						printf("\e[96m "); //light cyan
					if(grid[i][j][0]==2)
						printf("\e[36m "); //cyan
					if(grid[i][j][0]==3)
						printf("\e[34m "); //blue
					if(grid[i][j][0]>=4)
						printf("\e[35m "); //magenta
					if(grid[i][j][0]>=6)
						printf("\e[91m"); //red
				}
				printf("%d ",grid[i][j][0]);		//1 flea per square
			}
			printf("\n");
		}
		printf("\a");
	}

	for(i=0; i<INFOSIZE; i++){
		spaceInfo[i]=0;
	}

	for(i=0; i<SIZE;i++){
		for(j=0; j<SIZE;j++){
			spaceInfo[grid[i][j][0]]++;
		}
	}
	printf("\nSpaces\n");
	printf("\tUnoccupied : %d\t.%d\n", spaceInfo[0], spaceInfo[0]*1000/900);
	printf("\tNumber 1: %d\t\t.%d\n", spaceInfo[1], spaceInfo[1]*1000/900);
	printf("\tNumber 2: %d\t\t.%d\n", spaceInfo[2], spaceInfo[2]*1000/900);
	printf("\tNumber 3: %d\t\t.%d\n", spaceInfo[3], spaceInfo[3]*1000/900);
	printf("\tNumber 4: %d\t\t.%d\n", spaceInfo[4], spaceInfo[4]*1000/900);
	printf("\tNumber 5: %d\t\t.%d\n", spaceInfo[5], spaceInfo[5]*1000/900);
	printf("\tNumber 6: %d\t\t.%d\n", spaceInfo[6], spaceInfo[6]*1000/900);
	printf("\tNumber 7: %d\t\t.%d\n", spaceInfo[7], spaceInfo[7]*1000/900);
	printf("\tNumber 8: %d\t\t.%d\n", spaceInfo[8], spaceInfo[8]*1000/900);
	printf("\n\tTotal: %d\t\t.per-mille\n", spaceInfo[0]+spaceInfo[1]+spaceInfo[2]+spaceInfo[3]+spaceInfo[4]+spaceInfo[5]+spaceInfo[6]+spaceInfo[7]+spaceInfo[8]);
}






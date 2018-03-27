#include <stdlib.h>
#include <stdio.h>

#define LENGTH 40

/*
 * Recursive function that prints layer by layer the 
 * correspondent int array to build the piramid:
 * 1
 * 1 1
 * 2 1
 * 1 2 1 1
 * 1 1 1 2 2 1
 * 3 1 2 2 1 1
 *
 * layers: eligible on the first call
 * message: int array inicialized with first element 
 *			where empty cells = -1
 *
*/
void calcPiramid(int layers, int *message);

void main(){
	int message[LENGTH];
	
	for(int i=0;i<LENGTH; i++){
		message[i] = -1;
	}

	message[0]=1;

	printf("\n %d \n", message[0]);
	calcPiramid(10, message);
	
}

void calcPiramid(int layers, int *message){

	if(layers==0)
		return;

	//i message index 
	//j auxMessage index
	int i=0, j=0;

	// auxMessage inicialization
	int auxMessage[LENGTH];
	for(int i=0;i<LENGTH; i++){
		auxMessage[i] = -1;
	}

/*
 * For example on layers 3/4
 *
 * message:    		2' 			1"
 *			 [one] (two)' and [one] (one)"
 * auxMessage: [1]  (2)' 	   [1]   (1)"
 * 
 * where [n]: quantity of equal digits consecutives 
 * 		 (n): digit (int last)
 */

	int last=message[0];
	int quantity=0;

	while(message[i] != -1){

		if(last==message[i]){
			quantity++;

		} else {
			auxMessage[j] = quantity;
			auxMessage[j+1] = last;
			j += 2;
			quantity=1;
			last = message[i];
		}
		i++;
	}
	last = message[i-1]; 		//correction after while(-1)
	auxMessage[j] = quantity;	//adding the last one out of while
	auxMessage[j+1] = last;

//Printing layer
	printf("\n");
	i=0;
	while(auxMessage[i] != -1){
		printf(" %d ", auxMessage[i]);
		i++;
	}
	printf("\n");

//recursive call
	calcPiramid(layers -1, auxMessage);	
}

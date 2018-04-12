#include <stdlib.h>
#include <stdio.h>

void factorize(int number);

int isNumber(char number[]);

//global variable for the recursive function
int j = 2;

void main(int argc, char *argv[]){

	if(argc != 2){
		printf("Usage: %s <number>\n",argv[0]);
		exit(0);
	}

	if(!isNumber(argv[1])){
		printf("Error: %s is not a number. \n", argv[1]);
		exit(0);
	}

	printf("%d: ", atoi(argv[1]));
	factorize(atoi(argv[1]));
	printf("\n");
}

void factorize(int number){

	if(number<=1){
		return;
	}

	if(number%j == 0){
		printf(" %d ",j);
		number=number/j;
	} else{
		j++;
	}

	factorize(number);
}

int isNumber(char number[]){

	int i = 0;

	if(number[0] == '-')
		i = 1;

	for (; number[i] != 0; i++){
		if (!isdigit(number[i]))
			return 0;
	}
	return 1;
}

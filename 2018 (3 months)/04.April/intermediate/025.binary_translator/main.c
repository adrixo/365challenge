#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Reused function from 012.factor_a_number*/
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


/*2 solutions*/
//first one, it makes a fake binary: in fact is a decimal working as binary
int passToBin(int num){
	int pos=1;
	int fakeBinary = 0;
	while(num != 0){
		if(num == 0){
			fakeBinary += pos;
			break;
		}
		if(num%2 == 1)
			fakeBinary += pos;
		num = num/2;
		pos*=10;
	}

	return fakeBinary;
}

// second one, i tried to implement something similar;
// but i found this: https://stackoverflow.com/questions/7911651/decimal-to-binary
void getBinary(int num, char *str){
	*(str+5) = '\0';
	int mask = 0x10 << 1;
	while(mask>>=1)
		*str++ = !!(mask & num) + '0';
}

void main( int argc, char *argv[]){

	if(argc != 2){
		printf("Usage: %s <number>\n",argv[0]);
		exit(0);
	}

	if(!isNumber(argv[1])){
		printf("Error: %s is not a number. \n", argv[1]);
		exit(0);
	}

	char solution[32];

	getBinary(atoi(argv[1]), solution);
	int binary = passToBin(atoi(argv[1]));

	printf("%s\n%d\n",solution, binary);
}

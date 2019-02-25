#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCALE 10000
#define ARRINIT 2000

void main( int argc, char *argv[]){


	if(argc != 2){
		printf("Usage: %s <Number>\n",argv[0]);
		exit(0);
	}

	/* check parameter has only numbers */
	char *ptr = argv[1];
	while (*ptr){
		if( !(*ptr >= 0x30 && *ptr <=0x39) ){
			printf("Error: No es un integer: %s\n", argv[1]);
			exit(0);
		}
		ptr++;
	}

	int digits = atoi(argv[1]);

	/*http://www.codecodex.com/wiki/Calculate_digits_of_pi*/

	int carry = 0;
	int arr[digits + 1];
	for( int i = 0; i <= digits; ++i)
		arr[i] = ARRINIT;
	for (int i = digits; i > 0; i-= 14){
		int sum = 0;
		for (int j = i; j > 0; --j) {
			sum = sum * j + SCALE * arr[j];
			arr[j] = sum % (j * 2 - 1);
			sum /= j * 2 - 1;
		}
	 	printf("%04d", carry + sum / SCALE);
		carry = sum % SCALE;
	}

	printf("\n");
}

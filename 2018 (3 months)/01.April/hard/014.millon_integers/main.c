/* http://man7.org/linux/man-pages/man7/pthreads.7.html
 * Posix threads - man pthreads
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthreads.h>


#define SIZE 1000000

int main(int argc, char argv[]){

	if(argc != 2){
		printf("Usage: %s <number of threads>\n",argv[0]);
		exit(0);
	}

	int numbers[SIZE];

	srand(time(NULL));

	for(i =0; i<SIZE; i++){
		numbers[i] = rand();
	}

}



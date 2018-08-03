//#https://en.wikipedia.org/wiki/Linear-feedback_shift_register

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <sys/time.h>

#define SAMPLES 5

int genRand(long long seed, int selection);
int linear_feedback_shift_register(long long seed, int selection);

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}


void main()
{
	int selection, i=0;
	long long timeInt;

	printf("Random Range 0-N:\n\nN = ");
	scanf("%d", &selection);

	int generatedNumber[SAMPLES][2];

	while(i<SAMPLES)
	{
		timeInt = current_timestamp()%2000;
		generatedNumber[i][0] = genRand(timeInt, selection);
		generatedNumber[i][1] = linear_feedback_shift_register(timeInt, selection);
		//printf("\n%d\n",generatedNumber[i][1] );

		if(i == 0)
		{
			printf("My generator: %d\n", 	generatedNumber[i][0]);
			printf("LFSR generator: %d\n\n", generatedNumber[i][1]);
			//printf("timeInt: %lld\n\n", timeInt);
		}

		i++;
		sleep(1);
	}

	//checking our functions
	int averrage[selection][2];			//printf("timeInt: %lld\n\n", timeInt);

	for(i=0; i<selection; i++){
		averrage[i][0] = 0;
		averrage[i][1] = 0;
	}

	for(i=0; i<SAMPLES; i++){
		averrage[generatedNumber[i][0]][0]++;
		averrage[generatedNumber[i][1]][1]++;
	}

	printf("Number of samples: %d\n",SAMPLES);
	for(i=0; i<selection; i++){
		printf("%d:",i);
		printf(" My generator statistics: %d\t", averrage[i][0]);
		printf("LFSR statistics: %d\n", averrage[i][1]);
	}
}

int genRand(long long seed, int selection)
{ //Using prime
	long long randNumber;
	randNumber = (seed*8311)+1;
	randNumber = randNumber % selection;

	return (int) randNumber;
}

int linear_feedback_shift_register(long long seed, int selection)
{
	u_int16_t start_state = (u_int16_t) seed;
	u_int16_t lfsr = start_state;
	unsigned period = 0;

	do {
		unsigned lsb = lfsr & 1;
		lfsr >>= 1;
		if (lsb)
			lfsr ^= 0xB400u;
		++period;
	} while (lfsr != start_state);

	return lfsr%selection;
}

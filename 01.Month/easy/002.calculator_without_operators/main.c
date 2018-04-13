//Original idea: dailyprogrammer
#include <stdlib.h>
#include <stdio.h>

int add(int x, int y);
int multiply(int x, int y);
int subtrack(int x, int y);
int divide(int dividend, int divisor);

void getOperator(int *x, int i);

void main(void){
	int option =-1;
	int x,y;

	while(option){
		printf("CALCULATOR \n\n\t1) Add\n\n\t2) Multiply\n\n\t3) subtrack\n\n\t4) divide\n\n\t0) exit\n\nOpcion: ");
		scanf("%d",&option);

		switch(option){
			case 1:
				getOperator(&x,1);
				getOperator(&y,2);
				printf("%d + %d = %d \n", x, y, add(x,y));
				break;
			case 2:
				getOperator(&x,1);
				getOperator(&y,2);
				printf("%d * %d = %d \n", x, y, multiply(x,y));
				break;

			case 3:	
				getOperator(&x,1);
				getOperator(&y,2);
				printf("%d - %d = %d \n", x, y, subtrack(x,y));
				break;
			case 4:
				getOperator(&x,1);
				getOperator(&y,2);
				printf("%d / %d = %d \n", x, y, divide(x,y));
				break;
			default:
				break;
		}
	}
}

void getOperator(int *x, int i){
	printf("operator %d: ", i);
	scanf("%d",x);
}

//without using * operator
//Half_adder logic
int add(int x, int y){
	int sum, carry;
	if ( y == 0)
		return x;
	sum = x ^ y;
	carry = (x & y) << 1;

	return add(sum, carry);
}

int multiply(int x, int y){
	int aux = 0;
	while(y != 0){
		aux = add(aux,x);
		y --;
	}

	return aux;
}

int subtrack(int x, int y){
	return add(x, -y);
}

//https://stackoverflow.com/questions/5386377/division-without-using
//interesting
int divide(int dividend, int divisor){
	int denom = divisor;
	int current = 1;
	int answer = 0;

	if(denom > dividend)
		return 0;
	if(denom == dividend)
		return 1;
	
	while(denom <=dividend) {
		denom <<=1;
		current <<=1;
	}

	denom >>= 1;
	current >>= 1;

	while (current != 0) {
		if (dividend >= denom){
			dividend -= denom;
			answer |= current;
		}
		current >>= 1;
		denom >>= 1;
	}
	return answer;
}







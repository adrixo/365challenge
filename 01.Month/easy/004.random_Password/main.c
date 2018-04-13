#include <stdlib.h>
#include <stdio.h>

void main(){
	int lenght;
	int random, i;
	char *pass;

	srand(time(NULL));
	printf("Lenght: ");
	scanf("%d", &lenght);

	for( i = 0; i<lenght; i++){
		random = rand() % 59;
		
		if(random>=34){
			random += 63;
		} else if( random >= 9){  	
			random += 56;
		} else{
			random +=48;
		}

		pass[i] = random;
	}
	pass[i+1]=0;

	i=0;
	while(pass[i]!='\0'){
		printf("%c",pass[i]);
		i++;
	}
	printf("\n");
}

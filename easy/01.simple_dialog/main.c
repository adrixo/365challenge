#include <stdio.h>
#include <stdlib.h>

#define ARRAYSLENGTH 20

void main(void){

	char *name, username[ARRAYSLENGTH];
	int age;

	FILE *f;

	printf("Enter your name: ");
	scanf("%s",&name);
	printf("Enter your age: ");
	scanf("%d",&age);
	printf("Enter your username: ");
	scanf("%s",&username);

	//saving the information
	printf("Your name is %s, you are %d years old, and your nickname is @%s.\n", &name, age,username);

	f = fopen("info.log", "w");
	if(f == NULL){
		printf("Error opening file\n");
		exit(1);
	}

	fprintf(f,"Your name is %s, you are %d years old, and your nickname is @%s.\n", &name, age,username);

	fclose(f);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE 20

void encrypt(char *message);
void decrypt(char *message);

void main( int argc, char *argv[]){

	
	if(argc != 3){
		printf("Usage: %s <encrypt|decrypt> <message>\n",argv[0]);
		exit(0);
	}

	if( !(strcmp(argv[1], "encrypt")==0 || strcmp(argv[1], "decrypt")==0)){
		printf("Error: invalid argument: %s\n", argv[1]);
		exit(0);
	}

	if(!strcmp(argv[1], "encrypt")){
		printf("Encrypting %s...\n", argv[2]);
		encrypt(argv[2]);
		printf("The array is crypted: %s\n", argv[2]);
	}
	else {
		printf("Decrypting %s...\n", argv[2]);
		decrypt(argv[2]);
		printf("The array is decrypted: %s\n", argv[2]);
	}
}

void encrypt(char * message){
	int length = strlen(message);
	int i;

	for(i=0; i<length; i++){
		message[i] += CODE;
	}
}

void decrypt(char * message){
	int length = strlen(message);
	int i;

	for(i=0; i<length; i++){
		message[i] -= CODE;
	}
}


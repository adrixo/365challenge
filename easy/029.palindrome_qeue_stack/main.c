#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "queue.c"
#include "stack.h"
#include "stack.c"

int main(){
	char sentence[100];
	int i, flag=1;
	elementType auxStack, auxQueue;
	Queue c;
	Stack p;
	
//Creation
	printf("We will check if something is palindrome: ");
	scanf("%s",&sentence);

	if(createStack(&p) == -1)
		return -1;
	if(queueCreateVoid(&c) == -1)
		return -1;
		
	for( i = 0; i<strlen(sentence); i++){
		if(queueInsert(&c, sentence[i])==-1)
			return -1;
		if(stackInsert(&p, sentence[i])==-1)
			return -1;
	}

//Results
	for( i=0; i<strlen(sentence); i++ ){

		auxQueue = queueDelete(&c);
		if(auxQueue==-1)
			return -1;
		auxStack = stackDelete(&p);
		if(auxStack==-1)
			return -1;
		if(auxStack != auxQueue){
			flag = 0;
		}
	}

	if(flag)
		printf("%s its a palindrome. \n",sentence);
	else
		printf("%s it's not a palindrome. \n",sentence);
		
	return 0;
}

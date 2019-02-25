
int createStack(Stack *p){

	*p = (Stack) malloc(sizeof(Stack*));
	if(*p == NULL)
		return -1;

	(*p)->element = -1;
	(*p)->sig = NULL;
	return 0;
}

int stackIsEmpty(Stack *p){
	if( (*p)->sig == NULL )
		return 1;
	return 0;
}

int stackInsert(Stack *p,elementType element){

	Stack newCeld;
	newCeld = (Stack) malloc(sizeof(Stack*));
	if(newCeld==NULL)
		return -1;

	newCeld->sig = *p;
	newCeld->element = element;
	*p = newCeld;
	return 0;
}

elementType stackDelete(Stack *p){
	elementType temp;
	Stack deleted;
	if(stackIsEmpty(p))
		return -1;
	
	temp = (*p)->element;
	deleted = (*p);
	*p = (*p)->sig;
	free(deleted);
	return temp;
}





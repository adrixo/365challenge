int queueCreateVoid(Queue *c){
	if( (c = ( Queue * )malloc(sizeof(Queue))) == NULL){
		printf("Error: queue malloc. \n");
		return -1;
	} else  {
        c->front = NULL;
        c->end = NULL;
        return 0;
    }
}

int queueIsEmpty(Queue *c){
	if (c->front == NULL && c->end == NULL){
		return 1;
	} else {
		return 0;
	}
}

int queueInsert(Queue *c, elementType element){

	celdType * newCeld;
	newCeld = (celdType *)malloc(sizeof(celdType));
	
	if(newCeld == NULL){
		printf("Error: insert malloc. \n");
		return -1;
	}
	
	newCeld->element = element;
	newCeld->sig = NULL;
	
	if(queueIsEmpty(c)){
		c->front=newCeld;
		c->end = newCeld;
	} else {
		c->end->sig = newCeld;
		c->end = newCeld;
	}

	return 0;
}

elementType queueDelete(Queue *c){

	celdType * temp;
	elementType deletedElement;
	
	if(queueIsEmpty(c)){
		printf("Error: queue empty when deleting.\n");
		return -1;
	}

	temp = c->front;
	deletedElement = temp->element;
	c->front = c->front->sig;
	free(temp);
	return deletedElement;
	
}












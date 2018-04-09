#ifndef __COLA_H
#define __COLA_H

//A queue is just a LIFO data structure

typedef int elementType;

typedef struct celdType { 
	elementType element; 
	struct celdType * sig; 
	} celdType;

typedef struct {
        celdType *front, *end;
} Queue;

int queueCreateVoid(Queue *c);

int queueIsEmpty(Queue *c);

int queueInsert(Queue *c, elementType element);

elementType queueDelete(Queue *c);

#endif

#ifndef __PILA_H
#define __PILA_H
	
typedef celdType * Stack;

int createStack(Stack *p);

int stackIsEmpty(Stack *p);

int stackInsert(Stack *p,elementType element);

elementType stackDelete(Stack *p);


#endif

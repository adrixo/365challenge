#include <stdio.h>
#include <stdlib.h>

typedef struct maxiphobicHeap {
  int key;
  int value;
  struct maxiphobicHeap *leftNode;
  struct maxiphobicHeap *rightNode;
} maxiphobicHeap;

int findMinimun(maxiphobicHeap * root);
maxiphobicHeap * delMin(maxiphobicHeap * root);
int size(maxiphobicHeap * root);

maxiphobicHeap * insert(int value,maxiphobicHeap * root);
maxiphobicHeap * merge(maxiphobicHeap * left, maxiphobicHeap * right);


void main(void)
{

}

int findMinimun(maxiphobicHeap * root)
{
  if(root == NULL)
    return -1;
  return root.value;
}

maxiphobicHeap * delMin(maxiphobicHeap * root)
{
  if(root == NULL)
    return NULL;
  return merge(root.leftNode, root.rightNode);
}

int size(maxiphobicHeap * root)
{
  int sizeL, sizeR;
  if(root == NULL)
    return 0;

  return 1 + size(root.leftNode) + size(root.rightNode);
}

maxiphobicHeap * insert(int value, maxiphobicHeap * root)
{
  maxiphobicHeap * new;
  new = (maxiphobicHeap *) malloc(1*sizeof(maxiphobicHeap));
  if(new==NULL)
    return NULL;

  new.value = value;
  new.leftNode = NULL;
  new.rightNode = NULL;
  return merge(root, new);
}

maxiphobicHeap * merge(maxiphobicHeap * left, maxiphobicHeap * right)
{
  maxiphobicHeap * aux;
  maxiphobicHeap * a,b,c;

  if(left == NULL)
    return right;
  if(right == NULL)
    return left;

  if(left.value < right.value)
  {
    aux = left;
    left = right;
    right = aux;
  }

  a = left.leftNode;
  b = left.rightNode;
  c = right;

  if( size(b) > size(a) )
  {
    aux = a;
    a = b;
    b = aux;
  }
  if( size(c) > size(a) )
  {
    aux = a;
    a = c;
    c = aux;
  }

  left.leftNode = a;
  left.rightNode = merge(b,c);
  return left;

}

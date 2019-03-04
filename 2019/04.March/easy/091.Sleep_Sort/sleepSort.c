
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define TAM 10

struct args {
  int pN;
  int sort;
};

void *sleepAndPrint(void * arg){
  int x = ((struct args*)arg)->sort;
  int i = ((struct args*)arg)->pN;

  sleep(x);
  printf("- %d\n", x);
}

void main(void){
  int i, r;
  int numbers[TAM];
  pthread_t thread_id[TAM];

  struct args *value = (struct args *)malloc(sizeof(struct args));

  for(i=0; i<TAM; i++){
    printf("Enter the number %d/%d: ", i, TAM);
    scanf("%d", &r);
    numbers[i] = r;
  }

  for(i=0; i<TAM; i++){
    value->pN = i;
    value->sort = numbers[i];
    pthread_create(&thread_id[i], NULL, sleepAndPrint, (void *)value );
  }

  for(i=0; i<TAM; i++){
    pthread_join(thread_id[i], NULL);
  }
}

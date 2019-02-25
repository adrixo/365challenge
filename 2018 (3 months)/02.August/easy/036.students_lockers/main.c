
#include <stdio.h>
#include <stdlib.h>

#define NLOCKERS 1000

void not(int * status);

void main()
{
  int locker[NLOCKERS];
  int i,j;
  
  //inicialization
  for(i=0; i<NLOCKERS; i++){
    locker[i] = 0;
  }

  //Students doing student stuff
  for(i=1; i<NLOCKERS;i++){
    for(j=i;j<NLOCKERS;j+=i){
      not(&locker[j]);
    }
  }

  //Presentation
  for( i=0; i<NLOCKERS; i++){
    if(locker[i])
      printf("%d\t", i);
  }
}

void not(int * status)
{
  if( *status==0)
    *status = 1;
  else
    *status = 0;
}

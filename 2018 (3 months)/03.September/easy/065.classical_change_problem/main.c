#include <stdlib.h>
#include <stdio.h>


#define NCOINS 9
int coin_dictionary[NCOINS] = {10000,5000,1000,500,100,25,10,5,1};


int * minimunCoinChange(int *coin_dictionary, int elements, int amount){
 int i;

 if(coin_dictionary[elements-1] > amount)
   return NULL;

 int * coins = (int *) calloc ( elements, sizeof(int));


 for(i=0; i<elements; i++)
   while(amount >= coin_dictionary[i])
   {
     amount = amount - coin_dictionary[i];
     coins[i]++;
   }

 return coins;
}

void main(void){
  int *result;
  int amount, i;

  printf("\nCoins in use: [ ");
  for(i=0; i<NCOINS-1; i++)
    printf(" %d, ", coin_dictionary[i]);
  printf("%d ]\nEnter the amount: ", coin_dictionary[NCOINS-1]);
  scanf("%d",&amount);

  result = minimunCoinChange(coin_dictionary, NCOINS, amount);

  printf("\nResult: \n");
  for(i=0; i<NCOINS; i++)
    printf(" %20d$ x%d \n", coin_dictionary[i], result[i]);
  printf("\n");

}

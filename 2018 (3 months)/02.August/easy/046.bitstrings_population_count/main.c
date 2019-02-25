#include <stdio.h>
#include <stdlib.h>

typedef union{
  long int number;
  struct{
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
  }bit;
}Bitstring;

void main(){
  Bitstring bitstr;
  int n1 = 0;

  printf("Enter a number: ");
  scanf("%ld", &bitstr.number);
  printf("Your number is %d and in binary is: ", bitstr.number);
  printf(" %d %d %d %d %d %d %d %d \n", bitstr.bit.bit7, bitstr.bit.bit6, bitstr.bit.bit5, bitstr.bit.bit4, bitstr.bit.bit3, bitstr.bit.bit2, bitstr.bit.bit1, bitstr.bit.bit0  );

  n1 = bitstr.bit.bit7 + bitstr.bit.bit6 + bitstr.bit.bit5 + bitstr.bit.bit4 + bitstr.bit.bit3 + bitstr.bit.bit2 + bitstr.bit.bit1 + bitstr.bit.bit0;
  printf("The bitsTring number is %d\n", n1);
}

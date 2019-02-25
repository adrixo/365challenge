sal/*
 * Se hizo algo similar en: 01.April/easy/002.calculator_without_operators
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int and(unsigned int a,unsigned int b)
{
  return a&b;
}

unsigned int or(unsigned int a,unsigned int b)
{
  return a|b;
}

unsigned int xor(unsigned int a,unsigned int b)
{
  return a^b;
}

unsigned int not(unsigned int a)
{
  return (~a);
}

unsigned int left(unsigned int a,unsigned int b)
{
  return a<<b;
}

unsigned int right(unsigned int a,unsigned int b)
{
  return a>>b;
}



unsigned int add(unsigned int a,unsigned int b)
{
  unsigned int carryAux; //para manejar el desplazamiento del carry
  unsigned int carry = a&b; //Si son 1 en el mismo digito de a y b, se producirá carry
  unsigned int result = a^b; //or exclusivo si esta en uno y en otro no, ahí quedaría un 1

  //Solucionamos los casos en los que el carry "pasaría hacia la izquieda"
  while(carry != 0)
  {
    carryAux = carry<<1;
    carry = result & carryAux;
    result ^= carryAux;
  }

  return result;
}

unsigned int substract(unsigned int a, unsigned int b)
{
  return add(a, -b);

  //Tambien encontre otro metodo interesante
  while(b!=0)
  {
    int borrow = (~a) & b;
    a = a ^ b;
    b = borrow << 1;
  }
  return a;
}

//Basado en la multiplication rusa
unsigned int multiplication(unsigned int a, unsigned int b)
{
    int result = 0;

    while (b > 0)
    {
         if (b & 1) //Si es impar o primer bit activado
         {
           result = add(result, a);
           //printf("%d\n",a);//"Subdivide" en el numero
         }

         //multiplica por dos siempre, si es impar lo suma
         a <<= 1;
         //divide por dos siempre, redondeando a la baja en caso de impar
     }
     return result;
}

unsigned int divide(unsigned int a, unsigned int b)
{
    int result = 0;

    while (b > 0)
    {
         if (b & 1) //Si es impar o primer bit activado
         {
           result = add(result, a);
           //printf("%d\n",a);//"Subdivide" en el numero
         }

         //multiplica por dos siempre, si es impar lo suma
         a <<= 1;
         //divide por dos siempre, redondeando a la baja en caso de impar
     }
     return result;
}

unsigned int pow(unsigned int a, unsigned int b)
{
  return b;
}

void main(void)
{
  int a=5,b=7;

  while(1){
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    printf("%d&%d=%d\n",a,b,and(a,b));
    printf("%d|%d=%d\n",a,b,or(a,b));
    printf("%d^%d=%d\n",a,b,xor(a,b));
    printf("~%d=%d\n",a,not(a));
    printf("%d<<%d=%d\n",a,b,left(a,b));
    printf("%d>>%d=%d\n",a,b,right(a,b));
    printf("\n\n");
    printf("%d+%d=%d\n",a,b,add(a,b));
    printf("%d-%d=%d\n",a,b,substract(a,b));
    printf("%d*%d=%d\n",a,b,multiplication(a,b));
    printf("%d^%d=%d\n",a,b,divide(a,b));
    printf("%d^%d=%d\n",a,b,pow(a,b));

  }
}

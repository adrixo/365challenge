#!/usr/bin/python

import sys
import datetime


"""
we can avoid a lot operations if we realise of:
                            | number
              |50% 	/2 		  divisors
        |33% 		/3
    |25% 			/4

for number in range(3,int(rang)+1,2):
        

        if number%2 == 0 or number%3 == 0:
            isPrime = False
		else
            for divisor in range(2,number/4):
                if number%divisor == 0:
                    isPrime = False
                    break

        if isPrime:
            print(number)
            numberOfPrimes += 1

        isPrime = True
#########
we execute this in 15 seconds (36 before)

#########
but implementing a list with the last prime numbers:
	only 3 seconds

"""

def calcPrimeNumbers(rang):
    print("Calculating prime numbers up to "+ rang +"...")
    
    isPrime = True
    numberOfPrimes = 1

    print('2')

    listaPrimos = [2]
    for number in range(3,int(rang)+1,2):
        
        for divisor in listaPrimos:
            if number%divisor == 0:
                isPrime = False
                break

        if isPrime:
            print(number)
            listaPrimos.append(number)
            numberOfPrimes += 1

        isPrime = True
    
    return numberOfPrimes

if len(sys.argv) != 2 :
    print('Error: usage python primeNumbers.py <number>')
    sys.exit(0)

time = datetime.datetime.now()
primes = calcPrimeNumbers(sys.argv[1])

time = datetime.datetime.now() - time
print("Done! -> " + str(primes) + " numbers in "+str(time))

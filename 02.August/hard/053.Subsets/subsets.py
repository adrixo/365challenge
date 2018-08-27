#!/usr/bin/python
import itertools

def getPrimeNumbers(rang):

    primeList = [2]

    isPrime = True
    for number in range(3,int(rang)+1,2):
        for divisor in primeList:
            if number%divisor == 0:
                isPrime = False
                break

        if isPrime == True:
            primeList.append(number)
        isPrime = True

    return primeList

n = int(input("Enter a number for primes: "))
maximun = int(input("Enter the maximun: "))

primes = getPrimeNumbers(n)

possibilities = list(itertools.combinations(primes, 2))

winner = [(1,1)]
winnerProduct = 1
for i in range(len(possibilities)):
    attemp = possibilities[i][0] * possibilities[i][1]
    if attemp < maximun and attemp > winnerProduct:
        winner = possibilities[i]
        winnerProduct = attemp

print(winner, winnerProduct)

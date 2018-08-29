#!/usr/bin/python
import random

# From 053:
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

def gcd(a,b):
    while b > 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

primeNumbers = getPrimeNumbers(150)
distinctPrimeNumbers = random.sample(primeNumbers,2)
print("The prime numbers used: ",distinctPrimeNumbers)

#1 2 distinct prime numbers
p = distinctPrimeNumbers[0]
q = distinctPrimeNumbers[1]
#2 copmute n = pq
n = p * q
#3 lcm ""A(n)""
Nlcm = lcm(p-1,q-1)
#4 Choose any number 1<e<Nlcm that is coprime to Nlcm
# Coprime: They have no common prime factors
coprimeNotFound = True
while(coprimeNotFound):
    e = random.randint(2,Nlcm)
    if gcd(Nlcm,e) == 1:
        coprimeNotFound = False

#5 compute d, the modular multiplicative inverse of e(mod A(n)) yielding
dNotFound = True
d = 0
while(dNotFound):
    if (d*e % Nlcm) == 1:
        dNotFound = False
    d += 1

# print(p,q,n,Nlcm,e,d)
#PUBLIC KEY - n, e
#ENCRIPTION FUNCTION :
#c(m) = m^e mod n
def ENCRIPT(m,n,e):
    encripted = pow(m,e) %n
    return encripted

#PRIVATE KEY - n, d
#ENCRIPTION FUNCTION :
# m(c) = c^d mod n
def DECRIPT(c,n,d):
    decripted = pow(c,d) %n
    return decripted

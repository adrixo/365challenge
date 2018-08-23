#!/usr/bin/python

def countDigit1(number):
    ones = 0
    for i in range(number):
        aux = i
        while aux > 0:
            if(aux%10 == 1):
                ones += 1
            aux = int(aux /10)
    return ones

def countDigitParsingString(number):
    ones = 0
    for i in range(number):
        aux = str(i)
        for i in range(len(aux)):
            if aux[i] == "1":
                ones += 1
    return ones

#def countRecursively(number):
#    if number == 0:
#        return 0
#    one = 0
#    if number%10 == 1:
#        one = 1
#    return one + countRecursively(number/10)

number = int(input("Enter a number: "))

ones = countDigit1(number)
print("Using 1s function:",ones)

ones = countDigitParsingString(number)
print("Using 2s function:",ones)

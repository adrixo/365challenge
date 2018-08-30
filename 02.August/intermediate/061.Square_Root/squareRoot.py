#!/usr/bin/python

#https://en.wikipedia.org/wiki/Methods_of_computing_square_roots

def sqrtBabylonian(number, number2, iterations):
    if iterations == 0:
         #get digits
        digits = 0
        auxNumber = number
        while (auxNumber > 0):
            auxNumber = auxNumber//10
            digits = digits + 1

        number2 = digits * pow(10,2)
        iterations += 1
        return sqrtBabylonian(number, number2, iterations)

    else:
        root = 0.5*(number2 + number/number2)
        if(iterations == 6):
            return root
        else:
            iterations += 1
            return sqrtBabylonian(number, root, iterations )

number = int(input("Enter a number: "))
root = sqrtBabylonian(number,0,0)
print("The square root is: ",root)

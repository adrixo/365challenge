#!/usr/bin/python


print("Binomial product calculator.")
binomial = input("Enter a product. P. Ej (2x+4)(3x-5): ")

binomial = binomial.replace('(','')
binomial = binomial.split(')')

first = binomial[0].split('x')
second = binomial[1].split('x')
print(first, second)

x2 = int(first[0]) * int(second[0])
x1 = int(first[0]) * int(second[1]) + int(first[1]) * int(second[0])
x0 = int(first[1]) * int(second[1])

signed_1 = signed_2 = ''
if(x1 >= 0):
    signed_1 = '+'
if(x0 >= 0):
    signed_2 = '+'

result = str(x2)+"x²" + signed_1+str(x1)+"x" +  signed_2+ str(x0)
print(result)

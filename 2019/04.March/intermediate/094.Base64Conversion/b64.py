#!/usr/bin/python

import itertools

# A-Z = 65-90
# a-z = 97-122
# 0-; = 48-59

code = [chr(i) for i in range(65,91)] + [chr(i) for i in range(97,123)] + [chr(i) for i in range(48, 60)]

print("Enter a sentence: ")
sentence = input()

def pairwise(iterable):
    a = iter(iterable)
    return zip(a, a, a)

crypted = ""
for x, y, z in pairwise(sentence):
    suma = (ord(x)<<16)+(ord(y)<<8) + ord(z)
    toAdd = ""
    while suma > 0:
        new = suma % 64
        suma = suma //64
        toAdd = code[new] + toAdd
    crypted += toAdd

print("Cryped: "+crypted)

#!/usr/bin/python

import sys
from math import factorial

if len(sys.argv) != 8:
    print("Usage: \n\t./program blocks_sent error_probability n detection_capacity correction_capacity")
    exit()

def combinatorial(m, n):
    return factorial(m) // (factorial(n) * factorial(m - n))

def success_probability(errorP,n,p):
    total = 0
    total = combinatorial(n,0)*(p**0)*(1-p)**(n-0)
    for i in range(1,errorP):
        total += combinatorial(n,i)*(p**i)*(1-p)**(n-i)
    return total

sent_blocks = int(sys.argv[1])
error_probability = float(sys.argv[2])
n = int(sys.argv[3])
detection_capacity = int(sys.argv[4])
correction_capacity = int(sys.argv[5])


totalDeteccion = success_probability(detection_capacity, n, error_probability)
total = (totalDeteccion)**(sent_blocks)
totalCorreccion = success_probability(correction_capacity, n, error_probability)

print( totalDeteccion, totalCorreccion, total)

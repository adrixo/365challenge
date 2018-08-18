#!/usr/bin/python

#https://en.wikipedia.org/wiki/Trabb_Pardo%E2%80%93Knuth_algorithm
#
# ask for 11 numbers to be read into a sequence S
# reverse sequence S
# for each item in sequence S
#     call a function to do an operation
#     if result overflows
#         alert user
#     else
#         print result

#taking the code from wikipedia
import math

f = lambda t: math.sqrt(abs(t)) + 5 * t ** 3
#eq to
#def t:
#   x = sqrt(abs(t)) + 5 * t **3
#   return x
a = [float(input("input: ")) for _ in range(11)]

for t in reversed(a):
    y = f(t)
    print('TOO LARGE' if y > 400 else y)

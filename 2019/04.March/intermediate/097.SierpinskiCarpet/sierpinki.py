#!/usr/bin/python

#1
import pandas as pd
import numpy as np
import sys

import seaborn as sns
import matplotlib.pyplot as plt

#https://nikkimarinsek.com/blog/7-ways-to-label-a-cluster-plot-python

def isSierpinskiCarpetPixelFilled(x, y):
    while (x > 0 or y > 0):
        if (x % 3 == 1 and y % 3 == 1):
            return True
        x = x // 3
        y = y // 3
    return False

X = [[],[]]
#f = lambda t: math.sin(t)

if len(sys.argv) == 1:
    exit()
size = int(sys.argv[1])
size = 3**size

for i in range(size):
    for j in range(size):
        if isSierpinskiCarpetPixelFilled(i,j):
            X[0].append(i)
            X[1].append(j)

plt.scatter ( X[ 0 ] ,X [ 1 ] )
plt.show ()

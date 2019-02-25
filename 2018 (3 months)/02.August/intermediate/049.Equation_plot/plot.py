#!/usr/bin/python
import math
import numpy as np
import matplotlib.pyplot as plt

f = lambda t: math.sin(t)
X = [[],[]]

for i in np.arange(0.0, 10.0, 0.1):
    X[0].append(i)
    X[1].append(f(i))
    
plt.scatter ( X[ 0 ] ,X [ 1 ] )
plt.show ()

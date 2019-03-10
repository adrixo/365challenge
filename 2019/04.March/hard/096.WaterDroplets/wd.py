#!/usr/bin/python

import numpy as np
import sys
import matplotlib.pyplot as plt
import time
import random


N = random.randint(2, 100)
print("Number of droplets: ", N)

np.random.seed(int(time.time()))

x = np.random.rand(N)
y = np.random.rand(N)
colors = (0.64352 + np.random.rand(N)**0)
area = (30 * np.random.rand(N))**2  # 0 to 15 point radii

plt.scatter(x, y, s=area, c=colors)#, alpha=0.5)
object_methods = [method_name for method_name in dir(plt) ]
object_methods2 = [method_name for method_name in dir(object) if callable(getattr(object, method_name))]

print(len(object_methods),len(object_methods2), colors)
print("\n\nWithout if")
#for i in object_methods:
    #print(i)
print("\n\nWith if")
#for j in object_methods2:
    #print(j)

plt.show()

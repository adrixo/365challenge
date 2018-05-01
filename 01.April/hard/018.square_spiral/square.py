import numpy as np
import matplotlib.pyplot as plt

def spiral(length, x, y):
	if length <= 0:
		return

	if x>0 and y>0: # going down
		for i in range(1, length*2 - 1, 5):
			plt.scatter ( x , y )
			y = y - 5

	elif x>0 and y<0: # going left
		for i in range(1, length*2 - 1, 5):
			plt.scatter ( x , y )
			x = x - 5

	elif x<0 and y<0: # going top
		for i in range(1, length*2 - 1, 5):
			plt.scatter ( x , y )
			y = y + 5

	elif x<0 and y>0: # going down
		for i in range(1, length*2 - 1, 5):
			plt.scatter ( x , y )
			x = x + 5


	plt.scatter ( x , y )

	spiral(length - 5, x, y)

plt.scatter ( 0 , 0 )
spiral(100, 100, 100)
plt.show ()


# The function that determines a McNumber is
#		f = 6x + 9y + 20z / x,y,z >= 0
# As we get higher numbers the probability of obtaining a
# number as a linear combination of the mcnuggets' number
# increases, so we are gona have the maximum number very close

McNumbers = [ 0 ]
danger = 0

i = 1
while True:
	if (i - 6 in McNumbers or i - 9 in McNumbers or i - 20 in McNumbers) :
		McNumbers.append(i)
		danger += 1
		if danger >= 10:
			break

	else:
		print i
		danger = 0

	i += 1

# the highest mcnugget number is 43

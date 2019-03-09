#!/usr/bin/python
#from Puzzel
from random import uniform
from sys import argv

length = int(argv[1])

def weightedPick(d, n):
	q = 0
	for x in d:
		q += x[n]

	r = uniform(0, q)
	s = 0
	for x in d:
		s += x[n]
		if r < s: return x[0]
	return x[0]

# Character frequencies; any character/first letter #
charFreq = {
	('a' , 8167  , 11602),
	('b' , 1492  , 4702 ),
	('c' , 2782  , 3511 ),
	('d' , 4253  , 2670 ),
	('e' , 12702 , 2007 ),
	('f' , 2228  , 3779 ),
	('g' , 2015  , 1950 ),
	('h' , 6094  , 7232 ),
	('i' , 6966  , 6286 ),
	('j' , 153   , 597  ),
	('k' , 747   , 590  ),
	('l' , 4025  , 2705 ),
	('m' , 2406  , 4374 ),
	('n' , 6749  , 2365 ),
	('o' , 7507  , 6264 ),
	('p' , 1929  , 2545 ),
	('qu', 95    , 173  ),
	('r' , 5987  , 1653 ),
	('s' , 3327  , 7755 ),
	('t' , 9056  , 16671),
	('u' , 2663  , 1314 ),
	('v' , 1037  , 649  ),
	('w' , 2365  , 6753 ),
	('x' , 150   , 37   ),
	('y' , 1974  , 1620 ),
	('z' , 74    , 34   )}

totalWords = 0
words = 0
chars = 0
sentLen = int(uniform(3, 9))
wordLen = int(uniform(1, 13))
cap = True

while totalWords < length:
	if words >= sentLen:
		words = 0
		sentLen = int(uniform(3, 9))

		print('.', end='')

		if uniform(0, 1) <= 0.15:
			print()

			if uniform(0, 1) <= 0.50:
				print('\t', end='')

		else:
			print(' ', end='')

		cap = True

	elif chars >= wordLen:
		chars = 0
		words += 1
		totalWords += 1
		wordLen = int(uniform(1, 13))

		print(' ', end ='')

	else:
		if cap:
			cap = False
			print(weightedPick(charFreq, 2).capitalize(), end='')

		else:
			print(weightedPick(charFreq, 1), end='')

		chars += 1
print()

# I had a small complication abstracting for this problem
# so at the end I implemented it in python to avoid some
# faults that were putting me nervous.
# As always, python looks brighter:

import sys

def printLayer(layer):
	for x in range(layer):
		sys.stdout.write("\t")
		sys.stdout.flush()

def permutations(word, layer):
	if len(word) == 0:
		return

	for x in range(len(word)):
		if len(word) != 0:
			printLayer(layer)
			print( word[0] )

		subword = word[1:]
		permutations(subword, layer+1)
		if len(word) > 1:
			word = word[1:] + word[0] #displace all the letters one position
	

word = raw_input("lets try permutations: ")
permutations(word, 0)

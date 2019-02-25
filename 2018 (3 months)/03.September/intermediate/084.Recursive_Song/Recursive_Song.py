#!/usr/bin/python

things = ['moor', 'tree', 'branch', 'nest', 'bird', 'egg', 'chick', 'heart', 'love']
prepositions = ['in', 'on', 'on', 'in', 'under', 'in', 'in', 'in', 'in']

verse = "Hi ho, the barren moor,\nThe moor down in the valley-o,\nHi ho, the barren moor,\nThe moor down in the valley-o.\n"

for i in range(len(things) - 1):
	print verse
	print("Now %s that %s there was a %s,\nA bare %s, a barren %s;\nThe %s %s the %s" % (prepositions[i], things[i], things[i+1], things[i+1], things[i+1], things[i+1], prepositions[i], things[i]))
	for j in range(i):
		print("And the %s %s the %s" % (things[i-j], prepositions[i-j-1], things[i-j-1]))
	print("And the moor down in the valley-o\n")

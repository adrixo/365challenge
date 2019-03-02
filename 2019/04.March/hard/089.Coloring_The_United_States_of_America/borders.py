#!/usr/bin/python

base = " style=\"fill:#d3d3d3;stroke:#ffffff;stroke-opacity:1;stroke-width:0.75;stroke-miterlimit:4;stroke-dasharray:none\" />"
grey = "#d3d3d3"
yellow = "#FFE65D"
green = "#33cc33"
blue = "#3366ff"
purple = "#BA55D3"
colors = [yellow, green, blue, purple]

def loadStates(importFile, states):
	f = open(importFile)
	for line in f:
		splited = line.rstrip().split(':')
		country = splited[0]
		borders = [x.strip() for x in splited[1].split(',')]
		states.append([country, borders, grey])

# states = [ ['WA', ['OR', 'ID']], [ 'FL', ['AL', 'GA']] ]

importFile = "borders.txt"
states = []

# 1. load the states
loadStates(importFile, states)
#print(states)

counter = 0
def colorear(modifiedState, counter):
	ind = [i for i, s in enumerate(states) if modifiedState in s][0]

	if counter == len(states) or states[ind][2] != grey :
		print("fin, ", counter, states[ind])
		return True

	nextColour = 0
	nextState = 0
	success = False

	while nextColour < 4:
		avaibleColour = True
		for neighbour in states[ind][1]:
			if states[[i for i, s in enumerate(states) if neighbour in s][0]][2] == colors[nextColour]:
				avaibleColour = False

		if avaibleColour:
			states[ind][2] = colors[nextColour]
			while  nextState < len(states[ind][1]):
				success = colorear(states[ind][1][nextState], counter + 1)
				if success:
					print("otro mas\n")
				else:
					states[ind][2] = grey
				nextState += 1

		nextColour += 1

	return False

s = open("Grey.svg").read()
f = open("Tests.svg", 'w')
f.write(s)
f.close()

counter = 0
for stat in states:
	colorear(stat[0], counter)

for stat in states:
	s = open("Tests.svg").readlines()
	ins = 0
	for l in s:
		if stat[0] in l:
			s[ins] = l.replace(grey, stat[2])
		ins += 1
	f = open("Tests.svg", 'w')
	s = ''.join(str(e) for e in s)
	f.write(s)
	f.close()

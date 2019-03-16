#!/usr/bin/python
import cairosvg
import imageio

grey = "#d3d3d3"
orangeWhite = "#ffff"
baseHex = "9999"
maxim = 255 # ffff
minim = 16 # 7400 hex(dec).split('x')[-1]
darkmin = 6
darkmax = 16
darkference = darkmax - darkmin
diference = maxim - minim

def loadStates(importFile, states):
	f = open(importFile)
	for line in f:
		splited = line.rstrip().split(',')
		states.append(splited)

importFile = "data.txt"
states = []
loadStates(importFile, states)

images = []
# statIndex = selected year
for statIndex in range(1, len(states)):

#	if statIndex == 100:
#		break
	print(statIndex,"/",len(states))
	s = open("Grey.svg").read()
	f = open("Tests.svg", 'w')
	f.write(s)
	f.close()

	maximunWork = 0
	minimunWork = 100
	for stat in states[0][1:]:
		proporcion = float(states[statIndex][states[0].index(stat)])
		if proporcion > maximunWork:
			maximunWork = proporcion
		if proporcion < minimunWork:
			minimunWork = proporcion


	for stat in states[0][1:]:
		s = open("Tests.svg").readlines()
		ins = 0
		for l in s:
			if stat in l and ins > 8:
				proporcion = (float(states[statIndex][states[0].index(stat)]) - minimunWork) / maximunWork
				proporcion = (0.8-proporcion)
				colorDec = int(diference * proporcion + minim)
				colorHex = hex(colorDec).split('x')[-1]
				darkDec = int(darkference * proporcion + darkmin)
				darkHex = hex(darkDec).split('x')[-1]

				newColor = "#" + colorHex + darkHex*4
				s[ins] = l.replace(grey, newColor)
				break

			ins += 1

		f = open("Tests.svg", 'w')
		s = ''.join(str(e) for e in s)
		f.write(s)
		f.close()

	s = open("Tests.svg").read()
	cairosvg.svg2png(bytestring=s,write_to='output.png')
	images.append(imageio.imread('output.png'))
imageio.mimwrite('output.gif', images, 'GIF',duration=0.1)

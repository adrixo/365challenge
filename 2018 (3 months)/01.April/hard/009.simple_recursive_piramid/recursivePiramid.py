
#
#coments on main.c
#
import sys

LENGTH = 40

def calcPiramid(layers, message):
	if layers == 0:
		return

	i,j = 0,0
	auxMessage = [-1] * LENGTH
	last = message[0]
	quantity=0

	while message[i] != -1:
		if last == message[i]:
			quantity += 1

		else:
			auxMessage[j] = quantity
			auxMessage[j+1] = last
			j += 2
			quantity = 1
			last = message[i]

		i += 1

	last = message[i-1]
	auxMessage[j] = quantity
	auxMessage[j+1] = last

	for i in auxMessage:
		if i == -1:
			break
		sys.stdout.write(' ' +str(i)+ ' ')
		sys.stdout.flush()

	print('')
	calcPiramid(layers-1,auxMessage)
#def

#main
message = [-1] * LENGTH
message[0] = 1
print(' '+str(message[0]))
calcPiramid(10, message)


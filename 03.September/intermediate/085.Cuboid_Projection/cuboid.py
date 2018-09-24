#!/usr/bin/python

def cuboid(xLength, yLength, zLength):
	xc = "# "*xLength
	zc = "::"*xLength

	for z in range(0, zLength)[::-1]:
		if(yLength>zLength):
			print(' '*z + zc + '/'+ '+'*(zLength-z-1))
		else:
			if( zLength - z-1 < yLength ):
				print(' '*z + zc + '/'+ '+'*(zLength - z-1))
			else:
				print(' '*z + zc + '/'+ '+'*(yLength-1))


	for x in range(0,yLength)[::-1]:
		if(x<zLength):
			yc = "+"*(x)
		else:
			yc = "+"*zLength
		print(xc+yc)

while True:
	x = int(input("Enter the x: "))
	y = int(input("Enter the y: "))
	z = int(input("Enter the z: "))

	cuboid(x,y,z)

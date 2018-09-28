#!/usr/bin/python3
from PIL import Image

jpgfile = Image.open("pokeball.jpg")

print(jpgfile.getdata(), jpgfile.size, jpgfile.format)

asciiString = ""
n = 0
for i in jpgfile.getdata():
    if n % 50 == 0:
        n=0
        asciiString+="\n"
    intensity = (i[0]*75 + i[1]*155 + i[2]*25) // 255 //32
    asciiString += " " + str(intensity)
    n += 1
print(asciiString)

#for i in jpgfile.histogram():
#    print(i)
#print(len(jpgfile.histogram()))

#with open("pokeball.jpg", 'rb') as f:
#    jpgdata = f.read()
#f.close
#print(jpgdata)

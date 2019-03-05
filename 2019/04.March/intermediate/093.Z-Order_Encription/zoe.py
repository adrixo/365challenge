#!/usr/bin/python
import math

print("Enter a sentence: ")
sentence = input()

length = 1
flopMatrix = [2]
flopFlag = []
while length*length < len(sentence):
    length = length*2
    if length != 2:
        flopMatrix.append(length*2)
    flopFlag.append(True)

flopMatrix = [value for value in flopMatrix if value != 16]

matrix = [[] for i in range(length)]

position = 0
counter = 0
for i in range(len(sentence)):
    position = 0
    for j in range(len(flopMatrix)):
        if (counter % flopMatrix[j]) == 0:
            flopFlag[j] = not flopFlag[j]

        position += 0
        if flopFlag[j]:
            position += 2**j

    matrix[position].append(sentence[i])

    counter += 1

for line in matrix:
    for c in line:
        print("%c" % c, end='')
    print()

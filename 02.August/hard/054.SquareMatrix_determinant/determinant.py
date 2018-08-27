#!/usr/bin/python

stringMatrix = "x."
matrix = []
columns = 0
size = 0
while stringMatrix != "":
    stringMatrix = str(input("Enter the matrix: "))
    if stringMatrix == "":
        break
    matrix.append( stringMatrix.split(" "))
    if size == 0:
        size = len(matrix[0])-1
    columns += 1

for i in range(size+1):
    matrix[i] = [int(j) for j in matrix[i]]
    matrix[i] = matrix[i] + matrix[i]

det = [1 for j in matrix[0]]
for i in range(size + 1):
    for j in range(size + 1):
        det[j] = det[j] * matrix[i][j+i]
        det[-j-1] = det[-j-1] * (-matrix[i][-j-i-1])

print(sum(det))

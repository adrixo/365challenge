#!/usr/bin/python

matrix = [[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0],
[0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0],
[0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0],
[0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0],
[0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]

def crop(matrix):
    n=-1
    s=0
    w=999
    e=-1

    row = 0
    col = 0

    for f in matrix:
        for c in f:
            if(c==1):
                #north is not defined
                if(n==-1):
                    n=row
                #change the smallest west
                if(w>col):
                    w=col
                #change the bigest east
                if(e<col):
                    e=col
                #south substition
                s=row
            col = col+1

        col = 0
        row = row + 1

    for i in range(n,s+1):
        for j in range(w, e+1):
            print(matrix[i][j], end='')
        print("\n", end='')

print("submatrix: ")
crop(matrix)

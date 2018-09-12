#!/usr/bin/python

def generateSquare(n):
    magicSquare = [[0 for x in range(n)]for y in range(n)]

    i = n // 2
    j = n - 1

    num = 1
    while num <= (n*n):
        if i == -1 and j == n:
            j = n-2
            i = 0
        else:
            if j == n:
                j = 0
            if i < 0:
                i = n-1

        if magicSquare[i][j]:
            j = j-2
            i = i+1
            continue
        else:
            magicSquare[i][j] = num
            num = num + 1

        j = j + 1
        i = i - 1

    for i in range(0,n):
        for j in range(0,n):
            print('%2d ' %(magicSquare[i][j]), end="")
        print()

n = 19
generateSquare(n)

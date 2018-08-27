#!/usr/bin/python
import random

#https://imgur.com/6DyXQ
board = list(range(109))
#ladders
board[1] = 38
board[4] = 14
board[9] = 31
board[21] = 42
board[28] = 84
board[36] = 44
board[51] = 67
board[71] = 91
board[80] = 100
#snake
board[16] = 6
board[47] = 26
board[49] = 11
board[56] = 53
board[62] = 19
board[64] = 60
board[87] = 24
board[93] = 73
board[95] = 75
board[98] = 78

#print(board)
#1: First, what is the minimum number of rolls required to reach space 100.
# 6 jumps starting with one

attemps = 100000
#2: Second, for a single player, what is the average number of rolls required to reach space 100.
# 36.6
rolls = []
for x in range(attemps):
    i = 0
    rolls.append(0)
    while not (i>100):
        roll = random.randint(1,6)
        i = board[i+roll]
        rolls[x] += 1

print(sum(rolls)/len(rolls))

#3: And third, for k players, what is the average number of rolls until one of the players reaches space 100 and wins the game.
# we can use the attemps from last exercise. we divide a the huge cantity of atemps in k
# for example with 4
# 18.15
k = 5
krolls = []
for i in range(int(attemps/k)):
    minimun = 1000
    for j in range(k):
        if rolls[(i + j*int(attemps/k))] < minimun:
            minimun = rolls[i + j*int(attemps/k)]
    krolls.append(minimun)

print(sum(krolls)/len(krolls))

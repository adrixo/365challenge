#!/usr/bin/python3

# Sokoban
# Objects:
#
# User:  o
# block: #
# box: @
# end: H

class Sokoban(object):
    map = ["##########",
     "#        #",
     "#  @  #  #",
     "#     #  #",
     "#  #  #  #",
     "#  #     #",
     "#      H #",
     "#        #",
     "##########"]
     player = [1,1]
     end = [6,7]

    def __init__(self):
        for l in map:
            print(l)

        aux = map[2][3]
        map[2] = map[2][:2] + "  " + map[2][4:]
        map[4] = map[4][:4] + aux + map[4][5:]

        for l in map:
            print(l)

    def printMap(self):
        for l in map:
            print(l)

    def move(self, posX1, posY1, posX2, posY2):
        aux = map[posX1][posY1]
        map[posX1][posY1] = " "
        map[posX1][posY1] = aux

    def validMove(self, posX1, posY1, posX2, posY2):
        # void position
        if map[posX2][posY2] == " ":
            return True

        # there's a box on the position
        else if map[posX2][posY2] == "@":
            Xaux = posX2-posX1
            Yaux = posY2-posY1
            #if after that there is block:
            if map[posX2+Xaux][posY2+Yaux] == "#":
                return False
            else
                return True
        return False

    def moveABox(self, posX2, posY2):
        if map[posX2][posY2] == "@":
                return True
        return False

    def finish(self):
        if map[end[0]][end[1]] == "@":
            return True
        return False

    def analizeKey(self, key):
        if key == "a":
            return [-1,0]
        if key == "d":
            return [1,0]
        if key == "w":
            return [0,-1]
        if key == "s":
            return [0,1]

        return False

    def play(self):
        while not finish():
            printMap()

            key = string(input("Enter a move: "))
            moving = analizeKey(key)

            if validMove(player[0], player[1], player[0]+moving[0], player[1]+moving[1]):
                if moveABox(player[0]+moving[0], player[1]+moving[1]):
                    #move the box
                    move(player[0]+moving[0], player[1]+moving[1], player[0]+moving[0]+moving[0], player[1]+moving[1]+moving[1])
                    #move the player
                    move(player[0], player[1], player[0]+moving[0], player[1]+moving[1])
                else:
                    #move the player
                    move(player[0], player[1], player[0]+moving[0], player[1]+moving[1])
                player[0] += moving[0]
                player[0] += moving[0]

game = Sokoban()
#game.printMap()

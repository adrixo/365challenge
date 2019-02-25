#!/usr/bin/python3

# Sokoban
# Objects:
#
# User:  o
# block: #
# box: @
# end: H

class Sokoban(object):
    map = ["##########", "#o       #", "#  @  #  #", "#     #  #", "#  #  #  #", "#  #     #", "#      H #", "#        #", "##########"]
    player = [1,1]
    end = [6,7]

    def __init__(self):
        self.play()

    def printMap(self):
        for l in self.map:
            print(l)

    def move(self, posX1, posY1, posX2, posY2):
        aux = self.map[posX1][posY1]
        self.map[posX1] = self.map[posX1][:posY1] + " " + self.map[posX1][posY1+1:]
        self.map[posX2] = self.map[posX2][:posY2] + aux + self.map[posX2][posY2 +1:]

    def placePlayer(self):
        self.map[self.player[0]] = self.map[self.player[0]][:self.player[1]-1] + "o" + self.map[self.player[0]][self.player[1]+1:]


    def validMove(self, posX1, posY1, posX2, posY2):
        # void position
        if self.map[posX2][posY2] == " ":
            return True

        # there's a box on the position
        elif self.map[posX2][posY2] == "@":
            Xaux = posX2-posX1
            Yaux = posY2-posY1
            #if after that there is block:
            if self.map[posX2+Xaux][posY2+Yaux] == "#":
                return False
            else:
                return True
        return False

    def moveABox(self, posX2, posY2):
        if self.map[posX2][posY2] == "@":
                return True
        return False

    def finish(self):
        if self.map[self.end[0]][self.end[1]] == "@":
            return True
        return False

    def analizeKey(self, key):
        if key == "w":
            return [-1,0]
        if key == "s":
            return [1,0]
        if key == "a":
            return [0,-1]
        if key == "d":
            return [0,1]

        return False

    def play(self):
        while not self.finish():
            self.printMap()

            key = input("Enter a move: ")
            moving = self.analizeKey(key)
            if moving != False:
                if self.validMove(self.player[0], self.player[1], self.player[0]+moving[0], self.player[1]+moving[1]):
                    if self.moveABox(self.player[0]+moving[0], self.player[1]+moving[1]):
                        #move the box
                        self.move(self.player[0]+moving[0], self.player[1]+moving[1], self.player[0]+moving[0]+moving[0], self.player[1]+moving[1]+moving[1])
                        #move the player
                        self.move(self.player[0], self.player[1], self.player[0]+moving[0], self.player[1]+moving[1])
                    else:
                        #move the player
                        self.move(self.player[0], self.player[1], self.player[0]+moving[0], self.player[1]+moving[1])
                    self.player[0] += moving[0]
                    self.player[1] += moving[1]

            #self.placePlayer()
        print("You win!")
game = Sokoban()

#!/usr/bin/python

import random

# rectangle(x,y,w,h)

class Board:
    def __init__(self, size):
        self.size = size
        self.bo = [ [0 for j in range(size)] for i in  range(size)]
        self.area = 0

    def printBoard(self):
        for line in self.bo:
            for element in line:
                if element == 0:
                    print(" ", end='')
                else:
                    print(element, end='')
            print("")

    def addRectangle(self, rectangle):
        for i in range(rectangle.w):
            for j in range(rectangle.h):
                self.bo[rectangle.x + i][rectangle.y + j] += 1
                
    def returnArea(self):
        self.area = 0
        for i in self.bo:
            self.area += i.count(0)
        self.area = self.size*self.size - self.area
        return self.area

class Rectangle:
    def __init__(self, x, y, w, h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h

rectangles = []
for rect in range(5):
    rectangles.append(Rectangle(random.randint(0, 10), random.randint(0, 10), random.randint(0, 10), random.randint(0, 10)))

board = Board(20)
for rect in rectangles:
    board.addRectangle(rect)

board.printBoard()

print("Area : ",board.returnArea())

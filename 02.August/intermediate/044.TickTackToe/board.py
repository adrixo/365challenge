#!/usr/bin/bash

class  board(object):
  board = [[" ", " ", " "],[" ", " ", " "],[" ", " ", " "]]
  player = ["x", "o"]
  turn = 0

  def __init__(self)
    turn = 0

  def printBoard(self):
    for i in range(3):
      print(self.board[i] + "\n")

  def nextTurn(self):
      turn = turn + 1

  def getWinner(self):
      return player[turn % 2]

  def getTurn(self):
      return turn

  #Returns true on exit and false on failure
  def place(self, x, y):
    if( self.board[x][y] == " "):
        self.nextTurn()
        self.board[x][y] = self.player[self.turn % 2]
        return True
    else:
        return False

  def checkVictory(self):
      for i in range(3):
        #horizontal
        if( self.board[i][0] == self.board[i][1] == self.board[i][2] != " "):
            return True
        #vertical
        if( self.board[0][i] == self.board[1][i] == self.board[2][i] != " "):
            return True

      if(self.board[0][0] == self.board[1][1] == self.board[2][2] != " " || self.board[0][2] == self.board[1][1] == self.board[2][0] != " " ):
        return True

      return False

#!/usr/bin/python


class  board(object):
  board = [[" ", " ", " "],[" ", " ", " "],[" ", " ", " "]]
  player = ["x", "o"]
  turn = 0

  def __init__(self):
    turn = 0

  def printBoard(self):
    for i in range(3):
      print(self.board[i][0] +self.board[i][1] + self.board[i][2] + " " + str(i))

  def nextTurn(self):
      self.turn = self.turn + 1

  def getWinner(self):
      return self.player[self.turn % 2]

  def getTurn(self):
      return self.turn

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
            return False
        #vertical
        if( self.board[0][i] == self.board[1][i] == self.board[2][i] != " "):
            return False

      if(self.board[0][0] == self.board[1][1] == self.board[2][2] != " " or self.board[0][2] == self.board[1][1] == self.board[2][0] != " " ):
        return False

      return True


board = board()
end = True

while(end):
    board.printBoard()
    position = int(input("Using the numeric gamepad, enter the position: "))

    if(position==7):
        x=0
        y=0
    if(position==8):
        x=0
        y=1
    if(position==9):
        x=0
        y=2
    if(position==4):
        x=1
        y=0
    if(position==5):
        x=1
        y=1
    if(position==6):
        x=1
        y=2
    if(position==1):
        x=2
        y=0
    if(position==2):
        x=2
        y=1
    if(position==3):
        x=2
        y=2
    board.place(x,y)
    end = board.checkVictory()

board.printBoard()
print("The winner is " + board.getWinner())

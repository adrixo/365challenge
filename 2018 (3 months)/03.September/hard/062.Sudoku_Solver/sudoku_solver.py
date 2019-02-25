#!/usr/bin/python
import itertools

class Sudoku:
    board = []

    def __init__(self):
        self.board.append([0,0,6,0,0,2,3,0,4])
        self.board.append([9,0,4,7,5,0,0,8,2])
        self.board.append([0,0,8,0,0,6,0,0,5])
        self.board.append([0,0,3,0,0,0,0,4,0])
        self.board.append([2,0,0,4,0,0,8,3,0])
        self.board.append([4,0,7,5,0,0,0,0,0])
        self.board.append([0,0,0,6,0,0,0,0,8])
        self.board.append([7,0,0,0,2,0,4,5,3])
        self.board.append([0,0,0,3,7,0,0,6,9])

    def findNextCellToFill(self,board,i=0,j=0):
        for x in range(i,9):
            for y in range(j,9):
                if board[x][y] == 0:
                    return x,y
        return -1,-1

    def isValid(self, board, i, j):
        # check horizontal
        combinations = list(itertools.combinations(board[i],2))
        for x in combinations:
            if x[0] == x[1] and x[0] != 0:
                return False

        vertical = []
        for x in range(9):
            vertical.append(board[x][j])
        combinations = list(itertools.combinations(vertical,2))
        for x in combinations:
            if x[0] == x[1] and x[0] != 0:
                print(x)
                return False

        square = []
        squareI = i//3 * 3
        squareJ = j//3 * 3
        for x in range(squareI, squareI + 3):
            for y in range(squareJ, squareJ + 3):
                square.append(board[x][y])
        combinations = list(itertools.combinations(square,2))
        for x in combinations:
            if x[0] == x[1] and x[0] != 0:
                return False

        return True

    def solveSudoku(self,board):
        i,j = self.findNextCellToFill(board)
        if i == -1:
            print("Finish!")
            return True
        else:
            for n in range(1,10):
                board[i][j] = n
                self.printBoard(board)
                if self.isValid(board,i,j):
                    result = self.solveSudoku(board)
                    if(result):
                        return True
                    else:
                        board[i][j] = 0
                else:
                    board[i][j] = 0

            return False


    def printBoard(self,board):
        print("---------+---------+---------+")
        for i in range(9):
            for j in range(9):
                if board[i][j] == 0:
                    print(" . ", end="")
                else:
                    print("", board[i][j],"", end="")
                if (j+1) % 3 == 0:
                    print("|",end="")
            print()
            if (i+1) % 3 == 0 :
                print("---------+---------+---------+")
            aux=1

    def getBoard(self):
        return self.board

sudoku = Sudoku()
sudoku.solveSudoku(sudoku.board)

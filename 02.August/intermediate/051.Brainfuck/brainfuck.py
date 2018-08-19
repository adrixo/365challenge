#!/usr/bin/python

class os:

    tape = [0]
    pointer = 0
    jumpPointer = 0

    def __init__(self, instructions):
        self.instructions = list(instructions)
        self.instructionsPointer = 0
        self.instructions.append('x')

    def moveLeft(self):
        if self.pointer == 0:
            self.tape = [0] + self.tape
        else:
            self.pointer -= 1

    def moveRight(self):
        if self.pointer == (len(self.tape)-1):
            self.tape.append(0)
            self.pointer += 1
        else:
            self.pointer += 1

    def increment(self):
        self.tape[self.pointer] += 1

    def decrement(self):
        self.tape[self.pointer] -= 1

    def jumpForward(self):
        if self.tape[self.pointer] == 0:
            while self.instructions[self.instructionsPointer] != ']':
                self.instructionsPointer += 1

    def jumpBackwards(self):
        if self.tape[self.pointer] != 0:
            while self.instructions[self.instructionsPointer] != '[':
                self.instructionsPointer -= 1

#++++++++++[>>++++++>+++++++++++>++++++++++>+++++++++>+++>+++++>++++>++++++++>+[<]<-]>>+++++++.>+.-.>+++.<++++.>>+++++++.<<++.+.>+++++.>.<<-.>---.<-----.-.+++++.>>>+++.-.<<-.<+..----.>>>>++++++++.>+++++++..<<<<+.>>>>-.<<<<.++++.------.<+++++.---.>>>>>.<<<++.<<---.>++++++.>>>>+.<<<-.--------.<<+.>>>>>>+++.---.<-.<<<<---.<.>---.>>>>>>.
    def readAndStore(self):
        self.tape[self.pointer] = ord(input("Enter a char: "))

    def outputCurrent(self):
        print(chr(self.tape[self.pointer]))

    # https://www.google.es/search?q=switch+python&oq=switch+python&aqs=chrome.0.69i59j69i57j69i60l2.1810j0j7&sourceid=chrome&ie=UTF-8
    # switch case in python
    def switchInstruction(self,argument):
        switcher = {
            '<': self.moveLeft,
            '>': self.moveRight,
            '+': self.increment,
            '-': self.decrement,
            '[': self.jumpForward,
            ']': self.jumpBackwards,
            ',': self.readAndStore,
            '.': self.outputCurrent,
        }
        func = switcher.get(argument, lambda: "")
        func()

    def run(self):
        while self.instructions[self.instructionsPointer] != 'x':
            self.switchInstruction(self.instructions[self.instructionsPointer])
            self.instructionsPointer += 1
            print("tape: " , self.tape)
            print("pointer: " ,self.pointer)
            print("instructions: " , self.instructions)
            print("instructions: " , self.instructionsPointer)
            input()

brainfuck = os(str(input("Enter the orders in a simple string: ")))
brainfuck.run()

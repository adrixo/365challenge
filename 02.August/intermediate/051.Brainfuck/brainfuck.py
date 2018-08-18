#!/urs/bin/python

def moveLeft():

def moveRight():

def increment():

def decrement():

def jumpForward():

def jumpBackwards():

def readAndStore():

def outputCurrent():


# https://www.google.es/search?q=switch+python&oq=switch+python&aqs=chrome.0.69i59j69i57j69i60l2.1810j0j7&sourceid=chrome&ie=UTF-8
# switch case in python
def switch(argument):
    switcher = {
        '<': moveLeft,
        '>': moveRight,
        '+': increment,
        '-': decrement,
        ']': jumpForward,
        '[': jumpBackwards,
        ',': readAndStore,
        '.': outputCurrent,
    }
    func = switcher.get(argument, lambda: "")
    func()

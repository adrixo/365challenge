#!/usr/bin/python

class surrounded_sentence:

    def __init__(self, sentence):
        self.sentence = sentence
        self.surround()

    def printSentence(self):
        print(self.surrounded)

    def getSentence(self):
        return self.sentence

    def changeSentence(self, sentence):
        self.sentence = sentence
        self.surround()

    def surround(self):
        banner = (len(self.sentence) + 4) * "*" + "\n"
        separator = '*' + ((len(self.sentence) + 2) * ' ') + "*\n"
        builtInSentence = '* ' + self.sentence + " *\n"
        self.surrounded = banner + separator + builtInSentence + separator + banner


###   ###   ###   ###   ###   ###   ###   ###   ###   ###   ###   ###   ###   ##

mySentence = surrounded_sentence(input("Enter a sentence: "))

mySentence.printSentence()

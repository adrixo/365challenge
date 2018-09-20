#!/usr/bin/python
import sys
import re

try:
    indexFile = open("index.txt", "r")
    for word in sys.argv[1:]:
        found = False
        for l in indexFile.readlines():
            if re.findall(r"^[\w']+",l) != [] and found:
                break

            if re.findall(r"^%s:" %word,l) != []:
                found = True
                print(word + ": \n")

            if re.findall(r"^\t",l) != []:
                if found:
                    print(l + "\n")

except:
    print("Couldnt open the index. \n")

#!/usr/bin/python

import sys
import re

def containsWord(index,word):
    for i in index:
        if i[0]==word:
            return True
    return False

def wordContainsFile(index,word,file):
    for i in index:
        if i[0]==word:
            for j in i:
                if j[0] == file:
                    return True
    return False

index = [] #Example [["hi",["File1",3,5],["file2",1]],["bye",["file1",6]]]

for file in sys.argv[1:256]:
  f = open(file, "r")
  lines = f.readlines()

  lineNumber = 0
  for l in lines:
    words = re.findall(r"[\w']+",l)
    for w in words:
      i = 0
      found = False
      for saved in index:
        if saved[0] == w:
          found = True
          wordDoesntExist = False
          for o in saved[1:]:
            if file in o and lineNumber not in o:
                o.append(str(lineNumber))
                wordDoesntExist = False
                break
            if file not in o:
                wordDoesntExist = True
          if wordDoesntExist:
            saved.append([file,str(lineNumber)])
          break
        i += 1

      if not found:
          index.append([w,[file, str(lineNumber)]])
    lineNumber += 1

print("\nNew words: \n")
j=0
for x in index:
    print(j,x)
    j += 1

try:
    indexFile = open("index.txt", "r")
    j = 0
    savedIndex = [[]]
    currentWord = ""
    filesForWord = []
    for l in indexFile.readlines():
#       new entry word in the index
      if re.findall(r"^[\w]+:",l) != []:
        currentWord = re.findall(r"[\w]+",l)[0]
        savedIndex.append([currentWord])
        j += 1

#      new file entry in the index
      if re.findall(r"^\t[\w]+:",l) != []:
        savedIndex[j].append( re.findall(r"[\w]+",l))
    savedIndex.pop(0)

    print("\nOld words: \n")
    j=0
    for x in savedIndex:
      print(j,x)
      j += 1

#   union of indexFile with new entries in index
    for new in index:
        if containsWord(savedIndex, new[0]):
            oldI = -1
            for old in savedIndex:
                oldI += 1
                if old[0] == new[0]:
                    for new2 in new:
                        if wordContainsFile(savedIndex, new[0], new2[0]):
                            oldJ = -1
                            for old2 in old:
                                oldJ += 1
                                #file entry exists in both:
                                if old2[0]==new2[0] and old2 != old[0]:
                                    fileName = old2[0]
                                    lines = list(set(old2[1:]) | set(new2[1:]))
                                    lines.insert(0,fileName)
                                    savedIndex[oldI][oldJ] = lines
                        else:
                            savedIndex[oldI].append(new2)
        else:
            #word entry doesnt exists
            savedIndex.append(new)

    print("\nFinal index: \n")
    j=0
    for x in savedIndex:
      print(j,x)
      j += 1

except:
    print("Creating index... \n")
    savedIndex = index

indexFile.close()
indexFile = open("index.txt", "w")

for word in savedIndex:
    indexFile.write("\n"+word[0] + ":\n")
    for f in word:
        if f != word[0]:
            indexFile.write("\t"+f[0] + ": ")
            for element in f[1:]:
                indexFile.write(element+", ")
            indexFile.write("\n")

indexFile.close()

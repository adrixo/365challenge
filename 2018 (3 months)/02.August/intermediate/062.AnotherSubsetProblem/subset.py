#!/usr/bin/python
import itertools

originalSet = list(range(1,int(input("Range: "))))
# originalSet = [3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99]
# 179
testedNumbers = []
print(originalSet)

solutions = 0
for i in originalSet:
    for j in range(2,len(testedNumbers)):
        combinations = list(itertools.combinations(testedNumbers,j))
        for x in combinations:
            if sum(x) == i:
                solutions += 1
                print(x," = ",i)
    testedNumbers.append(i)

print(solutions)

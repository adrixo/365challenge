#!/usr/bin/python

items = int(input("Enter the number of items: "))
number = int(input("Enter the size of the array: "))
while(number>items):
    number = int(input("Enter the size of the array: "))

itemsArray = []
for i in range(items):
    itemsArray.append(i)

# After try different perspectives and test other people's algorithms
# avoiding to repeat others recursive's attemps from older challenges
# i implement the easiest way:

import itertools
print(list(itertools.combinations(itemsArray, number)))

#CheckItInTheFuture

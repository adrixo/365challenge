#!/usr/bin/python3

# a function that can take in an instance of 2-SAT encoded as a list
# of pairs of integers and return a boolean for whether or not there
# are any true solutions to the formula

def twoSat(code, variables):
    lastValue = True
    for pair in  code:
        # we substitute the value of the first value of the pair
        # with the correct value given on variables
        # e.g: x1 = True, x2 = False - not x1 or x3 => not True or False = False
        if pair[0] < 0: # not
            st = not variables[abs(pair[0])-1]
        else:
            st = variables[pair[0]-1]

        if pair[1] < 0:
            nd = not variables[abs(pair[1])-1]
        else:
            nd = variables[pair[1]-1]

        lastValue = lastValue and (st or nd)

    return lastValue


code = [[1,-3],[2,3],[1,-2]]
x = [False,False,True]
print(twoSat(code, x))

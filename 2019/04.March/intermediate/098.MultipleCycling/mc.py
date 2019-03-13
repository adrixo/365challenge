#!/usr/bin/python

def mc_rec(lim, x, iteration, currentSolution):
    if(currentSolution > lim):
        return iteration

    currentMult = x[ iteration % len(x) ]
    for i in range(currentMult):
        if (currentSolution + i) % currentMult == 0:
            currentSolution += i
            break

    print("Next multiple of {} is {}".format(currentMult, currentSolution))
    iteration += 1
    return mc(lim, x, iteration, currentSolution)

def mc_it(lim, x):
    currentSolution = 1
    iteration = 0
    while(currentSolution < lim):

        currentMult = x[ iteration % len(x) ]
        for i in range(1,currentMult+1):
            if (currentSolution + i) % currentMult == 0:
                currentSolution += i
                break

        print("Next multiple of {} is {}".format(currentMult, currentSolution))
        iteration += 1

    return iteration

x = [5395, 7168, 2367, 9999, 3]
print("Iterations: ", mc_it(1000000000, x))
#print("Iterations: ", mc_rec(1000000000, x, 0, 1)) #that exceds the 999 recursiions allowed in python

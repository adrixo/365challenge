#!/usr/bin/python

#Definition of the SVD:
#   Mv=su and M'u=sv
#
# M' denotes M transposed.
# sVD of M is the set of all singular tuples (u, s, v) for which this is true

# Input: 2x2 real matrix M
# Output: One of the singular tuples of M
def SVD(M):

    #We would check M size
    #M'
    Mt = [[M[0][0],M[1][0]],[M[0][1],M[1][1]]]

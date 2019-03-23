#!/usr/bin/python2
from itertools import groupby
from operator  import itemgetter

#sch1zo

print len([i for i in range(1000, 2013 + 1) if len(set(str(i))) == 4])

#bonus

m = lambda l: max([len(map(itemgetter(1), g)) for k, g in groupby(enumerate(l), lambda (i, x): i - x)])
print m([i for i in range(1000, 2013 + 1) if len(set(str(i))) == 4]) #non-repeating
print m([i for i in range(1000, 2013 + 1) if len(set(str(i)))  < 4]) #repeating

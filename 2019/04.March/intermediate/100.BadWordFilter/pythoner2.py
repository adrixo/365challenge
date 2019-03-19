#! /usr/bin/python2

import sys, re

mouth = sys.stdin.read()
filth = open(sys.argv[1], 'r').read().splitlines()
soap = [x for x in filth if re.search(r'%s.*' % x, mouth, flags=re.I)]
for x in soap:
	mouth = re.sub(x[1:], '*' * (len(x) - 1), mouth, flags=re.I)
print '\n', mouth

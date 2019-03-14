#!/usr/bin/python

#yentup

words, count = open('enable1.txt', 'r').readlines(), 0
for word in words:
	aword = word[:-2]
	if ''.join(sorted(aword)) == aword: count += 1
print count 

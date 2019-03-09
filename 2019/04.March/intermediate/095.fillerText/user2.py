#!/usr/bin/python2

#from kevwillia

import re, string, random as r

weights = [116,47,35,26,20,37,19,72,62,5,5,27,43,23,62,25,1,16,77,166,14,1,67,1,16,1]
weighted = ''.join([''.join(l * weights[i]) for i, l in enumerate(string.ascii_lowercase)])
punc = '...........,,,,,,,,,,??!'
eol = ['\n','\n','\n','\n\n','\n\n','\n\n',' ',' ',' ',' ',' ',' ',' ',' ',
       ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
       ' ',' ',' ',' ',' ',' ',' ',' ',' ']


def filler_text(n):
    result = ''
    let_count = 0
    while let_count < n:
        result += make_sent()
        let_count = len(result) - result.count(' ')
    return result

def make_sent():
    result = ''
    for word in range(r.randint(3,8)):
        result += make_word() + ' '
    result = string.capitalize(result[:-1]) + r.choice(punc) + r.choice(eol)
    return result


def make_word():
    result = ''
    if r.randint(1,100) < 3:
        return str(r.randint(1,1000))
    for letter in range(r.randint(1,12)):
        result += r.choice(weighted)
    return result


print filler_text(1000)

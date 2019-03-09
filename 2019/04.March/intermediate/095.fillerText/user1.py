#!/usr/bin/python

#from nagasgura

import random

def filler_text(limit):
    wordcount = 0
    text = ''
    letter_freq = {
    'a':8167,  'b':1492,  'c':2782,  'd':4253,
    'e':12702, 'f':2228,  'g':2015,  'h':6094,
    'i':6966,  'j':153,   'k':747,   'l':4025,
    'm':2406,  'n':6749,  'o':7507,  'p':1929,
    'q':95,    'r':5987,  's':6327,  't':9056,
    'u':2758,  'v':1037,  'w':2365,  'x':150,
    'y':1974,  'z':74
    }
    letters =''
    for i in letter_freq:
        letters += (i*letter_freq[i])
    while wordcount < limit:
        sentence = ''
        word = ''
        rand =random.choice(range(3,10))
        for i in range(rand):
            if random.random()>=0.05:
                for j in range(random.choice(range(1,13))):
                    word+=(random.choice(letters))
            else: word = str(random.randint(1,100))
            if i != rand-1:
                if random.random()<=0.1: sentence+=word+', '
                else: sentence+=word + ' '
            else: sentence+=word + ' '
            wordcount +=1
            if wordcount >= limit:
                formatted_sentence =sentence[0].upper()+sentence[1:-1]+ '. '
                break
            word = ''
            formatted_sentence =sentence[0].upper()+sentence[1:-1]
            if random.random()<=0.2:formatted_sentence+=random.choice('!?')+' '
            else: formatted_sentence+='. '
            if random.random() <= 0.15:
                formatted_sentence += '\n'
                if random.random() <=0.5:
                    formatted_sentence += '\n'
        text+= formatted_sentence
    return text

print(filler_text(100))

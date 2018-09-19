#!/usr/bin/python

cards = {'A':13,2:1,3:2,4:3,5:4,6:5,7:6,8:7,9:8,'T':9, 'J':10, 'Q':11, 'K':12}
suit = ['H','D','C','S']

hand = [['T','H'],['A','H'],['T','C'],['J','H'],['A','H']]


def whatHandIsIt(hand):
    handCode = [cards[hand[0][0]],cards[hand[1][0]],cards[hand[2][0]],cards[hand[3][0]],cards[hand[4][0]]]
    handCode = sorted(handCode)
    print(handCode)
    iSuit = -1

#royalFlush
    iSuit = hand[0][1]
    n=0
    objetive = ['T', 'J', 'Q', 'K', 'A']
    for i in hand:
        if i[1] != iSuit:
            break
        if i[0] in objetive:
            n += 1
        if n == 5:
            print("royalFlush")
            return "royalFlush"

#straight flush
    isStraight = True
    iSuit = hand[0][1]
    flushFlag = False
    for i in hand:
        if i[1] != iSuit:
            isStraight = False

    last = 0 # last hand,
    flag = True
    n = 0
    for i in handCode:
        if flag:
            flag = False
            last = i
            continue
        if i == last + 1:
            n += 1
            last = i
        else:
            break

    if n == 4:
        flushFlag = True

    if isStraight and flushFlag:
        print("royalFlush")
        return "royalFlush"

#four of a kind
    st = handCode[0]
    nd = handCode[1]
    n = 0
    d = 0
    for i in handCode:
        if st == i:
            n += 1
        if nd == i:
            d += 1
    if n >= 4 or d >= 4:
        print("poker")
        return "poker"

# ||| ||
# || |||
# Full
    if (handCode[0] == handCode[1] == handCode[2] and handCode[3] == handCode[4]) or \
        (handCode[0] == handCode[1] and handCode[2] == handCode[3] == handCode[4]):
        print("full")
        return "full"

# Flush
    if flushFlag:
        print("flush")
        return "flush"

# Straight
    if isStraight:
        print("Straight")
        return "Straight"

# ||| | |
# | ||| |
# | | |||
# three of a kind
    if (handCode[0] == handCode[1] == handCode[2]) or \
        (handCode[2] == handCode[3] == handCode[4]) or \
        (handCode[1] == handCode[2] == handCode[3]):
        print("three of a kind")
        return "three of a kind"

# || || |
# || | ||
# | || ||
# Two pairs
# Pair
    if (handCode[0] == handCode[1]):
        if(handCode[2] == handCode[3]) or (handCode[3] == handCode[4]):
            print("twoPairs")
            return "twoPairs"
        print("pair")
        return "pair"

    if (handCode[1] == handCode[2]):
        if(handCode[3] == handCode[4]):
            print("twoPairs")
            return "twoPairs"
        print("pair")
        return "pair"

# xx || |
# xx | ||
    if(handCode[2] == handCode[3]) or (handCode[3] == handCode[4]):
        print("pair")
        return "pair"


# High card
    print("The higher card is:", handCode[4])
    return "handCode[4]"


whatHandIsIt(hand)

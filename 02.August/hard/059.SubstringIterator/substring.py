#!/usr/bin/python


def P(n, sp):
    if(n == 0):
        sp.append("123456789")
        return 123456789

    N = ((22695477 * P(n-1,sp) + 12345 ) %1073741824)
    sp.append(str(N))
    return N

def Q(n, sp):
    if(n == 0):
        sp.append("987654321")
        return 987654321

    N = ((22695477 * Q(n-1,sp) + 12345) % 1073741824)
    sp.append(str(N))

    return N

sp = []
sq = []
P(200,sp)
Q(200,sq)

spString = ''.join(sp)
sqString = ''.join(sq)

def longestSubstring(spString, sqString):
    answer = ""
    len1, len2 = len(spString), len(sqString)
    for i in range(len1):
        match = ""
        for j in range(len2):
            if (i + j < len1 and spString[i + j] == sqString[j]):
                match += sqString[j]
            else:
                if (len(match) > len(answer)): answer = match
                match = ""
    return answer

longest = longestSubstring(spString, sqString)

print(longest)

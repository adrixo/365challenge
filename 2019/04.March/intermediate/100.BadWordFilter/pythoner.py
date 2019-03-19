import re
import sys

def re_bad_words(fname='badwords/badwords.txt'):
    with open(fname) as f:
        wordlist = [line.strip().strip('*(') for line in f]
    return re.compile(r'(%s)' % '|'.join(wordlist), re.I)

def filter_word(word):
    return word[0] + '*' * len(word[1:])

def filter_line(line):
    pattern = re_bad_words()
    matches = re.findall(pattern, line)
    for match in matches:
        line = re.sub(r'%s' % match, r'%s' % filter_word(match), line)
    return line

if __name__ == '__main__':
    for line in sys.stdin:
        sys.stdout.write(filter_line(line))

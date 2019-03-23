
#swimmingPastaDevil
def compare(n):
    return len(str(n))==len(set(str(n)))

print filter(compare, range(1980,1988))

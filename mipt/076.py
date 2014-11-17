def getmin(b):
    n = len(b)
    if n % 2 == 1:
        return -1
    else:
        open, close, min = 0, 0, 0
        for i in range(n):
            if b[i] == ')':
                if open - close == 0:
                    min += 1
                    open += 1
                else:
                    close += 1
            else:
                open += 1
        min += (open - close) / 2
        return min

t = getmin(raw_input())
if t == -1:
    print "NO"
else:
    print t

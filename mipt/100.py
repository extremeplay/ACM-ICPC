n, a = int(raw_input()), map(int, raw_input().split())
s = reduce(lambda acc, aa: acc ^ aa, a, 0)
if s == 0:
    print 'Second wins.'
else:
    print 'First wins.'
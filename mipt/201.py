n = int(input())

dpold = [0] * (n + 1)

dpold[0] = 1

for num in range(1, 5):
    dpnew = dpold[:]
    dpnew[0] = 1
    for i in range(1, n + 1):
        for j in range(1, i / num + 1):
            dpnew[i] += dpold[i - num * j]
    dpold = dpnew

print dpold[n]

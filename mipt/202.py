n = int(input())

dp = [0] * (n + 1)
dp[0] = 1

for i in range(1, n + 1):

    dpnew = dp[:]
    for j in range(1, n + 1):
        for k in range(1, j / i + 1):
            dpnew[j] += dp[j - k * i]
    dp = dpnew

print dp[n]
# def go(n):
#
# if n==0:
#         return 0
#     if n==1:
#         return 1
#     if n % 2 == 0:
#         return 1 + go (n >> 1)
#     else:
#         return 1 + min([go(n + 1), go(n - 1)])
#
# def main():
#     n = int(input())
#     print go(n)
#
# main()


def go(n, dp):
    if not n in dp.keys():
        if n == 0:
            dp[0] = 0
        elif n == 1:
            dp[1] = 1
        elif n % 2 == 0:
            dp[n] = 1 + go(n >> 1, dp)
        else:
            dp[n] = 1 + min([go(n + 1, dp), go(n - 1, dp)])

    return dp[n]


def main():
    n = int(input())
    print go(n, {})
    pass


main()

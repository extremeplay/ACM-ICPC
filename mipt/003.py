def dfs(a, k, l, vis):
    if vis[k]:
        return
    vis[k] = 1

    for i in range(len(a[k])):
        if a[k][i] == '#' or a[k][i] == '+':
            pass
        else:  # a[k][i] == '-'
            dfs(a, i, l, vis)

    l.append(k + 1)


def main():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(raw_input())

    for i in range(n):
        for j in range(i + 1, n):

            if a[j][i] == '+':
                a[i] += '-'
            else:
                a[i] += '+'

    l = []
    vis = [0] * n
    for i in range(n):
        if not vis[i]:
            dfs(a, i, l, vis)

    print ' '.join(map(str, l))


main()
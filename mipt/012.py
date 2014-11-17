def has_cycle(G, vis, n):

    if vis[n] == 1:
        return 0
    elif vis[n] == -1:
        return 1
    else:
        vis[n] = -1

        res = 0
        for i in G[n]:
            if vis.has_key(i):
                res |= has_cycle(G, vis, i)

        vis[n] = 1
        return res

def check():

    n = int(raw_input())
    G = {}
    for _ in range(n):
        g = raw_input().split()
        if G.has_key(g[0]):
            return 0
        G[g[0]] = []
        for i in range(int(g[1])):
            G[g[0]].append(g[i + 2])

    vis = {}
    for i in G.keys():
        vis[i] = 0

    for i in G.keys():
        if vis[i] == 0:
            t = has_cycle(G, vis, i)
            if t == 1:
                return 0

    return 1

if check() == 1:
    print "CORRECT"
else:
    print "NOT CORRECT"
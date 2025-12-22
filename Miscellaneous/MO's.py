import math

def MO(arr,queries):
    n =  len(arr)
    q = len(queries)
    bz = int(math.sqrt(n))

    queries.sort(key = lambda x : (x[0] // bz, x[1]))

    pl, pr, sm = 0,0,0
    res = [0 for i in range(q)]

    for i in range(q):
        l,r = queries[i]

        while(pl < l):
            sm -= arr[pl]
            pl += 1
        while(pl > l):
            pl -= 1
            sm += arr[pl]
        while(pr <= r):
            sm += arr[pr]
            pr += 1
        while(pr > r+1):
            pr -= 1
            sm -= arr[pr]

        res[i] = sm
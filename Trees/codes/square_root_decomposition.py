import sys
sys.setrecursionlimit(300000)
import math
from collections import defaultdict
adj = defaultdict(list)

n,m = map(int,input().split())
for i in range(m):
    u,v = map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)

values = list(map(int,input().split()))
euler = []
start = [0 for i in range(n+1)]
finish = [0 for i in range(n+1)]

def dfs(node,parent):
    start[node] = len(euler)
    euler.append(node)
    for child in adj[node]:
        if(child != parent):
            dfs(child,node)
    finish[node] = len(euler) - 1

dfs(1,-1)

arr = [values[node] for node in euler]

bz = int(math.sqrt(len(arr)))
num = (len(arr)+bz-1) // bz
bs = [0] * num

for i,val in enumerate(arr):
    bs[i // bz] += val

def query_subtree_sum(node):
    l = start[node]
    r = finish[node]
    total = 0
    while(l <= r):
        if(l%bz==0 and l+bz-1<=r):
            total += bs[l // bz]
            l += bz
        else:
            total += arr[l]
            l += 1
    return total

def update_node(node, new_value):
    idx = start[node]
    bnum = idx // bz
    diff = new_value - arr[idx]
    arr[idx] = new_value
    bs[bnum] += diff
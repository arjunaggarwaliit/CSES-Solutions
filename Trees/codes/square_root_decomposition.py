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
in_time = [0 for i in range(n+1)]
out_time = [0 for i in range(n+1)]

def dfs(node,parent):
    in_time[node] = len(euler)
    euler.append(node)
    for child in adj[node]:
        if(child != parent):
            dfs(child,node)
    out_time[node] = len(euler) - 1

dfs(1,-1)

arr = [values[node] for node in euler]

block_size = int(math.sqrt(len(arr)))
num_blocks = (len(arr)+block_size-1) // block_size
block_sum = [0] * num_blocks

for i,val in enumerate(arr):
    block_sum[i // block_size] += val

def query_subtree_sum(node):
    l = in_time[node]
    r = out_time[node]
    total = 0
    while(l <= r):
        if(l%block_size==0 and l+block_size-1<=r):
            total += block_sum[l // block_size]
            l += block_size
        else:
            total += arr[l]
            l += 1
    return total

def update_node(node, new_value):
    idx = in_time[node]
    block_idx = idx // block_size
    diff = new_value - arr[idx]
    arr[idx] = new_value
    block_sum[block_idx] += diff
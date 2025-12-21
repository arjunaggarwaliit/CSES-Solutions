import sys
sys.setrecursionlimit(200000)
from collections import defaultdict
adj = defaultdict(list)

n,m = map(int,input().split())

for _ in range(m):
    u,v = map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)

subtree_size = [0 for i in range(n+1)]
visited = [False for i in range(n+1)]
parent_centroid = [-1 for i in range(n+1)]

def dfs_size(node,parent):
    subtree_size[node] = 1
    for child in adj[node]:
        if(child!=parent and not visited[child]):
            subtree_size[node] += dfs_size(child,node)
    return subtree_size[node]

def find_centroid(node,parent,total_nodes):
    for child in adj[node]:
        if(child!=parent and not visited[child] and subtree_size[child] > total_nodes//2):
            return find_centroid(child,node,total_nodes)
    return node

def decompose(node,parent = -1):
    total_nodes = dfs_size(node,-1)
    centroid = find_centroid(node,-1,total_nodes)
    visited[centroid] = True
    parent_centroid[centroid] = parent

    for child in adj[centroid]:
        if not visited[child]:
            decompose(child,centroid)

decompose(1)



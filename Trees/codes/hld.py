import sys
sys.setrecursionlimit(10**7)
n = int(input())
adj = [[] for i in range(n+1)]
for i in range(n-1):
    u,v = map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)
values = [0] + list(map(int,input().split()))
par = [0] * (n+1)
depth = [0] * (n+1)
size = [0] * (n+1)
heavy = [-1] * (n+1)

def dfs(node,parent):
    par[node] = parent
    size[node] = 1
    max_size = 0
    for child in adj[node]:
        if(child != parent):
            depth[child] = depth[node] + 1
            dfs(child,node)
            size[node] += size[child]
            if(size[child] > max_size):
                max_size = size[child]
                heavy[node] = child
dfs(1,0)

head = [0] * (n+1)
pos = [0] * (n+1)
curr = 0

def decompose(node,start):
    global curr
    head[node] = start
    pos[node] = curr
    curr += 1
    if(heavy[node]!=-1):
        decompose(heavy[node],start)
    for child in adj[node]:
        if(child != par[node] and child != heavy[node]):
            decompose(child,child)
decompose(1,1)

tree = [0] * (4*n)
base = [0] * n
for i in range(1,n+1):
    base[pos[i]] = values[i]

def build(node,st,en):
    if(st==en):
        tree[node] = base[st]
    else:
        mid = (st + en)//2
        build(2*node + 1,st, mid)
        build(2*node + 2,mid+1,en)
        tree[node] = tree[2*node + 1] + tree[2*node + 2]
build(0,0,n-1)

def query(node,st,en,l,r):
    if(en<l or st>r):
        return 0
    if(st>=l and en<=r):
        return tree[node]
    mid = (st + en)//2
    return query(2*node + 1,st,mid,l,r) + query(2*node +2,mid+1,en,l,r)

def update(node, st, en, idx, val):
    if st == en:
        tree[node] = val
        return
    mid = (st + en) // 2
    if idx <= mid:
        update(2*node + 1, st, mid, idx, val)
    else:
        update(2*node + 2, mid + 1, en, idx, val)
    tree[node] = tree[2*node + 1] + tree[2*node + 2]

def path_query(u,v):
    res = 0
    while(head[u] != head[v]):
        if(depth[head[u]] < depth[head[v]]):
            u,v = v,u
        res += query(0,0,n-1,pos[head[u]],pos[u])
        u = par[head[u]]
    if(depth[u] > depth[v]):
        u,v = v,u
    res += query(0,0,n-1,pos[u],pos[v])
    return res

def update_node(u, val):
    update(0, 0, n-1, pos[u], val)

q = int(input())
for _ in range(q):
    t, *rest = map(int, input().split())
    if t == 1:
        u, v = rest
        print(path_query(u, v))
    else:
        u, x = rest
        update_node(u, x)



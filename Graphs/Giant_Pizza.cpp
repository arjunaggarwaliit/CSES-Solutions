#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> start, finish, assign;
int timer = 0;
int value = 0;

void dfs(int node) {
    timer++;
    start[node] = timer;
    for (int neigh : adj[node]) {
        if (start[neigh] == 0) {
            dfs(neigh);
        }
    }
    timer++;
    finish[node] = timer;
}

void make(int node, int val) {
    assign[node] = val;
    for (int child : adj[node]) {
        if (assign[child] == 0) {
            make(child, val);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    adj.assign(2 * m + 1, vector<int>());
    start.assign(2 * m + 1, 0);
    finish.assign(2 * m + 1, 0);
    assign.assign(2 * m + 1, 0);
    for (int i = 0; i < n; ++i) {
        char c1, c2;
        int n1, n2;
        cin >> c1 >> n1 >> c2 >> n2;
        if (c1 == '+' && c2 == '+') {
            adj[n1 + m].push_back(n2);
            adj[n2 + m].push_back(n1);
        } else if (c1 == '+' && c2 == '-') {
            adj[n1 + m].push_back(n2 + m);
            adj[n2].push_back(n1);
        } else if (c1 == '-' && c2 == '+') {
            adj[n1].push_back(n2);
            adj[n2 + m].push_back(n1 + m);
        } else {
            adj[n1].push_back(n2 + m);
            adj[n2].push_back(n1 + m);
        }
    }
    for (int i = 1; i <= 2 * m; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    for (int i = 1; i <= 2 * m; ++i) {
        if (start[i] == 0) {
            dfs(i);
        }
    }
    vector<int> lis(2 * m);
    iota(lis.begin(), lis.end(), 1);
    sort(lis.begin(), lis.end(), [](int a, int b) {
        return finish[a] < finish[b];
    });
    for (int node : lis) {
        if (assign[node] == 0) {
            value++;
            make(node, value);
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (assign[i] == assign[i + m]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (assign[i] < assign[i + m]) {
            cout << "+ ";
        } else {
            cout << "- ";
        }
    }
    cout << endl;
}

// Python Implementation
// import sys
// sys.setrecursionlimit(10**7)
// input = sys.stdin.readline
// from collections import defaultdict
// n,m = map(int,input().split())
// adj = [[] for i in range(2*m + 1)]
// def dfs(node,start,finish,timer):
//     timer[0] += 1
//     start[node] = timer[0]
//     for neigh in adj[node]:
//         if(start[neigh] == 0):
//             dfs(neigh,start,finish,timer)
//     timer[0] +=1
//     finish[node] = timer[0]
// def make(node,assign,value):
//     assign[node] = value[0]
//     for child in adj[node]:
//         if(assign[child] == 0):
//             make(child,assign,value)
// for _ in range(n):
//     c1,n1,c2,n2 = input().split()
//     n1 = int(n1)
//     n2 = int(n2)
//     if(c1=='+' and c2=='+'):
//         adj[n1+m].append(n2)
//         adj[n2+m].append(n1)
//     elif(c1=='+' and c2=='-'):
//         adj[n1+m].append(n2+m)
//         adj[n2].append(n1)
//     elif(c1=='-' and c2=='+'):
//         adj[n1].append(n2)
//         adj[n2+m].append(n1+m)
//     else:
//         adj[n1].append(n2+m)
//         adj[n2].append(n1+m)
// for i in range(len(adj)):
//     adj[i] = list(set(adj[i]))
// # print(adj)
// timer = [0]
// assign = [0 for i in range(2*m + 1)]
// start = [0] *(2*m + 1)
// finish = [0] *(2*m + 1)
// for i in range(1,2*m + 1):
//     if(start[i] == 0):
//         dfs(i,start,finish,timer)
// value = [0]
// lis = sorted([i+1 for i in range(2*m)],key = lambda x : finish[x])
// for node in lis:
//     if(assign[node] == 0):
//         value[0] += 1
//         make(node,assign,value)
// # print(assign)
// for i in range(1,m+1):
//     if(assign[i] == assign[i+m]):
//         # print(i)
//         print("IMPOSSIBLE")
//         exit()
// pres = [-1 for _ in range(2*m+1)]
// for i in range(1,m+1):
//     if(assign[i] < assign[i+m]):
//         pres[i] = 1
//     else:
//         pres[i] = 0
// for i in range(1,m+1):
//     if(pres[i] == 1):
//         print("+",end = " ")
//     else:
//         print("-",end = " ")

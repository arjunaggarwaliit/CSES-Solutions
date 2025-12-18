#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node, int parent, vector<int>& vec, vector<vector<int>>& adj) {
    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node, vec, adj);
        vec[node] += (vec[child] + 1);
    }
}
 
int32_t main() {
 
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n+1);
    vector<int> par(n-1);
 
    for (int i = 0; i < n-1; i++) {
        cin >> par[i];
    }
 
    for (int i = 2; i <= n; i++) {
        adj[i].push_back(par[i-2]);
        adj[par[i-2]].push_back(i);
    }
 
    vector<int> vec(n+1, 0);
    dfs(1, -1, vec, adj);
 
    for (int i = 1; i <= n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
 
    return 0;
}
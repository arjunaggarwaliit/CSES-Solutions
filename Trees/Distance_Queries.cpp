#include <bits/stdc++.h>
using namespace std;
#define int long long

struct LCA {
    int n, LOG;
    vector<vector<int>> dp;
    vector<int> parent;
    vector<int> depth;

    void init(int _n){
        this -> n = _n;
        this -> LOG = 32-__builtin_clz(n);
        dp.assign(n+1,vector<int>(LOG));
        parent.resize(n+1);
        depth.assign(n+1,-1);
    }

    void dfs(int node, int par, const vector<int> adj[]){
        parent[node] = par;
        depth[node] = depth[par] + 1;
        for(auto child : adj[node]){
            if(child == par) continue;
            dfs(child,node,adj);
        }
    }

    void binary_lift(){
        for(int i=1 ; i<=n ; i++){
            dp[i][0] = parent[i];
        }
        for(int j=1 ; j<LOG ; j++){
            for(int i=1 ; i<=n ; i++){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }

    void build(const vector<int> adj[]){
        dfs(1,1,adj);
        binary_lift();
    }

    int ancestor(int k, int node){
        for(int i=LOG-1 ; i>=0 ; i--){
            if((k & (1LL<<i)) != 0) node = dp[node][i];
        }
        return node;
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u,v);
        u = ancestor(depth[u] - depth[v],u);
        if(u == v) return u;
        for(int i=LOG-1 ; i>=0 ; i--){
            if(dp[u][i] != dp[v][i]){
                u = dp[u][i]; v = dp[v][i];
            }
        }
        return dp[u][0];
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> adj[n+1];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA tree;
    tree.init(n);
    tree.build(adj);
    vector<int> depth = tree.depth;
    while(q--){
        int u,v ; cin >> u >> v;
        cout << depth[u] + depth[v] - 2* depth[tree.lca(u,v)] << endl;
    }
}
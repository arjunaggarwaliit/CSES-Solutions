#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
void dfs(int node, const vector<int> adj[], vector<int> & topo, vector<bool>& vis){
    vis[node] = true;
    for(auto neigh : adj[node]){
        if(!vis[neigh]){
            dfs(neigh , adj, topo, vis);
        }
    }
    topo.push_back(node);
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ;i<m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> topo;
    vector<bool> vis(n+1,false);
    dfs(1, adj, topo, vis);
    bool found = false;
    for(auto ele : topo){
        if(ele == n){
            found = true;
            break;
        }
    }
    if(!found){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    reverse(topo.begin(), topo.end());
    for(int i=0 ; i< topo.size() ; i++){
        int node = topo[i];
        for(auto neigh : adj[node]){
            dp[neigh] += dp[node];
            dp[neigh]%=MOD;
        }
    }
    cout << dp[n] << endl;
}
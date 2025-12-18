#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,int par,vector<vector<int>>& adj,vector<bool>& vis){
    if(adj[node].size()==1 && adj[node][0]==par) return 0;
    int total = 0;
    for(auto child : adj[node]){
        if(child == par) continue;
        else{
            total += dfs(child,node,adj,vis);
            if(vis[node]==false && vis[child]==false){
                total += 1;
                vis[node] = true;
                vis[child] = true;
            }
        }
    }
    return total;
}
int32_t main(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b ; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    cout << dfs(1,-1,adj,vis) << endl;
}
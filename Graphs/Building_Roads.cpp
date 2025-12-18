#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node, vector<int>&vis, const vector<int> adj[]){
    vis[node] = 1;
    for(auto neigh : adj[node]){
        if(!vis[neigh]){
            dfs(neigh, vis, adj);
        }
    }
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,false);
    vector<int> points;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            points.push_back(i);
            dfs(i,vis,adj);
        }
    }
    cout << points.size() - 1 << endl;
    if(points.size() != 0){
        for(int i=1; i< points.size();i++){
            cout << points[i-1] << " " << points[i] << endl;
        }
    }
}
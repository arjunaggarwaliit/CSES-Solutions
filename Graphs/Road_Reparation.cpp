#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,const vector<pair<int,int>> adj[],vector<bool>&vis){
    vis[node] = true;
    for(auto neigh : adj[node]){
        int child = neigh.first;
        int w = neigh.second;
        if(vis[child]) continue;
        else{
            dfs(child,adj,vis);
        }
    }
}
int prims(int n,const vector<pair<int,int>> adj[]){
    vector<int> dist(n+1,LLONG_MAX);
    vector<int> vis(n+1,false);
    dist[1] = 0;
    int total = 0;
    set<pair<int,int>> s;
    s.insert({0,1});
    while(!s.empty()){
        pair<int,int> ele = *(s.begin());
        s.erase(s.begin());
        int node = ele.second;
        int d = ele.first;
        if(d != dist[node]) continue;
        vis[node] = true;
        // cout << node << " " << d << endl;
        total += ele.first;
        for(auto neigh : adj[node]){
            int child = neigh.first;
            int w = neigh.second;
            if(vis[child]) continue;
            if(dist[child] > w){
                dist[child] = w;
                s.insert({w,child});
            }
        }
    }
    return total;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    while(m--){
        int a,b,c ; cin >> a>> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<bool> vis(n+1,false);
    dfs(1,adj,vis);
    bool flag = true;
    for(int i=1 ; i<=n ; i++){
        flag = flag & vis[i];
        if(flag == false) break;
    }
    if(flag){
        cout << prims(n,adj) << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
void kahn(int n , const vector<int> adj[], vector<int>& topo){
    set<int> s;
    vector<int> indegree(n+1,0);
    for(int i=1 ; i<=n ; i++){
        for(auto neigh : adj[i]){
            indegree[neigh] += 1;
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(indegree[i] == 0){
            s.insert(i);
        }
    }
    while(!s.empty()){
        int node = *(s.begin());
        s.erase(s.begin());
        topo.push_back(node);
        for(auto neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                s.insert(neigh);
            }
        }
    }
}
void dfs(int node, const vector<int> adj[], vector<int> & topo, vector<bool>& vis){
    vis[node] = true;
    for(auto neigh : adj[node]){
        if(!vis[neigh]){
            dfs(neigh , adj, topo, vis);
        }
    }
    topo.push_back(node);
}
void dfs_wrapper(int node, const vector<int> adj[], vector<int>& topo, vector<bool> &vis){
    vector<int> local;
    dfs(node, adj, local, vis);
    reverse(local.begin(),local.end());
    for(auto ele : local){
        topo.push_back(ele);
    }
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> topo;
    kahn(n, adj, topo);
    if(topo.size() < n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto ele : topo){
            cout << ele << " ";
        }
        cout << endl;
    }
}
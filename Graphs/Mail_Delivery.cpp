#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>> adj[100005];
void dfs(int node,vector<bool>& visited){
    visited[node] = true;
    for(auto child : adj[node]){
        if(!visited[child.first]){
            dfs(child.first,visited);
        }
    }
}

void e_dfs(int node, vector<bool>& visited, vector<int>& circuit){
    while(!adj[node].empty()){
        pair<int,int>pr = adj[node].back();
        adj[node].pop_back();
        if(visited[pr.second]) continue;
        else{
            visited[pr.second] = true;
            e_dfs(pr.first,visited,circuit);
        }
    }
    circuit.push_back(node);
}

int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> deg(n+1,0);
    vector<bool> visited(n+1,false);
    vector<bool> e_visited(m, false);
    for(int i=0 ; i<m ; i++){
        int a,b; cin >> a >> b;
        deg[a]++; deg[b]++;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    dfs(1,visited);
    for(int i=1 ; i<=n ; i++){
        if(visited[i] == false && deg[i]>0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(deg[i]&1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    vector<int> circuit;
    e_dfs(1,e_visited,circuit);
    for(auto node : circuit){
        cout << node << " ";
    }
    cout << endl;
}
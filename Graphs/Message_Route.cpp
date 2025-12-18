#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> bfs(const vector<int> adj[], int n){
    vector<int> parent(n+1,-1);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto neigh : adj[node]){
            if(neigh == 1) continue;
            if(parent[neigh] == -1){
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }
    vector<int> comps;
    int temp = n;
    while(1){
        comps.push_back(temp);
        if(parent[temp] == -1){
            break;
        }
        else{
            temp = parent[temp];
        }
    }
    reverse(comps.begin(),comps.end());
    return comps;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b; cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans = bfs(adj,n);
    if(ans.size() == 1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << ans.size() << endl;
        for(auto node : ans){
            cout << node << " ";
        }
        cout << endl;
    }
}
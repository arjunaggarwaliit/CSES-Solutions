#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node, const vector<int> adj[], vector<int>& start, vector<int>& finish,int &timer){
    start[node] = ++timer;
    for(auto child : adj[node]){
        if(start[child] == -1){
            dfs(child,adj,start,finish,timer);
        }
    }
    finish[node] = ++timer;
}

void dfs_(int node, const vector<int> radj[], const int& idx, vector<int>& scc){
    scc[node] = idx;
    for(auto child : radj[node]){
        if(scc[child] == 0){
            dfs_(child, radj, idx, scc);
        }
    }
}

void dfs__(int node, const vector<int> dag[], vector<int>& topo, vector<bool>& visited){
    visited[node] = true;
    for(auto child : dag[node]){
        if(!visited[child]){
            dfs__(child, dag, topo, visited);
        }
    }
    topo.push_back(node);
}

int32_t main(){
    int n,m ; cin >> n >> m;
    vector<int> k(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> k[i];
    }
    vector<int> adj[n+1];
    vector<int> radj[n+1];
    for(int i=1 ; i<=m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> start(n+1,-1);
    vector<int> finish(n+1,-1);
    int timer = 0;
    vector<int> topo;
    for(int i=1 ; i<=n ; i++){
        topo.push_back(i);
        if(start[i] == -1){
            dfs(i,adj,start,finish,timer);
        }
    }
    sort(topo.begin(),topo.end(),[&](int a,int b){
        return (finish[a] > finish[b]);
    });
    vector<int> scc(n+1,0);
    int idx = 0;
    for(auto node : topo){
        if(scc[node] == 0){
            idx += 1;
            dfs_(node,radj,idx,scc);
        }
    }
    vector<int> coins(idx + 1,0);
    for(int i=1 ; i<=n ; i++){
        coins[scc[i]] += k[i];
    }
    vector<int> dag[idx + 1];
    for(int i=1 ; i<=n ; i++){
        for(auto node : adj[i]){
            dag[scc[i]].push_back(scc[node]);
        }
    }
    for(int i=1 ;i<=idx ; i++){
        sort(dag[i].begin(),dag[i].end());
        dag[i].erase(unique(dag[i].begin(),dag[i].end()),dag[i].end());
    }
    vector<bool> visited(idx+1, false);
    topo.clear();
    for(int i=1 ; i<= idx ; i++){
        if(visited[i] == false){
            dfs__(i,dag,topo,visited);
        }
    }
    reverse(topo.begin(),topo.end());
    vector<int> ans(topo.size());
    vector<int> ind(topo.size() + 1);
    for(int i=0 ; i<idx ; i++){
        ans[i] = coins[topo[i]];
        ind[topo[i]] = i;
    }
    cout << endl;
    for(int i=0 ; i<idx ; i++){
        for(auto node: dag[topo[i]]){
            if(node == topo[i]) continue;
            ans[ind[node]] = max(ans[ind[node]],coins[node]+ans[i]);
        }
    }
    cout << *(max_element(ans.begin(),ans.end())) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node, const vector<int> adj[], vector<bool>& visited){
    visited[node] = true;
    for(auto child : adj[node]){
        if(!visited[child]) dfs(child, adj, visited);
    }
}

vector<int> hierholzer_directed(int n, const vector<int> adj[]){
    vector<int> circuit;
    stack<int> st;
    vector<int> covered(n+1,0);
    st.push(1);
    while(!st.empty()){
        int node = st.top();
        if(covered[node] == adj[node].size()){
            circuit.push_back(node);
            st.pop();
        }
        else{
            st.push(adj[node][covered[node]]);
            covered[node]++;
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> in(n+1,0);
    vector<int> adj[n+1];
    for(int i=1 ; i<=m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    vector<bool> visited(n+1,false);
    dfs(1, adj, visited);
    if((adj[1].size() == in[1]+1) && (visited[n] && adj[n].size() == in[n]-1)){
        for(int node = 2; node < n ; node ++){
            if(visited[node]==false && (in[node]>0 || adj[node].size()>0)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if(visited[node]==true && (in[node] != adj[node].size())){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> circuit = hierholzer_directed(n,adj);
    for(auto node : circuit){
        cout << node << " ";
    }
    cout << "\n";
}
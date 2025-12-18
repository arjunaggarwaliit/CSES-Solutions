#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> from1(int n, const vector<pair<int,int>> adj[]){
    vector<bool> reach(n+1,false);
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(reach[node]){
            continue;
        }
        else reach[node] = true;
        for(auto neigh : adj[node]){
            int child = neigh.first;
            if(!reach[child]){
                st.push(child);
            }
        }
    }
    return reach;
}
vector<bool> fromn(int n, const vector<pair<int,int>> adj[]){
    vector<int> adjn[n+1];
    for(int i=1; i<=n ; i++){
        for(auto neigh : adj[i]){
            int child = neigh.first;
            adjn[child].push_back(i);
        }
    }
    vector<bool> reach(n+1,false);
    stack<int> st;
    st.push(n);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(reach[node]) continue;
        else reach[node] = true;
        for(auto neigh : adjn[node]){
            int child = neigh;
            if(!reach[child]){
                st.push(child);
            }
        }
    }
    return reach;
}
int bellman(int n, const vector<pair<int,int>> adj[]){
    vector<int> dist(n+1,LLONG_MAX);
    dist[1] =0;
    for(int i=1; i<= n-1; i++){
        for(int j=1 ; j<=n ; j++){
            for(auto neigh : adj[j]){
                int w = neigh.second;
                int v = neigh.first;
                if(dist[j] == LLONG_MAX){
                    continue;
                }
                if(w + dist[j] < dist[v]){
                    dist[v] = w + dist[j];
                }
            }
        }
    }
    // for(auto distance : dist){
    //     cout << distance << " ";
    // }
    // cout << endl;
    set<int> cycle_nodes;
    for(int node = 1; node <=n ; node ++){
        for(auto neigh : adj[node]){
            if(dist[node] == LLONG_MAX){
                continue;
            }
            if(neigh.second + dist[node] < dist[neigh.first]){
                cycle_nodes.insert(neigh.first);
            }
        }
    }
    // for(auto node : cycle_nodes){
    //     cout << node << " ";
    // }
    // cout << endl;
    // vector<bool> onereach = from1(n,adj);
    vector<bool> nreach = fromn(n,adj);
    for(auto node : cycle_nodes){
        if(nreach[node]){
            return -1;
        }
    }
    return -dist[n];
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,-c});
    }
    cout << bellman(n,adj) << endl;
}
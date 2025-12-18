#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX
void dfs(int node, vector<bool> &vis, int &size, const vector<pair<int,int>> adj[], vector<int> &nodes){
    vis[node] = true;
    size+=1;
    nodes.push_back(node);
    for(auto neigh : adj[node]){
        if(!vis[neigh.first]){
            dfs(neigh.first,vis,size,adj,nodes);
        }
    }
}
pair<bool,vector<int>> bellman_cycle(const vector<pair<int,int>> adj[],vector<int>& parent, vector<int> & dist, int n, int source,
vector<int> &nodes){
    dist[source] = 0;
    bool flag;
    int point = -1;
    for(int iter = 1 ; iter <= n ; iter++){
        flag = true;
        for(auto node : nodes){
            for(auto neigh : adj[node]){
                int child = neigh.first;
                int w = neigh.second;
                if(dist[node] == inf) continue;
                if(dist[child] > dist[node] + w){
                    dist[child] = dist[node] + w;
                    parent[child] = node;
                    flag = false;
                    point = child;
                }
            }
        }
    }
    if(!flag){
        int node = point;
        int temp= n;
        while(temp--){
            node = parent[node];
        }
        vector<int> cycle;
        cycle.push_back(node);
        node = parent[node];
        while(1){
            if(node == cycle[0]){
                cycle.push_back(node);
                break;
            }
            else{
                cycle.push_back(node);
                node = parent[node];
            }
        }
        reverse(cycle.begin(),cycle.end());
        return {true,cycle};
    }
    else{
        return {false,{}};
    }
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m ; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<int> parent(n+1,-1);
    vector<int> dist(n+1,inf);
    int ok = true;
    for(int i =1; i<= n ; i++){
        if(dist[i] == LLONG_MAX){
            int size = 0;
            vector<int> nodes;
            vector<bool> vis(n+1,false);
            dfs(i,vis,size,adj,nodes);
            pair<bool,vector<int>> pr = bellman_cycle(adj,parent,dist,size,i,nodes);
            if(pr.first == true){
                for(int j=1 ; j<=n ; j++){
                    cout << parent[j] << " ";
                }
                cout << endl;
                cout << "YES" << endl;
                for(auto it : pr.second){
                    cout << it << " ";
                }
                cout << endl;
                ok = false;
                break;
            }
        }
    }
    if(ok){
                        for(int j=1 ; j<=n ; j++){
                    cout << parent[j] << " ";
                }
                cout << endl;
        cout << "NO" << endl;
    }
}
// testing purposes
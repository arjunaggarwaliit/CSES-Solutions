#include <bits/stdc++.h>
using namespace std;
#define int long long

int find_augmenting_path(int source, int sink,const vector<int> adj[], vector<int>& parent,
vector<vector<int>> & residual){
    parent[source] = -2;
    queue<pair<int,int>> q;
    q.push({source,LLONG_MAX});
    while(!q.empty()){
        pair<int,int> pr = q.front();
        q.pop();
        int flow_till_now = pr.second;
        int vertex = pr.first;
        for(auto child : adj[vertex]){
            if(parent[child] == -1 && residual[vertex][child] > 0){
                int flow_after_node = min(flow_till_now, residual[vertex][child]);
                parent[child] = vertex;
                if(child == sink){
                    return flow_after_node;
                }
                q.push({child,flow_after_node});
            }
        }
    }
    return 0;
}

int edmonds_karp_max_flow(int source, int sink, const vector<int> adj[], vector<vector<int>>& residual, int n){
    int total_flow = 0;
    while(1){
        vector<int> parent(n+1,-1);
        int flow_to_add = find_augmenting_path(source,sink,adj,parent,residual);
        if(flow_to_add > 0){
            total_flow += flow_to_add;
            int node = sink;
            while(node != source){
                residual[parent[node]][node] -= flow_to_add;
                residual[node][parent[node]] += flow_to_add;
                node = parent[node];
            }
            continue;
        }
        else{
            return total_flow;
        }
    }
}

int32_t main(){
    int n; int m;
    cin >> n >> m;
    vector<vector<int>> residual (n+1, vector<int>(n+1,0));
    vector<int> adj[n+1];
    for(int i=0; i<m ; i++){
        int a,b,c; cin >> a >> b >>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        residual[a][b] = c;
    }
    cout << edmonds_karp_max_flow(1,n,adj,residual,n) << endl;
}


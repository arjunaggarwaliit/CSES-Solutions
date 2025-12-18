#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dfsvis(200005,-1);
vector<int> bfsdist(200005, -1);
vector<int> parent(200005, -1);
static int dp[18][200005];
vector<int> cycle(200005,-1);
map<int,int> mp;
void binary_jump(int n){
    for(int i=1; i<18; i++){
        for(int j=1 ; j<=n ; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}
int steps(int temp,int k){
    int node = temp;
    for(int i=17; i>=0 ; i--){
        if(k&(1<<i)){
            node = dp[i][node];
        }
    }
    return node;
}
void bfs_cycle(int start, const vector<int> radj[]){
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        pair<int,int> pr = q.front();
        q.pop();
        int node = pr.first;
        for(auto neigh: radj[node]){
            if(cycle[neigh]!=-1) continue;
            bfsdist[neigh] = pr.second + 1;
            q.push({neigh,bfsdist[neigh]});
        }
    }
}
void dfs_cycle(int n,int start, const vector<int> adj[], const vector<int> radj[], int iter){
    stack<int> st;
    st.push(start);
    vector<int> cycle_nodes;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dfsvis[node] == 0){
            dfsvis[node] = 1;
        }
        else{
            dfsvis[node] = 0;
            st.push(node);
        }
        for(auto neigh : adj[node]){
            if(dfsvis[neigh] == 1){
                continue;
            }
            else if(dfsvis[neigh] == -1){
                st.push(neigh);
                parent[neigh] = node;
            }
            else{
                int temp = node;
                while(1){
                    if(temp == neigh){
                        cycle[temp] = iter;
                        cycle_nodes.push_back(temp);
                        break;
                    }
                    else{
                        cycle[temp] = iter;
                        cycle_nodes.push_back(temp);
                        temp = parent[temp];
                    }
                }
                mp[iter] = cycle_nodes.size();
                break;
            }
        }
        if(!cycle_nodes.empty()){
            break;
        }
    }
    reverse(cycle_nodes.begin(),cycle_nodes.end());
    for(int i=0 ; i< cycle_nodes.size(); i++){
        bfsdist[cycle_nodes[i]] = i;
        bfs_cycle(cycle_nodes[i],radj);
    }
}
int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> tele(n+1,-1);
    vector<int> radj[n+1];
    vector<int> adj[n+1];
    for(int i=1 ; i<=n ; i++){
        cin >> tele[i];
        radj[tele[i]].push_back(i);
        adj[i].push_back(tele[i]);
        dp[0][i] = tele[i];
    }
    binary_jump(n);
    for(int i=1 ; i<=n ; i++){
        if(bfsdist[i] == -1){
            dfs_cycle(n,i,adj,radj,i);
        }
    }
    while(q--){
        int u,v; cin >> u >> v;
        if(cycle[u]!=-1 && cycle[v]!=-1){
            if(cycle[u] == cycle[v]){
                int cycle_length = mp[cycle[u]];
                if(bfsdist[u] < bfsdist[v]){
                    cout << bfsdist[v] - bfsdist[u] << endl;
                }
                else if(bfsdist[u] == bfsdist[v]){
                    cout << 0 << endl;
                }
                else{
                    cout << cycle_length - abs(bfsdist[v] - bfsdist[u]) << endl;
                }
            }
            else{
                cout << -1 << endl;
            }
        }
        else if(cycle[u]==-1 && cycle[v]==-1){
            if(bfsdist[u] >= bfsdist[v]){
                int nodeu = steps(u,bfsdist[u]-bfsdist[v]);
                if(nodeu == v){
                    cout << bfsdist[u]-bfsdist[v] << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }
            else{
                cout << -1 << endl;
            }
        }
        else if(cycle[u]==-1 && cycle[v]!=-1){
            int nodeu = steps(u,bfsdist[u]);
            if(cycle[nodeu] == cycle[v]){
                int cycle_length = mp[cycle[nodeu]];
                if(bfsdist[nodeu] < bfsdist[v]){
                    cout << bfsdist[v] - bfsdist[nodeu] + bfsdist[u] << endl;
                }
                else if(bfsdist[nodeu] == bfsdist[v]){
                    cout << bfsdist[u] << endl;
                }
                else{
                    cout << cycle_length - abs(bfsdist[v] - bfsdist[nodeu]) + bfsdist[u] << endl;
                }
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
}
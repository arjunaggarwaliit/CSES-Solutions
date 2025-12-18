#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dfs_directed(int n,const vector<int> adj[], int source, vector<int>&vis, vector<int>& parent){
    stack<int> st;
    st.push(source);
    while(!st.empty()){
        int node = st.top(); st.pop();
        if(vis[node] == 0){
            vis[node] = 1;
            continue;
        }
        else{
            vis[node] = 0;
            st.push(node);
            for(auto child : adj[node]){
                if(vis[child] == 0){
                    int temp = node;
                    vector<int> cycle;
                    while(1){
                        if(temp == child){
                            cycle.push_back(temp);
                            break;
                        }
                        else{
                            cycle.push_back(temp);
                            temp = parent[temp];
                        }
                    }
                    reverse(cycle.begin(),cycle.end());
                    cycle.push_back(child);
                    return cycle;
                }
                else if(vis[child] == 1){
                    continue;
                }
                else{
                    st.push(child);
                    parent[child] = node;
                }
            }
        }
    }
    return {};
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1,-1);
    vector<int> parent(n+1,-1);
    bool ok = true;
    for(int i=1 ; i<=n ; i++){
        if(vis[i] == -1){
            vector<int> ans = dfs_directed(n,adj,i,vis,parent);
            if(ans.empty()){
                continue;
            }
            else{
                cout << ans.size() << endl;
                for(auto node : ans){
                    cout << node << " ";
                }
                cout << endl;
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout << "IMPOSSIBLE" << endl;
    }
}
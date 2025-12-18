#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dfs(int start,const vector<int> adj[],int n, vector<int> & parent, vector<int>& vis){
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node]) continue;
        else{
            vis[node] = true;
        }
        for(auto neigh : adj[node]){
            if(neigh == parent[node]){
                continue;
            }
            else{
                if(vis[neigh]){
                    vector<int> ans;
                    int temp = node;
                    while(1){
                        ans.push_back(temp);
                        if(parent[temp] == neigh){
                            ans.push_back(neigh);
                            break;
                        }
                        else {
                            temp = parent[temp];
                        }
                    }
                    reverse(ans.begin(),ans.end());
                    ans.push_back(neigh);
                    return ans;
                }
                else{
                    parent[neigh] = node;
                    st.push(neigh);
                }
            }
        }
    }
    return {};
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1,-1);
    vector<int> vis(n+1,false);
    bool ok = true;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        else{
            vector<int> ans = dfs(i,adj,n,parent,vis);
            if(!ans.empty()){
                cout << ans.size() << endl;
                for(auto ele : ans){
                    cout << ele << " ";
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool dfs(int start, vector<int>& teams,const vector<int> adj[], int n){
    stack<int> st;
    st.push(start);
    teams[start] = 1;
    vector<int> vis(n+1,false);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node] == true){
            continue;
        }
        else{
            vis[node]  = true;
        }
        for(auto neigh : adj[node]){
            if(teams[neigh] == 0){
                if(teams[node] == 1) teams[neigh] = 2;
                else teams[neigh] = 1;
                st.push(neigh);
            }
            else{
                if(teams[node]==1){
                    if(teams[neigh] == 2) continue;
                    else return false;
                }
                else{
                    if(teams[neigh] == 1) continue;
                    else return false;
                }
            }
        }
    }
    return true;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> teams(n+1,0);
    bool ok = true;
    for(int i=1; i<=n ; i++){
        if(teams[i] == 0){
            bool flag = dfs(i,teams,adj,n);
            if(flag == false){
                cout << "IMPOSSIBLE" << endl;
                ok = false;
                break;
            }
        }
    }
    if(ok){
        for(int i=1; i<=n; i++){
            cout << teams[i] << " ";
        }
        cout << endl;
    }
}
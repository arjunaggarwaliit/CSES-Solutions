#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs_tarjan(int node, const vector<int> adj[], vector<int>& low, stack<int>& st,
    vector<bool>& instack, vector<int>& start, int& timer, vector<int>& victims){
    start[node] = low[node] = timer++;
    st.push(node);
    instack[node] = true;
    for(auto child : adj[node]){
        if(start[child] == -1){
            dfs_tarjan(child,adj,low,st,instack,start,timer,victims);
            low[node] = min(low[node],low[child]);
        }
        else{
            if(instack[child]){
                low[node] = min(low[node], start[child]);
            }
        }
    }
    if(low[node] == start[node]){
        victims.push_back(node);
        while(true){
            int temp = st.top(); st.pop();
            instack[temp] = false;
            if(temp == node) break;
        }
    }
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> low(n+1,-1);
    vector<int> start(n+1,-1);
    int timer = 0;
    stack<int> st;
    vector<bool> instack(n+1,false);
    bool flag = true;
    for(int i=1 ; i<=n ; i++){
        if(start[i] == -1){
            if(i!=1){
                cout << "NO" << endl;
                cout << 1 << " " << i << endl;
                flag = false;
                break;
            }
            vector<int> victims;
            dfs_tarjan(i,adj,low,st,instack,start,timer,victims);
            if(victims.size() == 1){
                continue;
            }
            else{
                cout << "NO" << endl;
                cout << victims[0] << " " << victims[1] << endl;
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "YES" << endl;
    }
}
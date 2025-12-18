#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs_tarjan(int node, const vector<int> adj[], vector<int>& low, stack<int>& st,
    vector<bool>& instack, vector<int>& start, int& timer, int& iter, vector<int>& group){
    start[node] = low[node] = timer++;
    st.push(node);
    instack[node] = true;
    for(auto child : adj[node]){
        if(start[child] == -1){
            dfs_tarjan(child,adj,low,st,instack,start,timer,iter,group);
            low[node] = min(low[node],low[child]);
        }
        else{
            if(instack[child]){
                low[node] = min(low[node], start[child]);
            }
        }
    }
    if(low[node] == start[node]){
        iter++;
        while(true){
            int temp = st.top(); st.pop();
            instack[temp] = false;
            group[temp] = iter;
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
    int iter = 0;
    vector<int> group(n+1,-1);
    for(int i=1 ; i<=n ; i++){
        if(start[i] == -1){
            dfs_tarjan(i,adj,low,st,instack,start,timer,iter,group);
        }
    }
    cout << iter << endl;
    for(int i=1 ; i<=n ; i++){
        cout << group[i] << " ";
    }
    cout << endl;
}
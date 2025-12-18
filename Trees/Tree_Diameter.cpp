#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> maxdepth(int node,int par,vector<vector<int>>& adj){
    if(adj[node].size()==1 && adj[node][0]==par) return {0,node};
    int maxx = INT_MIN;
    int coming = node;
    for(auto child : adj[node]){
        if(child == par) continue;
        pair<int,int> childepth = maxdepth(child,node,adj);
        if(childepth.first > maxx){
            maxx = childepth.first;
            coming = childepth.second;
        }
    }
    return {maxx+1,coming};
}
int32_t main(){
    int n; cin >> n;
    if(n==1){
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int,int> itera = maxdepth(1,-1,adj);
    cout << maxdepth(itera.second,-1,adj).first << endl;
}

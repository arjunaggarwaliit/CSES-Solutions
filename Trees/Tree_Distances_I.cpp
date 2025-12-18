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
void distances(int node,vector<vector<int>>&adj,vector<int>&dist){
    queue<int> q;
    q.push(node);
    int level = 0;
    int n = adj.size();
    vector<bool> vis(n,false);
    vis[node] = true;
    while(!q.empty()){
        queue<int> qq;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            dist[ele] = level;
            for(auto child : adj[ele]){
                if(vis[child] == false){
                    vis[child] = true;
                    qq.push(child);
                }
            }
        }
        q = qq;
        level +=1;
    }
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
    pair<int,int> iterb = maxdepth(itera.second,-1,adj);
    vector<int> dista(n+1,0);
    vector<int> distb(n+1,0);
    distances(itera.second,adj,dista);
    distances(iterb.second,adj,distb);
    for(int i=1;i<=n;i++){
        cout << max(dista[i],distb[i]) << " ";
    }
    cout << endl;
}

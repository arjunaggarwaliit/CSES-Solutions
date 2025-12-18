#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfsbuild(int node,int par,vector<int> adj[],vector<pair<int,int>>&info){
    for(auto child: adj[node]){
        if(child == par) continue;
        dfsbuild(child,node,adj,info);
        info[node].first += info[child].first;
        info[node].second += (info[child].second + info[child].first);
    }
}
void dfsspread(int node,int par,vector<int> adj[],vector<pair<int,int>>&info,int n){
    for(auto child: adj[node]){
        if(child == par) continue;
        info[child].second = info[node].second + n - (2*(info[child].first));
        dfsspread(child,node,adj,info,n);
    }
}
int32_t main(){
    int n; cin >> n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int,int>> info(n+1,{1,0});
    dfsbuild(1,-1,adj,info);
    dfsspread(1,-1,adj,info,n);
    for(int i=1;i<=n;i++){
        cout << info[i].second << " ";
    }
    cout << endl;
}
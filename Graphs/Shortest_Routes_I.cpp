#include <bits/stdc++.h>
using namespace std;
#define int long long
void dijkstra(int n, vector<pair<int,int>> adj[]){
    vector<int> dist(n+1,LLONG_MAX);
    multiset<pair<int,int>> ms;
    ms.insert({0,1});
    dist[1] = 0;
    while(!ms.empty()){
        pair<int,int> pr = *(ms.begin());
        ms.erase(ms.begin());
        for(auto neigh : adj[pr.second]){
            if(dist[neigh.first] == LLONG_MAX){
                dist[neigh.first] = pr.first + neigh.second;
                ms.insert({dist[neigh.first],neigh.first});
            }
            else{
                if(pr.first + neigh.second < dist[neigh.first]){
                    ms.erase(ms.find({dist[neigh.first],neigh.first}));
                    ms.insert({pr.first+neigh.second,neigh.first});
                    dist[neigh.first] = pr.first + neigh.second;
                }
            }
        }
    }
    for(int i=1; i<=n ; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dijkstra(n,adj);
}
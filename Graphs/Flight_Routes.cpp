#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<int> k_dijkstra(int n,const vector<pair<int,int>> adj[], int k){
    vector<multiset<int>> dist(n+1);
    dist[1].insert(0);
    multiset<pair<int,int>> ms;
    ms.insert({0,1});
    while(!ms.empty()){
        pair<int,int> pr = *(ms.begin());
        ms.erase(ms.begin());
        int d = pr.first;
        int node = pr.second;
        if(d > *(prev(dist[node].end()))){
            continue;
        }
        else{
            for(auto neigh : adj[node]){
                int child = neigh.first;
                int w = neigh.second;
                if(dist[child].size() < k){
                    dist[child].insert(d+w);
                    ms.insert({d+w,child});
                }
                else{
                    if(d+w < *(prev(dist[child].end()))){
                        dist[child].erase(prev(dist[child].end()));
                        dist[child].insert(d+w);
                        ms.insert({d+w,child});
                    }
                }
            }
        }
    }
    return dist[n];
}
int32_t main(){
    int n,m,k; cin >> n >> m >> k;
    vector<pair<int,int>> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int a,b,c ; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    multiset<int> ms = k_dijkstra(n,adj,k);
    for(auto node : ms){
        cout << node << " ";
    }
    cout << endl;
}
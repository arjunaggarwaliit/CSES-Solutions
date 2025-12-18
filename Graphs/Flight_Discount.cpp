#include <bits/stdc++.h>
using namespace std;
#define int long long
int modified_dijkstra(int n, const vector<pair<int,int>> adj[]){
    vector<pair<int,int>> dist (n+1,{LLONG_MAX,LLONG_MAX});
    dist[1] = {0,0};
    set<pair<pair<int,int>,int>> s;
    s.insert({{0,1},0});
    while(!s.empty()){
        pair<pair<int,int>,int> pr = *(s.begin());
        s.erase(s.begin());
        int node = pr.first.second;
        int d = pr.first.first;
        if(pr.second == 0){
            if(dist[node].first != d){
                continue;
            }
        }
        else{
            if(dist[node].second != d){
                continue;
            }
        }
        for(auto neigh: adj[node]){
            int child = neigh.first;
            int w = neigh.second;
            if(pr.second == 0){
                if(dist[child].first > d + w){
                    dist[child].first = d+w;
                    s.insert({{dist[child].first,child},0});
                }
                if(dist[child].second > d + w/2){
                    dist[child].second = d + w/2;
                    s.insert({{dist[child].second,child},1});
                }
            }
            else{
                if(dist[child].second > d + w){
                    dist[child].second = d+w;
                    s.insert({{dist[child].second,child},1});
                }
            }
        }
    }
    return dist[n].second;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    cout << modified_dijkstra(n,adj) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
void king_dijkstra(int n,const vector<pair<int,int>> adj[]){
    vector<int> dist(n+1,LLONG_MAX);
    vector<int> dp_count(n+1,0);
    vector<int> dp_min(n+1,0);
    vector<int> dp_max(n+1,0);
    dist[1] = 0;
    dp_count[1] = 1;
    set<pair<int,int>> s;
    s.insert({0,1});
    while(!s.empty()){
        pair<int,int> pr = *(s.begin());
        s.erase(s.begin());
        int d = pr.first;
        int u = pr.second;
        if(d != dist[u]) continue;
        for(auto neigh : adj[u]){
            int v = neigh.first;
            int w = neigh.second;
            if(dist[v] > d + w){
                dist[v] = d+w;
                dp_count[v] = dp_count[u];
                dp_min[v] = dp_min[u] + 1;
                dp_max[v] = dp_max[u] + 1;
                s.insert({d+w, v});
            }
            else if(dist[v] == d+w){
                dp_count[v] += dp_count[u];
                dp_count[v]%=MOD;
                dp_min[v] = min(dp_min[v], dp_min[u]+1);
                dp_max[v] = max(dp_max[v], dp_max[u]+1);
            }
            else{
                continue;
            }
        }
    }
    cout << dist[n] << " " << dp_count[n] << " " << dp_min[n] << " " << dp_max[n] << endl;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0 ; i<m ; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    king_dijkstra(n,adj);
}
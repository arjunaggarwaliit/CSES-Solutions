#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int dp[1 << 20][20];
// dp[mask][v] denote the numbers of ways to reach v covering all cities in mask exactly once
vector<int> in_adj[20];

int32_t main(){
    int n,m; cin >> n >> m;
    for(int i=0 ;i<m ; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        in_adj[v].push_back(u);
    }

    dp[1][0] = 1;
    for(int mask = 2 ; mask < (1<<n); mask++){
        if(mask&1 == 0) continue;
        if((mask&(1<<(n-1))) && (mask != ((1<<n)-1))) continue;
        for(int city = 0 ; city < n ; city++){
            if(mask & (1 << city)){
                int prev_mask = mask - (1 << city);
                for(int from_node : in_adj[city]){
                    if(mask & (1 << from_node)){
                        dp[mask][city] += dp[prev_mask][from_node];
                        dp[mask][city] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << '\n';
}
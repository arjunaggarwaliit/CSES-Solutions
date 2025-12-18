#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<vector<int>> dp(31,vector<int>(n+1,-1));
    for(int i=1 ; i<=n ; i++){
        int t; cin >> t;
        dp[0][i] = t;
    }
    for(int i=1 ; i<= 30 ; i++){
        for(int j=1 ; j<=n ; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    while(q--){
        int x,k; cin >> x >> k;
        int node = x;
        for(int i=30; i>=0; i--){
            if(k&(1LL<<i)){
                node = dp[i][node];
            }
        }
        cout << node << endl;
    }
}
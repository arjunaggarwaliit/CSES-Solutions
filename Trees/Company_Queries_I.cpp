#include <bits/stdc++.h>
using namespace std;
#define int long long
void binarylift(int n,vector<vector<int>>& dp, vector<int>& par, vector<int>& depth){
    for(int i=1;i<=n;i++){
        dp[i][0] = par[i];
    }
    int k = log2(n);
    for(int j=1 ; j<=k; j++){
        for(int i=1;i<=n;i++){
            if(depth[i] >= (1<<j)){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
}
int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> par(n+1);
    vector<int> depth(n+1,-1);
    depth[1] = 0;
    par[1] = -1;
    for(int i=2;i<=n;i++){
        int emp; cin >> emp;
        par[i] = emp;
        depth[i] = depth[par[i]] + 1;
    }
    int base = (int)log2(n) + 1;
    vector<vector<int>> dp(n+1, vector<int>(base,-1));
    binarylift(n,dp,par,depth);
    while(q--){
        int x,k; cin >> x >> k;
        if(k > depth[x]){
            cout << -1 << endl;
        }
        else{
            int ans = x;
            for(int i=0; i<base;i++){
                if(k&(1<<i)){
                    ans = dp[ans][i];
                }
            }
            cout << ans << endl;
        }
    }
}
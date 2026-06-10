#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int32_t main(){
    vector<pair<int, int>> dp(1000001, {1,1});
    for(int i=2; i<= 1000001; i++){
        dp[i].first = (4*dp[i-1].first + dp[i-1].second)%MOD;
        dp[i].second = (2*dp[i-1].second + dp[i-1].first)%MOD;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (dp[n].first + dp[n].second)%MOD << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
void generate_masks(int curr_mask, int next_mask,int i,int n, vector<int>& masks){
    if(i==n){
        masks.push_back(next_mask);
        return;
    }
    if((curr_mask & (1<<i)) != 0){
        generate_masks(curr_mask,next_mask,i+1,n,masks);
    }
    else{
        generate_masks(curr_mask,next_mask ^ (1 << i),i+1,n,masks);
        if((i < n-1) && (curr_mask&(1<<(i+1))) == 0){
            generate_masks(curr_mask,next_mask,i+2,n,masks);
        }
    }
}
int dp_recur(int i, int mask, int n, int m, vector<vector<int>>& dp){
    if(dp[i][mask] != -1) return dp[i][mask];
    vector<int> next_masks; generate_masks(mask,0,0,n,next_masks);
    int tot = 0;
    for(auto next_mask : next_masks){
        tot += dp_recur(i+1,next_mask,n,m,dp);
        tot %= MOD;
    }
    return dp[i][mask] = tot;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> dp(m+1, vector<int>(1<<n,-1));
    for(int i=0 ; i < (1<<n); i++){
        if(i==0) dp[m][i] = 1;
        else dp[m][i] = 0;
    }
    cout << dp_recur(0,0,n,m,dp) << endl;
}
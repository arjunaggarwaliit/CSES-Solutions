#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int32_t main(){
    int n; cin >> n;
    vector<int> dp = {1,1,2,4,8,16};
    if(n<=5){
        cout << dp[n] << endl;
    }
    else{
        for(int i=6;i<=n;i++){
            int val = 0;
            for(int j=0;j<6;j++){
                val += (dp[j]);
                val%= MOD;
            }
            for(int k=0;k<5;k++){
                dp[k] = dp[k+1];
            }
            dp[5] = val;
        }
        cout << dp[5] << endl;
    }
}
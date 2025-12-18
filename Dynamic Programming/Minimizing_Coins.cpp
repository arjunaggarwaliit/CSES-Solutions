#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x; cin >> n >> x;
    vector<int> c(n);
    vector<int> dp(x+1,-1);
    for(int i=0;i<n;i++){
        cin >> c[i];
        if(c[i]<=x){
            dp[c[i]] =1;
        }
    }
    dp[0] =0;
    for(int i=1;i<=x;i++){
        if(dp[i]==-1){
            int minn = LLONG_MAX;
            for(int j=0;j<n;j++){
                if(i-c[j]<0){
                    continue;
                }
                else{
                    minn = min(minn,dp[i-c[j]]);
                }
            }
            if(minn == LLONG_MAX){
                dp[i] = minn;
            }
            else{
                dp[i] = minn+1;
            }
        }
    }
    if(dp[x] == LLONG_MAX){
        cout << -1 << endl;
    }
    else{
        cout << dp[x] << endl;
    }
}
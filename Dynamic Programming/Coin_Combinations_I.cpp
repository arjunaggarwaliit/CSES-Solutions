#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x; cin >> n >> x;
    vector<int> c(n);
    vector<int> dp(x+1,-1);
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        int ways =0;
        bool flag = false;
        for(int j=0;j<n;j++){
            if(i-c[j]<0){
                continue;
            }
            else{
                if(dp[i-c[j]]==-1) continue;
                else {
                    flag = true;
                    ways += (dp[i-c[j]]);
                    ways%=MOD;
                }
            }
        }
        if(ways ==0 && !flag){
            dp[i] = -1;
        }
        else{
            dp[i] = ways;
        }
    }
    if(dp[x]== -1){
        cout << 0 << endl;
    }
    else{
        cout << dp[x] << endl;
    }
}
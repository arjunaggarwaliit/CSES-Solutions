#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] =0;
    for(int i=1;i<=9;i++){
        if(i<=n){
            dp[i]= 1;
        }
    }
    for(int i=10;i<=n;i++){
        int temp = i;
        int minn = INT_MAX;
        while(temp>0){
            int dig = temp%10;
            if(dig!=0) minn = min(minn,1+dp[i-dig]);
            temp/=10;
        }
        dp[i] = minn;
    }
    cout << dp[n] << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int a,b; cin >> a >> b;
    vector<vector<int>> dp (a+1,vector<int>(b+1));
    dp[1][1] = 0;
    for(int i=2;i<=a;i++){
        dp[i][1] = i-1;
    }
    for(int j=2;j<=b;j++){
        dp[1][j] = j-1;
    }
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            for(int k=1;k<i;k++){
                min1 = min(min1,dp[k][j]+dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                min2 = min(min2,dp[i][k]+dp[i][j-k]);
            }
            dp[i][j] = 1 + min(min1,min2);
        }
    }
    // for(int i=1;i<=a;i++){
    //     for(int j=1;j<=b;j++){
    //         cout << dp[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    cout << dp[a][b] << endl;
}
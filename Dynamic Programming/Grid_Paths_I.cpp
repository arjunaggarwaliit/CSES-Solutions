#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int32_t main(){
    int n; cin >> n;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch; cin >> ch;
            if(ch=='.'){
                dp[i][j] =1;
            }
            else dp[i][j] =0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]){
                dp[i][j]=0;
                if(i==0 && j==0) dp[i][j] =1 ;
                if(i!=0) dp[i][j] += (dp[i-1][j]);
                if(j!=0) dp[i][j] += (dp[i][j-1]);
                dp[i][j]%=MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}
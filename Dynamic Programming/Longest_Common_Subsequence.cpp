#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m ; cin >> n >> m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b(m+1,0);
    for(int i=1;i<=m;i++) cin >> b[i];
    vector<vector<int>>dp (n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j] = max(dp[i-1][j-1]+1,dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    vector<int> ans;
    int i=n; int j = m;
    while(1){
        if(i==0 || j==0) break;
        if(dp[i][j]==dp[i-1][j]){
            i--; continue;
        }
        if(dp[i][j]==dp[i][j-1]){
            j--; continue;
        }
        ans.push_back(a[i]);
        i--; j--;
    }
    cout << dp[n][m] << endl;
    for(int iter = ans.size()-1;iter>=0;iter--){
        cout << ans[iter] << " ";
    }
    cout << endl;
}

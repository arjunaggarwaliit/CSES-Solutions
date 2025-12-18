#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int32_t main(){
    int n,m ; cin >> n>> m;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    vector<vector<int>> dp(n,vector<int>(m+2,0));
    vector<int> prev(m+2,0);
    if(x[0]){
        prev[x[0]] = 1;
    }
    else{for(int i=0;i<(m+2);i++){
        if(i==0 || i==m+1){
            continue;
        }
        prev[i] = 1;
    }}
    vector<int> curr(m+2,0);
    for(int i=1;i<n;i++){
        if(x[i] !=0){
            int j = x[i];
            curr[j] = (prev[j] + prev[j-1] + prev[j+1])%MOD;
        }
        else{for(int j=1;j<=m;j++){
            curr[j] = (prev[j] + prev[j-1] + prev[j+1])%MOD;
        }
    }
            prev = curr;
        fill(curr.begin(),curr.end(),0);
    }
    int ans = 0;
    for(int j=1;j<=m;j++) ans = (ans + prev[j]) % MOD;
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vector<int> x(n+1);
    for(int i=1; i<=n; i++) cin >> x[i];
    vector<int> dp(n+1);
    map<int,int> mp;
    set<int> s;
    int st = n+1;
    for(int i=1; i<=n; i++){
        s.insert(x[i]);
        if(s.size() > k){
            st = i; break;
        }
        mp[x[i]] = i;
        dp[i] = 1;
    }
    for(int i =st; i<=n; i++){
        if(mp[x[i]] >= dp[i-1]){
            mp[x[i]] = i;
            dp[i] = dp[i-1];
        }
        else{
            int temp = dp[i-1];
            while(1){
                if(mp[x[temp]] == temp){
                    dp[i] = temp+1; break;
                }
                else{
                    temp++;
                }
            }
            mp[x[i]] = i;
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += (i - dp[i] + 1);
    }
    cout << ans << endl;
}
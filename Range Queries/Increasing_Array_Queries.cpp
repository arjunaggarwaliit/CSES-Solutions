#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX

int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> x(n);
    for(int i=0 ;i<n ; i++) cin >> x[i];
    vector<int> ng(n);
    stack<pair<int,int>> st;
    for(int i= n-1 ; i>=0 ; i--){
        while(!st.empty() && st.top().first<x[i]){
            st.pop();
        }
        if(st.empty()) ng[i] = inf;
        else{
            ng[i] = st.top().second;
        }
        st.push({x[i],i});
    }
    // Prefix Sum (Static Sum Queries)
    vector<int> pre = x;
    for(int i=1 ; i<n ; i++) pre[i] += pre[i-1];
    int LOG = 32 - __builtin_clz(n);
    // Weighted Binary Jumping (Static Max Range Addition Queries)
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(LOG));
    for(int i=0 ; i<n ; i++){
        if(ng[i] != inf){
            dp[i][0] = {ng[i],x[i]*(ng[i]-i)};
        }
        else{
            dp[i][0] = {ng[i],x[i]*(n-i)};
        }
    }
    for(int i=1 ; i<LOG ; i++){
        for(int j=0 ; j<n ; j++){
            if(dp[j][i-1].first == inf){
                dp[j][i] = {inf,dp[j][i-1].second};
            }
            else{
                dp[j][i] = {dp[dp[j][i-1].first][i-1].first,dp[j][i-1].second+dp[dp[j][i-1].first][i-1].second};
            }
        }
    }

    // Query Processing
    while(q--){
        int a,b; cin >> a >> b;
        int ans = 0;
        a--; b--;
        int idx = a;
        for(int i=LOG-1 ; i>=0 ; i--){
            if(dp[idx][i].first <= b){
                ans += dp[idx][i].second;
                idx = dp[idx][i].first;
            }
        }
        ans += x[idx]*(b-idx+1);
        ans -= pre[b];
        if(a!=0) ans += pre[a-1];
        cout << ans << endl;
    }
}
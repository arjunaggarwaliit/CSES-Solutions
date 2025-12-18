#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    multiset<pair<pair<int,int>,int>> ms;
    for(int i=0;i<n;i++){
        int a,b,p; cin >> a >> b >> p;
        ms.insert({{b,a},p});
    }
    vector<int> price;
    vector<int> start;
    vector<int> finish;
    vector<int> prev(n);
    for(auto ele : ms){
        price.push_back(ele.second);
        start.push_back(ele.first.second);
        finish.push_back(ele.first.first);
    }
    for(int i=0;i<n;i++){
        auto it = lower_bound(finish.begin(),finish.end(),start[i]);
        if(it == finish.begin()){
            prev[i] = -1;
        }
        else{
            it--;
            prev[i] = it - finish.begin();
        }
    }
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i] = price[i];
            continue;
        }
        if(prev[i] == -1){
            dp[i] = max(price[i],dp[i-1]);
        }
        else{
            dp[i] = max(dp[prev[i]]+price[i],dp[i-1]);
        }
    }
    cout << dp[n-1] << endl;
}

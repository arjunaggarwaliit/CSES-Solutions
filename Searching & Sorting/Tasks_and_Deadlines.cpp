#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;
    vector<pair<int,int>> vec;
    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    int curr = 0;
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        curr += vec[i].first;
        ans += (vec[i].second - curr);
    }
    cout << ans << endl;
}
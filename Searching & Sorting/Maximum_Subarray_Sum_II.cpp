#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,a,b; cin >> n >> a >> b;
    vector<int> x(n+1);
    x[0] = 0;
    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=1; i<=n; i++) x[i] += x[i-1];
    multiset<int> ms;
    int ans = LLONG_MIN;
    for(int i=1; i<=n; i++){
        if(i-a >= 0) ms.insert(x[i-a]);
        if(i-b-1 >=0) ms.erase(ms.find(x[i-b-1]));
        if(ms.empty()) continue;
        ans = max(ans, x[i] - *(ms.begin()));
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=1; i<n; i++) a[i] += a[i-1];
    vector<int> cnt(n, 0);
    cnt[0] = 1;
    int ans = 0;
    for(int i=0; i<n; i++){
        int rem = (a[i]%n + n)%n;
        ans += cnt[rem];
        cnt[rem] += 1;
    }
    cout << ans << endl;
}
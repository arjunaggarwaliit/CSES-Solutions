#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; 
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
 
    vector<int> lis;
 
    for (int val : x) {
        auto it = lower_bound(lis.begin(), lis.end(), val); 
        if (it == lis.end()) {
            lis.push_back(val); 
        } else {
            *it = val; 
        }
    }
 
    cout << (int)lis.size() << "\n";
}
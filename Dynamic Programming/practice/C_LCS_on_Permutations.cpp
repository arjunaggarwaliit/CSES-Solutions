#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[b[i]] = i+1;
    }
    for(int i=0;i<n;i++){
        a[i] = mp[a[i]];
    }
    vector<int> lis;
    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(),lis.end(),a[i]);
        if(it == lis.end()){
            lis.push_back(a[i]);
        }
        else{
            *it = a[i];
        }
    }
    cout << lis.size() << endl;
}
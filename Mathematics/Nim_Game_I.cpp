#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> x(n);
        for(int i=0;i<n;i++) cin >> x[i];
        int xorr = 0;
        for(auto ele: x) xorr ^= ele;
        if(xorr == 0){
            cout << "second" << endl;
        }
        else{
            cout << "first" << endl;
        }
    }
}
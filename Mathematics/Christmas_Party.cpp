#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int32_t main(){
    int n; cin >> n;
    vector<int> dn(1000001);
    dn[1] = 0; dn[2] = 1;
    for(int i=3;i<=1000000;i++){
        dn[i] = ((i-1) * (dn[i-1]+dn[i-2]));
        dn[i]%=MOD;
    }
    cout << dn[n] << endl;
}
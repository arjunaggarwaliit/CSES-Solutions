#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
int modPow(int a,int b,int mod){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
int32_t main(){
    int n; cin >> n;
    while(n--){
        int a,b,c; cin >> a >> b >> c;
        cout << modPow(a,modPow(b,c,M-1),M) << endl;
    }
}
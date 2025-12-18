#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
// int pow(int a,int b,int mod){
//     int ans = 1;
//     while(b>0){
//         if(b&1){
//             ans*=a;
//             ans%=mod;
//         }
//         a = (a*a)%mod;
//         b>>=1;
//     }
//     return ans;
// }
// int inv(int a,int mod){
//     return pow(a,mod-2,mod);
// }
int32_t main(){
    int n; cin >> n;
    int sm = n*(n+1);
    sm/=2;
    if(sm&1){
        cout << 0 << endl;
    }
    else{
        int target = sm/2;
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                curr[j] = prev[j];
            }
            for(int j=i; j<=target; j++){
                curr[j] = (prev[j] + prev[j-i])%MOD;
            }
            prev = curr;
        }
        cout << (prev[target] * ((MOD + 1) / 2)) % MOD << endl;
    }
}
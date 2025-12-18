#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
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
int modInverse(int a,int mod){
    // for prime mod
    // fermat theorem
    return modPow(a,mod-2,mod);
}
vector<int> facts(1000001);
vector<int> inverses(1000001);
void precompute(){
    int n = 1000000;
    facts[0] = 1;
    inverses[0] = 1;
    for(int i=1;i<=n;i++){
        facts[i] = facts[i-1] * i;
        facts[i] %= MOD;
        inverses[i] = inverses[i-1] * modInverse(i,MOD);
        inverses[i] %= MOD;
    }
}
int ncr(int a,int b, int mod){
    int ans = facts[a] * inverses[b];
    ans %= mod;
    ans *= inverses[a-b];
    ans %= mod;
    return ans;
}
int32_t main(){
    int n; cin >> n;
    precompute();
    while(n--){
        int a,b; cin >> a>> b;
        cout << ncr(a,b,MOD) << endl;
    }
}
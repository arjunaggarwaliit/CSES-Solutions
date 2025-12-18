#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int MOD1 = 1000000006;
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
int modInverse(int a,int MOD){
    return modPow(a,MOD-2,MOD);
}
int32_t main(){
    int n; cin >> n;
    int number = 1;
    int sum = 1;
    int product = 1;
    bool flag = true;
    int exponent = 1;
    int sqrtn = 1;
    while(n--){
        int x,k; cin >> x >> k;
        if(k&1 && flag){
            exponent *= ((k+1)/2);
            exponent %= MOD1;
            flag = false;
        }
        else{
            exponent *= (k+1);
            exponent %= MOD1;
        }
        sqrtn *= modPow(x,k/2,MOD);
        sqrtn%=MOD;
        number *= (k+1);
        number %= MOD;
        sum *= ((modPow(x,k+1,MOD) -1 + MOD)%MOD);
        sum%=MOD;
        sum *= (modInverse(x-1,MOD));
        sum%=MOD;
        product *= modPow(x,k,MOD);
        product%=MOD;
    }
    int pro;
    if(flag){
        pro = modPow(sqrtn,exponent,MOD);
    }
    else{
        pro = modPow(product,exponent,MOD);
    }
    cout << number << " " << sum << " " << pro << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct stringhash{
    vector<int> h = vector<int>(2000);
    vector<int> pow_inv = vector<int>(2000);
    int p, mod;
    string t;
    int binpow(int a, int b){
        int res = 1;
        while(b>0){
            if(b&1){
                res = res*a;
                res%=mod;
            }
            a *= a;
            a%=mod;
            b>>=1;
        }
        return res;
    }
    int inv(int p){
        return binpow(p,mod-2);
    }
    void init(int _p, int _mod, string const& _t){
        p = _p;
        mod = _mod;
        t = _t;
        vector<int> pow(t.size());
        pow[0] = 1;
        pow_inv[0] = 1;
        int p_inv = inv(p);
        for(int i=1 ; i< pow.size(); i++){
            pow[i] = pow[i-1] * p;
            pow[i] %= mod;
            pow_inv[i] = pow_inv[i-1] * p_inv;
            pow_inv[i] %= mod;
        }
        h[0] = (t[0]-'a'+1);
        for(int i=1 ; i< t.size() ; i++){
            h[i] = h[i-1] + ((t[i]-'a'+1) * pow[i]);
            h[i] %= mod;
        }
    }
    int query(int i, int j){
        if(i==0){
            return h[j];
        }
        else{
            int ans = (h[j]+mod-h[i-1])%mod;
            ans *= pow_inv[i];
            ans %= mod;
            return ans;
        }
    }
};
int32_t main(){
    string s;
    stringhash s1;
    s1.init(31,1e9+7,s);
    stringhash s2;
    s2.init(37,1e9+9,s);
}
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
int32_t main(){
    int n; cin >> n;
    vector<int> st;
    for(int i=1;i*i<=n;i++){
        st.push_back(i);
    }
    int tot = 0;
    for(int i=0;i<st.size();i++){
        tot += (st[i]*(n/(st[i])));
        tot%=MOD;
        int l,r;
        if(i == st.size()-1){
            l = st[i] + 1;
            r = n/st[i];
        }
        else{
            l = (n/st[i+1]) + 1;
            r = (n/st[i]);
        }
        int diff = (r-l+1)%MOD;
        int add = (l+r)%MOD;
        int twoinverse = modPow(2,MOD-2,MOD);
        int pro = diff*add;
        pro%=MOD;
        pro*=(twoinverse);
        pro%=MOD;
        pro*=(st[i]);
        pro%=MOD;
        tot += pro;
        tot%=MOD;
    }
    cout << tot << endl;
}
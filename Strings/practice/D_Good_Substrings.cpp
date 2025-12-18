#include <bits/stdc++.h>
using namespace std;
#define int long long
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n,0);
    }

    int comb (int a, int b){
        return a + b;
    }

    void build(vector<int> &v){build(0,n-1,0,v);}
    void build(int start, int ending, int node, vector<int> &v){
        if(start==ending){
            st[node]  = v[start] ; return;
        }
        int mid = start + (ending - start)/2;
        build(start, mid, 2*node + 1, v);
        build(mid + 1, ending, 2*node +2, v);

        st[node] = comb(st[2*node +1],st[2*node +2]);
    }

    int query(int l, int r){return query(0,n-1,l,r,0);}
    int query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return 0;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid = start + (ending-start)/2;

        int q1 = query(start,mid,l,r,2*node +1);
        int q2 = query(mid+1, ending, l, r , 2*node +2);

        return comb(q1,q2);
    }
};
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
    string s; cin >> s;
    int len = s.length();
    string bad;
    cin >> bad;
    int k; cin >> k;
    segmenttree tree;
    tree.init(len);
    vector<int> vec;
    for(int i=0 ; i<len ; i++){
        char c = s[i];
        if(bad[c-'a'] == '0'){
            vec.push_back(1);
        }
        else{
            vec.push_back(0);
        }
    }
    tree.build(vec);
    stringhash s1;
    s1.init(31,1e9+7,s);
    stringhash s2;
    s2.init(37,1e9+9,s);
    vector<pair<int,int>> num;
    for(int i=0; i<len; i++){
        for(int j=i ; j<len ; j++){
            if(tree.query(i,j) <= k){
                num.push_back({s1.query(i,j),s2.query(i,j)});
            }
        }
    }
    sort(num.begin(),num.end());
    cout << unique(num.begin(), num.end()) - num.begin() << endl;
}
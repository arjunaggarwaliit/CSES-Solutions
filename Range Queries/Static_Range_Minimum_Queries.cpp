#include <bits/stdc++.h>
using namespace std;
#define int long long

struct sparsetable{
    int n, LOG;
    vector<vector<int>> st;
    vector<int> log;
    void init(int _n){
        this -> n = _n;
        this -> LOG = 32-__builtin_clz(n);
        st.assign(n,vector<int>(LOG));
        log.assign(n+1,0);
        for(int i=2 ; i<=n; i++) log[i] = log[i/2] + 1;
    }
    int comb(int a,int b){
        return min(a,b);
    }
    void build(const vector<int> &arr){
        for(int i=0 ; i<n ; i++){
            st[i][0] =  arr[i];
        }
        for(int j=1; j<LOG; j++){
            for(int i=0 ; i + (1<<j) <= n; i++){
                st[i][j] = comb(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l, int r){
        return comb(st[l][log[r-l+1]],st[r-(1<<(log[r-l+1]))+1][log[r-l+1]]);
    }
};

int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> x(n);
    for(int i=0 ; i<n ; i++) cin >> x[i];
    sparsetable table;
    table.init(n);
    table.build(x);
    while(q--){
        int a,b; cin >> a >> b;
        cout << table.query(a-1,b-1) << endl;
    }
}
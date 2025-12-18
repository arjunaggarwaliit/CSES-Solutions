#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segmenttree {
    int n;
    vector<pair<int,int>> st;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n,{0,0});
    }

    pair<int,int> comb (pair<int,int> a, pair<int,int> b){
        return {a.first+b.first, max(a.second,a.first+b.second)};
    }

    void build(vector<int> &v){build(0,n-1,0,v);}
    void build(int start, int ending, int node, vector<int> &v){
        if(start==ending){
            st[node].first = v[start] ;
            st[node].second = max(0LL, v[start]);
            return;
        }
        int mid = start + (ending - start)/2;
        build(start, mid, 2*node + 1, v);
        build(mid + 1, ending, 2*node +2, v);

        st[node] = comb(st[2*node +1],st[2*node +2]);
    }

    int query(int l, int r){return query(0,n-1,l,r,0).second ;}
    pair<int,int> query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return {0,0};
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid = start + (ending-start)/2;

        pair<int,int> q1 = query(start,mid,l,r,2*node +1);
        pair<int,int> q2 = query(mid+1, ending, l, r , 2*node +2);

        return {q1.first+q2.first, max(q1.second, q1.first+q2.second)};
    }

    void update(int index,int value){ update(0,n-1,0,index,value);}
    void update(int start, int ending, int node, int index, int value){
        if(start==ending){
            st[node].first = value;
            st[node].second = max(0LL,value);
            return;
        }
        int mid = start + (ending-start)/2;
        if(index<=mid){
            update(start, mid, 2*node + 1, index, value);
        }
        else{
            update(mid+1,ending, 2*node +2, index, value);
        }
        st[node] = comb(st[2*node +1],st[2*node +2]);
        return;
    }

};


int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> x(n);
    for(int i=0 ; i<n ; i++) cin >> x[i];
    segmenttree tree;
    tree.init(n);
    tree.build(x);
    while(q--){
        int idx; cin >> idx;
        if(idx == 1){
            int k,u ; cin >> k >> u;
            tree.update(k-1,u);
        }
        else{
            int a,b; cin >> a >> b;
            a--; b--;
            cout << tree.query(a,b) << endl;
        }
    }
}
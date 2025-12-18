#include <bits/stdc++.h>
using namespace std;
#define int long long

struct treenode{
    int sum;
    int maxx;
    int pre;
    int suf;
};

struct segmenttree {
    int n;
    vector<treenode> st;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n);
    }

    treenode comb(const treenode &a, const treenode &b){
        return {a.sum+b.sum,max(a.maxx,max(b.maxx,a.suf+b.pre)),max(a.pre,a.sum+b.pre),
        max(b.suf,b.sum+a.suf)};
    }

    void build(vector<int> &v){build(0,n-1,0,v);}
    void build(int start, int ending, int node, vector<int> &v){
        if(start==ending){
            st[node]  = {v[start],v[start],v[start],v[start]} ; return;
        }
        int mid = start + (ending - start)/2;
        build(start, mid, 2*node + 1, v);
        build(mid + 1, ending, 2*node +2, v);

        st[node] = comb(st[2*node +1],st[2*node +2]);
    }

    int query(int l, int r){return query(0,n-1,l,r,0).maxx;}
    treenode query(int start, int ending, int l, int r, int node){
        if(start>r || ending<l){
            return {0,LLONG_MIN,0,0};
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid = start + (ending-start)/2;

        treenode q1 = query(start,mid,l,r,2*node +1);
        treenode q2 = query(mid+1, ending, l, r , 2*node +2);

        return comb(q1,q2);
    }
};

int32_t main(){
    int n,m; cin >> n >> m;
    vector<int> x(n);
    for(int i=0; i<n ; i++) cin >> x[i];
    segmenttree tree;
    tree.init(n);
    tree.build(x);
    for(int i=0 ; i<m ; i++){
        int l,r ; cin >> l >> r;
        l--; r--;
        cout << max(0LL,tree.query(l,r)) << endl;
    }
}
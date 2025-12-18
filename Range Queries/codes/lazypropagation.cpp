#include <bits/stdc++.h>
using namespace std;
// Lazy Propagation
struct segmenttree {
    int n;
    vector<int> st;
    vector<int> lazy;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n,0);
        lazy.resize(4*n,0);
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

    int query(int l, int r){return query(0,n-1,0,l,r);}
    int query(int start, int ending, int node, int l, int r){
        if(lazy[node]!=0){
            st[node] += (ending-start+1)*lazy[node];
            if(start!=ending){
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start>r || ending<l){
            return 0;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int mid = start + (ending-start)/2;

        int q1 = query(start,mid,2*node +1,l,r);
        int q2 = query(mid+1, ending,2*node +2,l,r);

        return comb(q1,q2);
    }

    void update(int l,int r,int value){ update(0,n-1,0,l,r,value);}
    void update(int start, int ending, int node, int l, int r, int value){
        if(lazy[node]!=0){
            st[node] += (ending-start+1)*lazy[node];
            if(start!=ending){
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start>r || ending<l) return;
        if(start>=l && ending<=r){
            st[node] += (ending-start+1)*value;
            if(start!=ending){
                lazy[2*node + 1] += value;
                lazy[2*node + 2] += value;
            }
            return;
        }
        int mid = start + (ending-start)/2;
        update(start,mid,2*node + 1,l,r,value);
        update(mid+1,ending,2*node + 2,l,r,value);
        st[node] = comb(st[2*node + 1],st[2*node + 2]);
    }

};
#include <bits/stdc++.h>
using namespace std;
// Segment Tree
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

    void update(int x,int y){ update(0,n-1,0,x,y);}
    void update(int start, int ending, int node, int index, int value){
        if(start==ending){
            st[node]=value;
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

// Indexed Set Libraries
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n = 10; vector<int> arr;
    arr = {1,2,3,4,5,6,7,8,9,10};
    segmenttree tree;
    tree.init(n);
    tree.build(arr);
    cout << tree.query(0,5) << endl;
}

// Iterative Segment Tree
struct segmenttree_iter {
    int n;
    vector<int> st;

    void init(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        st.assign(2*n, INT_MIN);
    }

    void build(vector<int> &v) {
        for (int i = 0; i < (int)v.size(); i++)
            st[n + i] = v[i];
        for (int i = n - 1; i > 0; i--)
            st[i] = max(st[2*i], st[2*i + 1]);
    }

    void update(int idx, int val) {
        idx += n;
        st[idx] = val;
        for (idx >>= 1; idx; idx >>= 1)
            st[idx] = max(st[2*idx], st[2*idx + 1]);
    }

    int query(int l, int r) {
        int res = INT_MIN;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, st[l++]);
            if (!(r & 1)) res = max(res, st[r--]);
        }
        return res;
    }
};
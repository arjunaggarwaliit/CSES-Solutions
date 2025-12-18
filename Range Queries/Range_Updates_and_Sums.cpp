#include <bits/stdc++.h>
using namespace std;
#define int long long
// Lazy Propagation
struct segmenttree {
    int n;
    vector<int> st;
    vector<int> lazy;
    vector<int> setlazy;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n,0);
        lazy.resize(4*n,0);
        setlazy.resize(4*n,0);
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
        if(setlazy[node]!=0){
            st[node] = (ending-start+1)*setlazy[node];
            if(start!=ending){
                setlazy[2*node + 1] = setlazy[node];
                lazy[2*node + 1] = 0;
                setlazy[2*node + 2] = setlazy[node];
                lazy[2*node + 2] = 0;
            }
            setlazy[node] = 0;
        }
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
        if(setlazy[node]!=0){
            st[node] = (ending-start+1)*setlazy[node];
            if(start!=ending){
                setlazy[2*node + 1] = setlazy[node];
                lazy[2*node + 1] = 0;
                setlazy[2*node + 2] = setlazy[node];
                lazy[2*node + 2] = 0;
            }
            setlazy[node] = 0;
        }
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

    void set_update(int l,int r,int value){ set_update(0,n-1,0,l,r,value);}
    void set_update(int start, int ending, int node, int l, int r, int value){
        if(setlazy[node]!=0){
            st[node] = (ending-start+1)*setlazy[node];
            if(start!=ending){
                setlazy[2*node + 1] = setlazy[node];
                lazy[2*node + 1] = 0;
                setlazy[2*node + 2] = setlazy[node];
                lazy[2*node + 2] = 0;
            }
            setlazy[node] = 0;
        }
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
            st[node] = (ending-start+1)*value;
            if(start!=ending){
                setlazy[2*node + 1] = value;
                lazy[2*node + 1] = 0;
                setlazy[2*node + 2] = value;
                lazy[2*node + 2] = 0;
            }
            return;
        }
        int mid = start + (ending-start)/2;
        set_update(start,mid,2*node + 1,l,r,value);
        set_update(mid+1,ending,2*node + 2,l,r,value);
        st[node] = comb(st[2*node + 1],st[2*node + 2]);
    }
};

int32_t main(){
    int n; int q;
    cin >> n >> q;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    segmenttree tree;
    tree.init(n);
    tree.build(vec);
    while(q--){
        int idx; cin >> idx;
        if(idx == 1){
            int a,b,x; cin >> a >> b >> x;
            tree.update(a-1,b-1,x);
        }
        else if(idx == 2){
            int a,b,x; cin >> a >> b >> x;
            tree.set_update(a-1,b-1,x);
        }
        else if(idx == 3){
            int a,b; cin >> a >> b;
            cout << tree.query(a-1,b-1) << endl;
        }
    }
}
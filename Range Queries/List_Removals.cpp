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

int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    vector<int> ones(n,1);
    segmenttree tree;
    tree.init(n);
    tree.build(ones);
    vector<int> order(n);
    for(int i=0 ; i<n ; i++) cin >> order[i];
    for(int i=0 ; i<n ; i++){
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(l == r){
                cout << a[l] << " ";
                break;
            }
            if(tree.query(l,mid) >= order[i]){
                r = mid;
            }
            else{
                order[i] -= tree.query(l,mid);
                l = mid+1;
            }
        }
        tree.update(l,0);
    }
    cout << endl;
}
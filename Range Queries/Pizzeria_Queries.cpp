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
        return min(a,b);
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
            return LLONG_MAX;
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
    int n,q; cin >> n >> q;
    vector<int> p(n);
    for(int i=0 ; i<n ; i++) cin >> p[i];
    vector<int> plus(n);
    vector<int> diff(n);
    for(int i=0 ; i<n ; i++){
        plus[i] = p[i] + i;
        diff[i] = p[i] - i;
    }
    segmenttree treeplus;
    segmenttree treediff;
    treeplus.init(n);
    treeplus.build(plus);
    treediff.init(n);
    treediff.build(diff);
    while(q--){
        int idx; cin >> idx;
        if(idx == 1){
            int k,x; cin >> k >> x;
            k--;
            treeplus.update(k,x+k);
            treediff.update(k,x-k);
            p[k] = x;
        }
        else{
            int k; cin >> k;
            k--;
            int minn = LLONG_MAX;
            if(k <n-1){
                minn = min(treeplus.query(k+1,n-1)-k,minn);
            }
            if(k > 0){
                minn = min(treediff.query(0,k-1)+k,minn);
            }
            minn= min(minn,p[k]);
            cout << minn << endl;
        }
    }
}
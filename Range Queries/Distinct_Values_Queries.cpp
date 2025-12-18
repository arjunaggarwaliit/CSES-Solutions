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
    int n,q ; cin >> n >> q;
    vector<int> x(n+1);
    x[0] = 0;
    for(int i=1 ; i<=n ; i++) cin >> x[i];
    vector<vector<pair<int,int>>> vec(n+1);
    for(int i=0; i<q; i++){
        int a,b; cin >> a >> b;
        vec[b].push_back({a,i});
    }
    segmenttree tree;
    tree.init(n+1);
    vector<int> ans(q,0);
    map<int,int> prev;
    for(int i=1 ; i<=n ; i++){
        if(prev[x[i]] == 0){
            tree.update(i,1);
            prev[x[i]] = i;
        }
        else{
            tree.update(prev[x[i]],0);
            tree.update(i,1);
            prev[x[i]] = i;
        }
        for(auto pr : vec[i]){
            ans[pr.second] = tree.query(pr.first,i);
        }
    }
    for(auto ele : ans){
        cout << ele << endl;
    }
}
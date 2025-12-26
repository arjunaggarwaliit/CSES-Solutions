#include <bits/stdc++.h>
using namespace std;
#define int long long
struct segmenttree {
    int n;
    vector<int> st;
    vector<pair<int,int>> lazy;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n,0);
        lazy.resize(4*n,{0,0});
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
        int mid = start + (ending - start)/2;
        if(lazy[node].second != 0){
            st[node] += (((ending-start+1)*lazy[node].first) + lazy[node].second*((ending-start)*(ending-start+1))/2);
            if(start!=ending){
                lazy[2*node + 1].first += lazy[node].first;
                lazy[2*node + 1].second += lazy[node].second;
                lazy[2*node + 2].first += (lazy[node].first + lazy[node].second*(mid - start + 1));
                lazy[2*node + 2].second += lazy[node].second;
            }
            lazy[node] = {0,0};
        }
        if(start>r || ending<l){
            return 0;
        }
        if(start>=l && ending<=r){
            return st[node];
        }
        int q1 = query(start,mid,2*node +1,l,r);
        int q2 = query(mid+1, ending,2*node +2,l,r);

        return comb(q1,q2);
    }

    void update(int l,int r){ update(0,n-1,0,l,r);}
    void update(int start, int ending, int node, int l, int r){
        int mid = start + (ending - start)/2;
        if(lazy[node].second != 0){
            st[node] += (((ending-start+1)*lazy[node].first) + lazy[node].second*((ending-start)*(ending-start+1))/2);
            if(start!=ending){
                lazy[2*node + 1].first += lazy[node].first;
                lazy[2*node + 1].second += lazy[node].second;
                lazy[2*node + 2].first += (lazy[node].first + lazy[node].second*(mid - start + 1));
                lazy[2*node + 2].second += lazy[node].second;
            }
            lazy[node] = {0,0};
        }
        if(start>r || ending<l) return;
        if(start>=l && ending<=r){
            lazy[node] = {start-l+1,1};
            st[node] += (((ending-start+1)*lazy[node].first) + lazy[node].second*((ending-start)*(ending-start+1))/2);
            if(start!=ending){
                lazy[2*node + 1].first += lazy[node].first;
                lazy[2*node + 1].second += lazy[node].second;
                lazy[2*node + 2].first += (lazy[node].first + lazy[node].second*(mid - start + 1));
                lazy[2*node + 2].second += lazy[node].second;
            }
            lazy[node] = {0,0};
            return;
        }
        update(start,mid,2*node + 1,l,r);
        update(mid+1,ending,2*node + 2,l,r);
        st[node] = comb(st[2*node + 1],st[2*node + 2]);
    }

};
int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for(int i=0 ;i<n ; i++) cin >> arr[i];
    segmenttree tree;
    tree.init(n);
    tree.build(arr);
    while(q--){
        int idx; cin >> idx;
        if(idx == 1){
            int a,b; cin >> a >> b;
            a--; b--;
            tree.update(a,b);
        }
        else{
            int a,b; cin >> a >> b;
            a--; b--;
            cout << tree.query(a,b) << endl;
        }
    }
}
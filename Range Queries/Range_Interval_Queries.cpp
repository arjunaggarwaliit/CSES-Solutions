#include <bits/stdc++.h>
using namespace std;
#define int long long

struct mergesorttree{
    int n;
    vector<vector<int>> st;

    void init(int _n) {
        this -> n = _n;
        st.resize(4*n);
    }

    vector<int> comb(vector<int> &a, vector<int> &b){
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> ret(a.size()+b.size());
        while(i < a.size() && j < b.size()){
            if(a[i] <= b[j]){
                ret[k] = a[i];
                k++; i++;
            }
            else{
                ret[k] = b[j];
                j++; k++;
            }
        }
        while(i < a.size()){
            ret[k] = a[i];
            i++ ; k++;
        }
        while(j < b.size()){
            ret[k] = b[j];
            j++ ; k++;
        }
        return ret;
    }

    void build(vector<int> &v){build(0,n-1,0,v);}
    void build(int start, int ending, int node, vector<int> &v){
        if(start==ending){
            st[node]  = {v[start]} ; return;
        }
        int mid = start + (ending - start)/2;
        build(start, mid, 2*node + 1, v);
        build(mid + 1, ending, 2*node +2, v);

        st[node] = comb(st[2*node +1],st[2*node +2]);
    }

    int query(int l, int r, int a, int b){return query(0,n-1,l,r,0,a,b);}
    int query(int start, int ending, int l, int r, int node, int a, int b){
        if(start>r || ending<l){
            return 0;
        }
        if(start>=l && ending<=r){
            auto it1 = lower_bound(st[node].begin(),st[node].end(),a);
            auto it2 = upper_bound(st[node].begin(),st[node].end(),b);
            return it2-it1;
        }
        int mid = start + (ending-start)/2;

        int q1 = query(start,mid,l,r,2*node +1,a,b);
        int q2 = query(mid+1, ending, l, r , 2*node +2,a,b);

        return q1+q2;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> x(n);
    for(int i=0 ;i<n ; i++) cin >> x[i];
    mergesorttree tree;
    tree.init(n);
    tree.build(x);
    while(q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        a--; b--;
        cout << tree.query(a,b,c,d) << endl;
    }
}
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
        return max(a,b);
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
            return LLONG_MIN;
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
    int n,m; cin >> n >>m;
    vector<int> h(n);
    for(int i=0 ; i<n ; i++) cin >> h[i];
    segmenttree tree;
    tree.init(n);
    tree.build(h);
    vector<int> rm(m);
    for(int i=0 ; i<m ; i++) cin >> rm[i];
    for(int i=0 ; i<m; i++){
        int maxx = tree.query(0,n-1);
        if(maxx >= rm[i]){
            int l = 0;
            int r = n-1;
            while(l <= r){
                if(l==r){
                    cout << l+1 << " ";
                    tree.update(l,h[l]-rm[i]);
                    h[l] -= rm[i];
                    break;
                }
                else{
                    int mid = l + (r-l)/2;
                    if(tree.query(l,mid) >= rm[i]){
                        r = mid;
                        continue;
                    }
                    else{
                        l = mid+1;
                        continue;
                    }
                }
            }
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;
}
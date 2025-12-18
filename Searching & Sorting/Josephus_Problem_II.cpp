#include <bits/stdc++.h>
using namespace std;
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
            st[node] = v[start] ; return;
        }
        int mid = start + (ending - start)/2;
        build(start, mid, 2*node + 1, v);
        build(mid + 1, ending, 2*node +2, v);
        st[node] = comb(st[2*node +1],st[2*node +2]);
    }
    int sumq(int l, int r){return sumq(0,n-1,l-1,r-1,0);}
    int sumq(int start, int ending, int l, int r, int node){
        if(start>r || ending<l) return 0;
        if(start>=l && ending<=r) return st[node];
        int mid = start + (ending-start)/2;
        int q1 = sumq(start,mid,l,r,2*node +1);
        int q2 = sumq(mid+1, ending, l, r , 2*node +2);
        return comb(q1,q2);
    }
    int query(int k){return query(0,n-1,k,0)+ 1;}
    int query(int start, int ending, int k, int node){
        if(start == ending) return start;
        int mid = start + (ending-start)/2;
        if(k <= st[2*node + 1]) return query(start,mid,k,2*node + 1);
        else return query(mid+1,ending,k-st[2*node + 1],2*node +2);
    }
    void update(int index,int value){ update(0,n-1,0,index-1,value);}
    void update(int start, int ending, int node, int index, int value){
        if(start==ending){
            st[node]=value; return;
        }
        int mid = start + (ending-start)/2;
        if(index<=mid) update(start, mid, 2*node + 1, index, value);
        else update(mid+1,ending, 2*node +2, index, value);
        st[node] = comb(st[2*node +1],st[2*node +2]);
        return;
    }
};
int32_t main(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> circle(n,1);
    segmenttree tree;
    tree.init(n);
    tree.build(circle);
    int step = k+1;
    int leave = k;
    while(1){
        int tot = tree.sumq(1,n);
        if(tot == 0){
            break;
        }
        if(tot <= leave){
            leave%=tot;
        }
        int it = leave + 1;
        vector<int> rem;
        while(it <= tot){
            int idx = tree.query(it);
            cout << idx << " ";
            rem.push_back(idx);
            if(it + step <= tot){
                it+= step;
                continue;
            }
            else{
                for(auto ele: rem){
                    tree.update(ele,0);
                }
                leave = k-(tot - it);
                break;
            }
        }
    }
    cout << endl;
}
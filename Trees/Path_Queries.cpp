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
        if(start>r || ending<l) return 0;
        if(start>=l && ending<=r) return st[node];
        int mid = start + (ending-start)/2;
        int q1 = query(start,mid,l,r,2*node +1);
        int q2 = query(mid+1, ending, l, r , 2*node +2);
        return comb(q1,q2);
    }
    void update(int x,int y){ update(0,n-1,0,x,y);}
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

void dfs(int node, int parent, const vector<int> adj[], vector<int> &value, int& timer,
vector<int>&flatten, vector<int> &entry, vector<int>& finish){
    entry[node] = timer++;
    flatten.push_back(value[node]);
    for(auto child : adj[node]){
        if(child == parent) continue;
        dfs(child,node,adj,value,timer,flatten,entry,finish);
    }
    finish[node] = timer++;
    flatten.push_back(-value[node]);
}

int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> value(n+1);
    for(int i=1; i<=n; i++) cin >> value[i];
    vector<int> adj[n+1];
    for(int i=0 ; i<n-1 ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> flatten;
    int timer = 0;
    vector<int> entry(n+1,-1);
    vector<int> finish(n+1,-1);
    dfs(1,-1,adj,value,timer,flatten,entry,finish);
    segmenttree tree;
    tree.init(2*n);
    tree.build(flatten);
    for(int i=0 ; i<q ; i++){
        int idx ; cin >> idx;
        if(idx == 1){
            int s,x ; cin >> s >> x;
            tree.update(entry[s],x);
            tree.update(finish[s],-x);
        }
        else{
            int s; cin >> s;
            cout << tree.query(0,entry[s]) << endl;
        }
    }
}
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

struct HLD {
    int n;
    vector<vector<int>> adj;
    vector<int> par, depth, sz, heavy;
    vector<int> head, pos;
    vector<int> base;
    int curr;

    segmenttree st;

    HLD(int _n,const vector<vector<int>> &adj_) {
        n = _n;
        adj = adj_;
        par.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        heavy.assign(n + 1, -1);
        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        base.assign(n, 0);
        curr = 0;
    }

    void dfs(int node, int parent) {
        par[node] = parent;
        sz[node] = 1;
        int max_size = 0;

        for (int child : adj[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
            sz[node] += sz[child];
            if (sz[child] > max_size) {
                max_size = sz[child];
                heavy[node] = child;
            }
        }
    }

    void decompose(int node, int h) {
        head[node] = h;
        pos[node] = curr++;

        if (heavy[node] != -1) {
            decompose(heavy[node], h);
        }

        for (int child : adj[node]) {
            if (child != par[node] && child != heavy[node]) {
                decompose(child, child);
            }
        }
    }

    void build(vector<int> &values) {
        dfs(1, 0);
        decompose(1, 1);

        for (int i = 1; i <= n; i++) {
            base[pos[i]] = values[i];
        }

        st.init(n);
        st.build(base);
    }

    int path_query(int u, int v) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) {
                swap(u, v);
            }
            res += st.query(pos[head[u]], pos[u]);
            u = par[head[u]];
        }

        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        res += st.query(pos[u], pos[v]);
        return res;
    }

    void update_node(int u, int val) {
        st.update(pos[u], val);
    }
};

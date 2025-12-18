#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using indexed_set =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


    // TLE with PBDS
// int32_t main(){
//     int n,q; cin >> n >> q;
//     vector<int> p(n);
//     indexed_set<pair<int,int>> s;
//     unordered_map<int,int> mp;
//     for(int i=0 ; i<n ; i++){
//         cin >> p[i];
//         s.insert({p[i],mp[p[i]]+1});
//         mp[p[i]]++;
//     }
//     while(q--){
//         char c; cin >> c;
//         if(c == '!'){
//             int k,x ; cin >> k >> x;
//             k--;
//             auto it = s.lower_bound({p[k],LLONG_MIN});
//             s.erase(it);
//             p[k] = x;
//             s.insert({p[k],mp[p[k]]+1});
//             mp[p[k]]+=1;
//         }
//         else{
//             int a,b ; cin >> a >> b;
//             int lw = s.order_of_key({a,INT_MIN});
//             int uw = s.order_of_key({b,INT_MAX});
//             cout << uw - lw << endl;
//         }
//     }
// }

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
    int n,q; cin >> n >> q;
    vector<int> p(n);
    set<int> salaries;
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
        salaries.insert(p[i]);
    }
    vector<tuple<char,int,int>> offline(q);
    for(int i=0; i<q ; i++){
        char c; int a,b; cin >> c >> a >> b;
        offline[i] = {c,a,b};
        if(c == '!'){
            salaries.insert(b);
        }
    }
    vector<int> vec(salaries.begin(),salaries.end());
    vector<int> cnt(vec.size());
    for(int i=0 ; i<n ; i++){
        cnt[lower_bound(vec.begin(),vec.end(),p[i])-vec.begin()]+=1;
    }
    segmenttree tree;
    tree.init(cnt.size());
    tree.build(cnt);
    for(int i=0 ; i<q ; i++){
        char c= get<0>(offline[i]);
        int a = get<1>(offline[i]);
        int b = get<2>(offline[i]);
        if(c == '!'){
            a--;
            int idx1 = lower_bound(vec.begin(),vec.end(),p[a])-vec.begin();
            cnt[idx1]-=1;
            tree.update(idx1,cnt[idx1]);
            p[a] = b;
            int idx2 = lower_bound(vec.begin(),vec.end(),p[a])-vec.begin();
            cnt[idx2]+=1;
            tree.update(idx2,cnt[idx2]);
        }
        else{
            int idx1 = lower_bound(vec.begin(),vec.end(),a)-vec.begin();
            int idx2 = prev(upper_bound(vec.begin(),vec.end(),b))-vec.begin();
            if(idx1 <= idx2){
                cout << tree.query(idx1,idx2) << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}
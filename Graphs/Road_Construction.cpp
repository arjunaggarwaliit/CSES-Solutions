#include <bits/stdc++.h>
using namespace std;
#define int long long
// Disjoint Set Union
struct DSU {
    vector<int> p, r, size;
    int max_size;
    int components;
    DSU(int n) {
        max_size = 1;
        components = n;
        p.resize(n+1);
        r.resize(n+1, 0);
        size.resize(n+1,1);
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int get(int a) {
        return p[a] = (p[a] == a ? a : get(p[a]));
    }
    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (r[a] == r[b]) {
            r[a]++;
        }
        if (r[a] > r[b]) {
            p[b] = a;
            size[a] += size[b];
            max_size = max(max_size,size[a]);
            components--;
        } else {
            p[a] = b;
            size[b] += size[a];
            max_size = max(max_size,size[b]);
            components--;
        }
    }
    bool same(int a, int b) {
        return get(a) == get(b);
    }
};
int32_t main(){
    int n,m; cin >> n >> m;
    DSU dsu(n);
    for(int i=0 ; i<m ; i++){
        int a,b; cin >> a >> b;
        if(dsu.same(a,b)){
            cout << dsu.components << " " << dsu.max_size << endl;
        }
        else{
            dsu.unite(a,b);
            cout << dsu.components << " " << dsu.max_size << endl;
        }
    }
}

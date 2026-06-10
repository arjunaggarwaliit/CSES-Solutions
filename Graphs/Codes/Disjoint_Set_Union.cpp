#include <bits/stdc++.h>
using namespace std;
#define int long long
// Disjoint Set Union
struct DSU {
    vector<int> p, r;
    DSU(int n) {
        p.resize(n+1);
        r.resize(n+1, 0);
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
        } else {
            p[a] = b;
        }
    }
    bool same(int a, int b) {
        return get(a) == get(b);
    }
};
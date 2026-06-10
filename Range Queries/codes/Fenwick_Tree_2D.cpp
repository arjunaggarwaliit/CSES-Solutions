#include <bits/stdc++.h>
using namespace std;
#define int long long


struct fenwicktree2d{
    int n, m;
    vector<vector<int>> bit;

    fenwicktree2d(int _n, int _m) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }

    int sum(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i){
            for (int j = y; j > 0; j -= j & -j){
                res += bit[i][j];
            }
        }
        return res;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i <= n; i += i & -i){
            for (int j = y; j <= m; j += j & -j){
                bit[i][j] += delta;
            }
        }
    }

    int rangesum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
};
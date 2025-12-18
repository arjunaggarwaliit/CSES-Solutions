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


int32_t main(){
    int n,q; cin >> n >> q;
    // fenwicktree2d tree(n,n);
    vector<vector<int>> grid (n, vector<int> (n,0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            char c; cin >> c;
            if(c == '*'){
                grid[i][j] += 1;
            }
            if(i>0 && j>0){
                grid[i][j] -= grid[i-1][j-1];
            }
            if(i < n-1){
                grid[i+1][j] += grid[i][j];
            }
            if(j < n-1){
                grid[i][j+1] += grid[i][j];
            }
        }
    }
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<n ; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        swap(x1,y1);
        swap(x2,y2);
        // cout << y1 << x1 << y2 <<x2 << endl;
        int ans = grid[x2][y2];
        if(x1>0 && y1>0){
            ans += grid[x1-1][y1-1];
        }
        if(x1> 0){
            ans -= grid[x1-1][y2];
        }
        if(y1 > 0){
            ans -= grid[x2][y1-1];
        }
        cout << ans << endl;
    }
}
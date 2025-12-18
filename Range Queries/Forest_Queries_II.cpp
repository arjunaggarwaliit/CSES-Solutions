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
    fenwicktree2d tree(n,n);
    vector<vector<int>> grid (n+1, vector<int>(n+1,0));
    for(int i=1; i<=n ; i++){
        string s; cin >> s;
        for(int j=0 ; j<n ; j++){
            if(s[j] == '*'){
                grid[i][j+1] = 1;
                tree.add(i,j+1,1);
            }
        }
    }
    while(q--){
        int idx; cin >> idx;
        if(idx == 1){
            int x,y; cin >> x >> y;
            if(grid[x][y] == 1){
                tree.add(x,y,-1);
                grid[x][y] -=1;
            }
            else{
                tree.add(x,y,1);
                grid[x][y] +=1;
            }
        }
        else{
            int y1, x1, y2, x2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.rangesum(x1,y1,x2,y2) << endl;
        }
    }
}
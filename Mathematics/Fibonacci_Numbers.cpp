#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b){
    int m = a.size();
    int p = a[0].size();
    int n = b[0].size();
    vector<vector<int>> c(m, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<p; k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j]%=MOD;
            }
        }
    }

    return c;
}

vector<vector<int>> matrix_expo(vector<vector<int>> &a, int p){
    int n = a.size();

    vector<vector<int>> res = a;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) ans[i][i] = 1;

    while(p > 0){
        if(p&1) ans = multiply(ans, res);
        p>>=1;
        res = multiply(res, res);
    }

    return ans;
}

int32_t main(){
    int n; cin >> n;
    if(n==0){
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<int>> transition = {{1,1}, {1, 0}};
    vector<vector<int>> ans = matrix_expo(transition, n-1);
    cout << ans[0][0] << endl;
}
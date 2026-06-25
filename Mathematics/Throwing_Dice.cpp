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
    vector<int> base_case = {1, 1, 2, 4, 8, 16};
    vector<vector<int>> transition(6, vector<int>(6, 0));
    for(int j=0; j<6; j++) transition[0][j] = 1;
    for(int i=1; i<6; i++){
        transition[i][i-1] = 1;
    }
    if(n <= 5){
        cout << base_case[n] << endl;
    }
    else{
        int ans = 0;
        vector<vector<int>> fin = matrix_expo(transition, n-5);
        for(int i=0; i<6; i++) ans += (fin[0][i] * base_case[5-i]);
        ans%=MOD;
        cout << ans << endl;
    }
}
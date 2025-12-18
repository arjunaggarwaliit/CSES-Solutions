#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX
int32_t main(){
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int>> prev (n+1, vector<int> (n+1,LLONG_MAX));
    vector<vector<int>> next (n+1, vector<int> (n+1,LLONG_MAX));
    for(int i=1 ; i<=n ; i++){
        prev[i][i] = 0;
    }
    for(int i=0 ; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        prev[a][b] = min(prev[a][b],c);
        prev[b][a] = min(prev[b][a],c);
    }
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                next[i][j] = prev[i][j];
                if(prev[i][k]!=inf && prev[k][j]!=inf){
                    next[i][j] = min(next[i][j], prev[i][k] + prev[k][j]);
                }
            }
        }
        prev = next;
    }
    while(q--){
        int a,b; cin >> a >> b;
        if(prev[a][b] == inf){
            cout << -1 << endl;
        }
        else{
            cout << prev[a][b] << endl;
        }
    }
}
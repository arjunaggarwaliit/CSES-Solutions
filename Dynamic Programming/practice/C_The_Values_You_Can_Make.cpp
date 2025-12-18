#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,k; cin >> n >> k;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin >> coins[i];
    vector<vector<bool>> prev (k+1,vector<bool>(k+1,false));
    vector<vector<bool>> curr (k+1,vector<bool>(k+1,false));
    prev[0][0] = true;
    for(int x=1;x<=n;x++){
        for(int y=0;y<=k;y++){
            for(int z=0;z<=k;z++){
                bool flag = false;
                flag |= prev[y][z];
                if(y-coins[x-1]>=0){
                    flag |= prev[y-coins[x-1]][z];
                    if(z-coins[x-1]>=0){
                        flag |= prev[y-coins[x-1]][z-coins[x-1]];
                    }
                }
                curr[y][z] = flag;
            }
        }
        prev = curr;
    }
    int cnt = 0;
    for(int i=0;i<=k;i++){
        if(prev[k][i]) cnt+=1;
    }
    cout << cnt << endl;
    for(int i=0;i<=k;i++){
        if(prev[k][i]){
            cout << i << " ";
        }
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int32_t main(){
    int n,x; cin >> n >> x;
    vector<int> coins(n+1);
    for(int i=1;i<=n;i++) cin >> coins[i];
    vector<int> prev(x+1,0LL);
    vector<int> curr(x+1);
    curr[0] =1;
    for(int i=1;i<=n;i++){
        curr[0] =1;
        for(int j=1;j<=x;j++){
            int tot =0;
            tot += prev[j];
            if(j-coins[i] >=0){
                tot += (curr[j-coins[i]]);
            }
            tot%=MOD;
            curr[j] = tot;
        }
        prev = curr;
    }
    cout << prev[x] << endl;
}
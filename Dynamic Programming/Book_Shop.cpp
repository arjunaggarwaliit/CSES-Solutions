#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x; cin >> n >> x;
    vector<int> price(n+1);
    for(int i=1;i<=n;i++) cin >> price[i];
    vector<int> profit(n+1);
    for(int i=1;i<=n;i++) cin >> profit[i];
    vector<int> prev(x+1,0);
    vector<int> curr(x+1);
    for(int i=1;i<=n;i++){
        curr[0] =0;
        for(int j=1;j<=x;j++){
            int maxx = INT_MIN;
            maxx = max(maxx,prev[j]);
            if(j-price[i]>=0){
                maxx = max(maxx,profit[i]+prev[j-price[i]]);
            }
            curr[j] = maxx;
        }
        prev = curr;
    }
    cout << prev[x] << endl;
}
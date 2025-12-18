#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> cnt(1e6+10,0);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = 1;
    for(int i = 1e6; i>=1; i--){
        int k = 0;
        for(int j= i; j<= 1e6; j+=i){
            k += cnt[j];
            if(k>=2){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
}
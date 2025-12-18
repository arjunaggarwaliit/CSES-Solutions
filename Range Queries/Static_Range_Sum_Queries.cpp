#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,q; cin >> n >> q;
    vector<int> x(n);
    for(int i=0 ;i<n ; i++) cin >> x[i];
    for(int i=0 ;i<n-1; i++) x[i+1] += x[i];
    while(q--){
        int a,b; cin >> a >> b;
        a--; b--;
        if(a==0){
            cout << x[b] << endl;
        }
        else{
            cout << x[b] - x[a-1] << endl;
        }
    }
}
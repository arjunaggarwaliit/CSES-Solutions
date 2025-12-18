#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int fin = LLONG_MIN;
    int curr =0;
    for(int i=0;i<n;i++){
        if(curr < 0) curr =0;
        curr += arr[i];
        fin = max(fin , curr);
    }
    cout << fin << endl;
}
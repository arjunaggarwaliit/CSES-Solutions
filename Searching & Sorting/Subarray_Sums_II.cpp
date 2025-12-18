#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x; cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >>arr[i];
    map<int,int> mp;
    mp[0]+=1;
    int pre =0;
    int tot =0;
    for(int i=0;i<n;i++){
        pre +=arr[i];
        tot += (mp[pre-x]);
        mp[pre]+=1;
    }
    cout << tot << endl;
}
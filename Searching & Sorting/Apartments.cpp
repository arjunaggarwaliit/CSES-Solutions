#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    sort(b.begin(),b.end());
    sort(arr.begin(),arr.end());
    int count =0;
    auto it = b.begin();
    for(int i=0;i<n;i++){
        auto st = lower_bound(it,b.end(),arr[i]-k);
        auto en = upper_bound(it,b.end(),arr[i]+k);
        en--;
        if(en<st) continue;
        else{
            count+=1; it=st+1;
        }
    }
    cout << count << endl;
}
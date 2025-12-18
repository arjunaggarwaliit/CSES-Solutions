#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x; cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int left = x - arr[i].first;
        int l = i+1;
        int r = n-1;
        while(l<r){
            int sm = arr[l].first + arr[r].first;
            if(sm == left){
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << endl;
                return 0;
            }
            if(sm < left){
                l++;
            }
            else r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
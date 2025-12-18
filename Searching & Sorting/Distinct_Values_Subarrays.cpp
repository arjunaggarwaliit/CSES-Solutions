#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    multiset<pair<int,int>> ms;
    int prev = 0;
    int total =1;
    int curr;
    ms.insert({arr[0],0});
    for(int i=1;i<n;i++){
        auto it = ms.upper_bound({arr[i],INT_MAX});
        if(it != ms.begin()){
            it--;
        }
        if((*it).first == arr[i]){
            curr = max(prev,(*it).second +1);
        }
        else{
            curr = prev;
        }
        total += (i - curr +1);
        ms.insert({arr[i],i});
        prev = curr;
    }
    cout << total << endl;
}
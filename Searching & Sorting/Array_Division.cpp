#include <bits/stdc++.h>
using namespace std;
#define int long long

bool predicate(int n, vector<int>& x, int k, int limit){
    int cnt = 0;
    int curr = 0;
    for(int i=0; i<n; i++){
        if(curr + x[i] <= limit){
            curr += x[i];
        }
        else{
            cnt += 1;
            curr = x[i];
        }
    }
    cnt +=1;
    if(cnt <= k) return true;
    else return false;
}

int32_t main(){
    int n,k; cin >> n >> k;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    int low = *(max_element(x.begin(), x.end()));
    int high = accumulate(x.begin(), x.end(), 0LL);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(predicate(n, x, k, mid)){
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << low << endl;
}
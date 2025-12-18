#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    sort(vec.begin(),vec.end());
    int maxx = 0;
    int i;
    for(i=0;i<n;i++){
        if(vec[i]<= (maxx+1)){
            maxx += vec[i];
        }
        else{
            cout << maxx+1 << endl;
            break;
        }
    }
    if(i==n){
        cout << maxx+1 << endl;
    }
}

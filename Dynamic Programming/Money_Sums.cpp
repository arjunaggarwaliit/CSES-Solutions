#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int32_t main(){
    int n; cin >> n;
    vector<int> a(n+1);
    int tot = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tot += a[i];
    }
    vector<bool> prev(tot+1,false);
    vector<bool> curr(tot+1,false);
    prev[0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=tot;j++){
            if(j-a[i] >=0){
                curr[j] = prev[j-a[i]] | prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    vector<int> s;
    for(int i=1;i<=tot;i++){
        if(prev[i]){
            s.push_back(i);
        }
    }
    cout << s.size() << endl;
    for(auto ele : s){
        cout << ele << " ";
    }
    cout << endl;
}
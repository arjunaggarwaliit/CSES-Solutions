#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    string a,b ; cin >> a>> b;
    int n = a.length();
    int m = b.length();
    vector<int> prev(m+1,0);
    for(int i=0;i<=m;i++) prev[i] = i;
    vector<int> curr(m+1);
    for(int i=1;i<=n;i++){
        curr[0] = i;
        for(int j=1;j<=m;j++){
            curr[j] = LLONG_MAX;
            if(a[i-1]==b[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                curr[j] = min(curr[j],curr[j-1]+1);
                curr[j] = min(curr[j],prev[j]+1);
                curr[j] = min(curr[j],1+ prev[j-1]);
            }
        }
        prev = curr;
    }
    cout << prev[m] << endl;
}

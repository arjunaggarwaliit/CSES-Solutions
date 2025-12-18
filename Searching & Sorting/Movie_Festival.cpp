#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    multiset<pair<int,int>> ms;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        ms.insert({b,a});
    }
    int tot =0;
    int last = -1;
    for(auto pr : ms){
        if(pr.second >= last){
            tot+=1;
            last = pr.first;
        }
        else{
            continue;
        }
    }
    cout << tot << endl;
}

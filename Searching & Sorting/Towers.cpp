#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> cubes(n);
    for(int i=0;i<n;i++) cin >> cubes[i];
    multiset<int> ms;
    for(int i=0;i<n;i++){
        auto it = ms.upper_bound(cubes[i]);
        if(it == ms.end()){
            ms.insert(cubes[i]);
        }
        else{
            ms.erase(it);
            ms.insert(cubes[i]);
        }
    }
    cout << ms.size() << endl;
}

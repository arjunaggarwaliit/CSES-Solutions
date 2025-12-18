#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int x,n; cin >> x >> n;
    vector<int> poles(n);
    for(int i=0;i<n;i++) cin >> poles[i];
    multiset<int> ms;
    ms.insert(0); ms.insert(x);
    multiset<int> paths;
    paths.insert(x);
    for(int i=0;i<n;i++){
        auto itu = ms.upper_bound(poles[i]);
        auto itl = prev(itu);
        paths.erase(paths.find((*itu)-(*itl)));
        paths.insert(poles[i]-(*itl));
        paths.insert((*itu)-poles[i]);
        ms.insert(poles[i]);
        cout << *(prev(paths.end())) << " ";
    }
}
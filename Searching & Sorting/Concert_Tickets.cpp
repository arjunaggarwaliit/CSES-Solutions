#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m ; cin >> n >> m;
    multiset<int> ms;
    for(int i=0;i<n;i++){
        int ele; cin >> ele;
        ms.insert(ele);
    }
    vector<int> t(m);
    for(int i=0;i<m;i++) cin >> t[i];
    int ans[m];
    for(int i=0;i<m;i++){
        int ele = t[i];
        if(ms.empty()){
            ans[i] = -1;
            continue;
        }
        auto pt = ms.upper_bound(ele);
        if(pt == ms.begin()){
            ans[i] = -1;
        }
        else{
            pt--;
            ans[i] = *(pt);
            ms.erase(pt);
        }
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << endl;
    }
}
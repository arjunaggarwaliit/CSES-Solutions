#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    multiset<pair<int,int>> ms;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        ms.insert({a,b});
    }
    multiset<int> dep;
    int maxx =0;
    for(auto pr : ms){
        if(dep.empty()){
            maxx +=1;
            dep.insert(pr.second);
        }
        else{
            auto it = dep.begin();
            if(*it < pr.first){
                dep.erase(it);
                dep.insert(pr.second);
            }
            else{
                maxx +=1;
                dep.insert(pr.second);
            }
        }
    }
    cout << maxx << endl;
}

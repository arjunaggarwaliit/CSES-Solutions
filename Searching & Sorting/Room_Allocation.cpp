#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    multiset<pair<pair<int,int>,int>> ms;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        ms.insert({{a,b},i});
    }
    int maxx = 0;
    multiset<pair<int,int>> dep;
    multiset<pair<int,int>> rooms;
    for(auto pr : ms){
        if(dep.empty()){
            maxx =1;
            dep.insert({pr.first.second,maxx});
            rooms.insert({pr.second,maxx});
        }
        else{
            auto it = dep.begin();
            if((*it).first < pr.first.first){
                rooms.insert({pr.second,(*it).second});
                int rm = (*it).second;
                dep.erase(it);
                dep.insert({pr.first.second,rm});
            }
            else{
                maxx += 1;
                rooms.insert({pr.second,maxx});
                dep.insert({pr.first.second,maxx});
            }
        }
    }
    cout << maxx << endl;
    for(auto ele : rooms){
        cout << ele.second << " ";
    }
    cout << endl;
}
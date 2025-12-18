#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x; cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    multiset<pair<int,int>> mslow;
    vector<int> ind;
    multiset<pair<int,int>> mshigh;
    for(int i=0;i<n;i++){
        if(arr[i] < (x/2)){
            mslow.insert({arr[i],i});
        }
        else if(arr[i] == (x/2)){
            if(x&1){
                mslow.insert({arr[i],i});
            }
            else{
                ind.push_back(i);
            }
        }
        else{
            mshigh.insert({arr[i],i});
        }
    }
    if(ind.size() >=2){
        cout << ind[0]+1 << " " << ind[1]+1 << endl;
    }
    else{
        bool flag = true;
        for(auto pr : mslow){
            if(mshigh.empty()){
                break;
            }
            int ele = pr.first;
            auto it = mshigh.lower_bound({x-ele,INT_MIN});
            if((it == mshigh.end()) || (it->first != x-ele)){
                continue;
            }
            else{
                cout << (pr.second)+1 << " " << (it->second)+1 << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
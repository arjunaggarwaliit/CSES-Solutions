#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x ; cin >> n >> x;
    vector<int> w(n);
    for(int i=0;i<n;i++) cin >> w[i];
    multiset<int> ms;
    int count =0;
    vector<int> pq;
    for(int i=0;i<n;i++){
        if(w[i] <= (x/2)){
            ms.insert(w[i]);
        }
        else{
            pq.push_back(w[i]);
        }
    }
    int ele = pq.size();
    for(int i=0;i<(ele);i++){
        if(ms.empty()){
            count += (ele - i);
            break;
        }
        else{
            int diff = x - (pq[i]);
            auto up = ms.upper_bound(diff);
            if(up == ms.begin()){
                count +=1;
            }
            else{
                up--;
                count+=1;
                ms.erase(up);
            }
        }
    }
    if(!ms.empty()){
        int sz = ms.size();
        count += (sz/2);
        if(sz&1){
            count +=1;
        }
    }
    cout << count << endl;
}
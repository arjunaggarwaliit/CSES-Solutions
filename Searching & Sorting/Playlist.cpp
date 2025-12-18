#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> song(n);
    for(int i=0;i<n;i++) cin >> song[i];
    int maxx = INT_MIN;
    multiset<int> ms;
    int count = 0;
    int start = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(ms.find(song[i]) == ms.end()){
            ms.insert(song[i]);
            count+=1;
            maxx = max(maxx, count);
        }
        else if(mp[song[i]] < start){
            count+=1;
            maxx = max(maxx, count);
        }
        else{
            int ind = mp[song[i]];
            ind++;
            start = ind;
            count = i-ind+1;
            maxx = max(maxx, count);
        }
        mp[song[i]] = i;
    }
    cout << maxx << endl;
}

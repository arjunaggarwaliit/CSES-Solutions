#include <bits/stdc++.h>
using namespace std;
#define int long long

struct interval{
    int start;
    int end;

    interval() = default;
    interval(int s, int e) : start(s), end(e) {}

    bool operator<(const interval& other) const{
        if(end < other.end) return true;
        else if(end > other.end) return false;
        else{
            if(start < other.start) return true;
            else return false;
        }
    }
};

int32_t main(){
    int n,k; cin >> n >> k;
    vector<interval> times(n);
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        times[i] = interval(a, b);
    }
    sort(times.begin(), times.end());
    int ans= 0;
    multiset<int> ms;
    for(int i=0; i<k; i++){
        ms.insert(0);
    }
    for(int i=0; i<n; i++){
        // find largest element <= times[i].start
        auto it = ms.upper_bound(times[i].start);
        if(it == ms.begin()) continue;
        else{
            it--;
            ms.erase(it);
            ms.insert(times[i].end);
            ans+=1;
        }
    }
    cout << ans << endl;
}
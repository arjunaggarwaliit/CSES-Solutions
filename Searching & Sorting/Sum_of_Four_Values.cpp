#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,x; cin >> n >> x;
    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        int ele; cin >> ele;
        a.push_back({ele,i+1});
    }
    sort(a.begin(),a.end());
    for(int i=0 ; i<n ; i++){
        if(a[i].first >= x) break;
        for(int j=i+1; j<n ; j++){
            if(j+1 >= n-1) continue;
            if(a[i].first + a[j].first >= x) break;
            int pt1 = j+1; int pt2 = n-1;
            int smleft = x- (a[i].first + a[j].first);
            while(pt1 < pt2){
                if(a[pt1].first + a[pt2].first == smleft){
                    cout << a[i].second << " " << a[j].second << " " << a[pt1].second << " " << a[pt2].second << endl;
                    return 0;
                }
                else if(a[pt1].first + a[pt2].first < smleft){
                    pt1++;
                }
                else{
                    pt2--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
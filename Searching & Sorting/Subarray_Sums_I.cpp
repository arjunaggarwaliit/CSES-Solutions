#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x ; cin >> n >> x;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    int pt1=0;
    int pt2=0;
    int cnt =0;
    int curr = 0;
    while(pt1<n && pt2<n){
        curr += vec[pt2];
        pt2++;
        while(curr >= x){
            if(curr == x) cnt+=1;
            curr -= vec[pt1];
            pt1++;
        }
    }
    cout << cnt << endl;
}

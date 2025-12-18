#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(vector<int> &p, int ele){
    int s=0;
    int n = p.size();
    for(int i=0;i<n;i++){
        s += (abs(ele - p[i]));
    }
    return s;
}
int32_t main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    sort(p.begin(),p.end());
    int ele1;
    int ele2;
    if(n&1){
        ele1 = p[n/2];
        ele2 = ele1;
    }
    else{
        ele1 = p[(n/2)-1];
        ele2 = p[n/2];
    }
    cout << min(calc(p,ele1),calc(p,ele2)) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    map<int,int> ind;
    for(int i=0;i<n;i++){
        ind[x[i]] = i;
    }
    vector<bool> num(n);
    for(int i=1;i<n;i++){
        if(ind[i+1]>ind[i]){
            num[i] = true;
        }
        else num[i] = false;
    }
    int i=1;
    int count =1;
    while(i<n){
        while(i<n && num[i]){
            i++;
        }
        if(num[i] == false){
            count+=1;
        }
        i++;
    }
    cout << count << endl;
}
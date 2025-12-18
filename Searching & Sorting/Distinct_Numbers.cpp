#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    set<int> s;
    int ans =0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])==s.end()){
            ans+=1;
            s.insert(arr[i]);
        }
    }
    cout << ans << endl;
}
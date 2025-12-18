#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && (st.top().first >= arr[i])){
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
            st.push({arr[i],i+1});
        }
        else{
            auto pr = st.top();
            cout << pr.second << " ";
            st.push({arr[i],i+1});
        }
    }
    cout << endl;
}
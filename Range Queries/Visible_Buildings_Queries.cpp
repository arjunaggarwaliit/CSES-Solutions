#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX

// int position(vector<vector<int>> &binaryjump, int k, int from){
//     for(int i=0 ;i<31; i++){
//         if(k &(1LL << i)){
//             from = binaryjump[from][i];
//             if(from == inf){
//                 return inf;
//             }
//         }
//     }
//     return from;
// }

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin >> n >> q;
    vector<int> h(n);
    for(int i=0 ; i<n ; i++){
        cin >> h[i];
    }
    vector<int> greater(n);
    stack<pair<int,int>> st;
    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && (st.top()).first <= h[i]){
            st.pop();
        }
        if(st.empty()){
            greater[i] = inf;
            st.push({h[i],i});
        }
        else{
            greater[i] = (st.top()).second;
            st.push({h[i],i});
        }
    }
    int LOG = 32-__builtin_clz(n);
    vector<vector<int>> binaryjump(n, vector<int>(LOG));
    for(int i=0 ; i<n ; i++){
        binaryjump[i][0] = greater[i];
    }
    for(int j=1 ; j<LOG; j++){
        for(int i=0 ; i<n ; i++){
            if(binaryjump[i][j-1] == inf){
                binaryjump[i][j] = inf;
            }
            else{
                binaryjump[i][j] = binaryjump[binaryjump[i][j-1]][j-1];
            }
        }
    }
    // while(q--){
    //     int a,b; cin >> a >> b;
    //     a--; b--;
    //     int l = 0; int r = n;
    //     while(l <= r){
    //         int mid = l + (r-l)/2;
    //         if(position(binaryjump,mid,a) > b){
    //             r = mid - 1;
    //         }
    //         else{
    //             l = mid + 1;
    //         }
    //     }
    //     cout << l << endl;
    // }
    while(q--){
        int a,b; cin >> a >> b;
        a--; b--;
        int jmps = 0;
        int from = a;
        for(int i=LOG-1 ; i>=0 ; i--){
            if(binaryjump[from][i] <= b){
                from = binaryjump[from][i];
                jmps += (1LL << i);
            }
        }
        cout << jmps+1 << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void add_increm(int num, int k, vector<int> &basis){
    for(int i=k-1; i>=0; i--){
        if(basis[k-i-1]&(1LL << i)){
            if(num& (1LL << i)) num^= (basis[k-i-1]);
        }
        else{
            if(num& (1LL << i)) {basis[k-i-1] = num; break;}
        }
    }
}

vector<int> make_basis(int n, vector<int>& arr, int k){
    vector<int> basis(k,0);
    for(int i=0; i<n; i++){
        add_increm(arr[i], k, basis);
    }
    return basis;
}

int distinct_subsets(int n, vector<int>& basis, int k){
    int cnt = 0;
    for(int i=k-1; i>=0; i--){
        if(basis[k-i-1]&(1LL << i)) cnt+=1;
    }
    return (1LL << cnt);
}

int32_t main(){
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    int k = 32;
    vector<int> basis = make_basis(n, x, k);
    cout << distinct_subsets(n, basis, k) << endl;
}
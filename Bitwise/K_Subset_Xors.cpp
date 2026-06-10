#include <bits/stdc++.h>
using namespace std;
#define int long long

void add_increm(int num, int k, vector<int> &basis){
    for(int i=k-1; i>=0; i--){
        if(basis[k-i-1]&(1LL << i)){
            if(num& (1LL << i)) num^= (basis[k-i-1]);
        }
        else{
            if(num& (1LL << i)) {
                basis[k-i-1] = num; break;
            }
        }
    }
}

vector<int> make_basis(int n, vector<int>& arr, int k){
    vector<int> basis(k,0);
    for(int i=0; i<n; i++){
        add_increm(arr[i], k, basis);
    }
    for(int i=0; i<k; i++){
        if(basis[i] == 0) continue;
        for(int j=0; j<i; j++){
            if(basis[j] & (1LL << (k-i-1))) basis[j]^=basis[i];
        }
    }
    return basis;
}

vector<int> smallest_k(int n, int k, int bits, vector<int>& basis){
    vector<int> dis;
    for(int i= bits-1; i>=0; i--){
        if(basis[i] != 0) dis.push_back(basis[i]);
    }
    int cnt = 0;
    int sl = dis.size();
    vector<int> ans;
    int many = n - sl;
    for(int i=0; i< (1LL << sl); i++){
        int xorr = 0;
        for(int j=0; j< sl; j++){
            if(i&(1LL << j)) xorr^=dis[j];
        }
        for(int j=0; j<(1LL << many); j++){
            if(cnt == k) break;
            ans.push_back(xorr);
            cnt++;
        }
        if(cnt == k) break;
    }
    return ans;
}

int32_t main(){
    int n,k; cin >> n >> k;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    int bits = 32;
    vector<int> basis = make_basis(n, x, bits);
    vector<int> ans = smallest_k(n, k, bits, basis);
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

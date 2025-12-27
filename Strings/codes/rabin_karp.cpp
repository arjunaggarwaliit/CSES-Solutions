#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> rabin_karp(string const& s, string const& t){
    int p = 31; int mod = 1000000009;
    vector<int> pow(max(s.size(), t.size()));
    pow[0] = 1;
    for(int i=1 ; i< pow.size(); i++){
        pow[i] = pow[i-1] * p;
        pow[i] %= mod;
    }
    vector<int> h(t.size());
    h[0] = (t[0]-'a'+1);
    for(int i=1 ; i< t.size() ; i++){
        h[i] = h[i-1] + ((t[i]-'a'+1) * pow[i]);
        h[i] %= mod;
    }
    int pattern = 0;
    for(int i=0 ; i<s.size(); i++){
        pattern += (s[i]-'a'+1)*pow[i];
        pattern %= mod;
    }
    vector<int> ind;
    for(int i=0; i<= t.size()-s.size(); i++){
        int hash = h[i+s.size()-1]+mod;
        if(i!=0) hash-=h[i-1];
        hash %= mod;
        int cmp = pattern*pow[i];
        cmp %= mod;
        if(hash == cmp) ind.push_back(i);
    }
    return ind;
}
int32_t main(){
    string s; string t;
    cin >> s >> t;
    vector<int> ans = rabin_karp(s,t);
    for(auto ele : ans){
        cout << ele << " ";
    }
}
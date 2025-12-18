#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int32_t main(){
    string s; cin >> s;
    int n = s.length();
    vector<int> pi = prefix_function(s);
    vector<int> ind(n,0);
    for(int i=0; i<n-1; i++){
        ind[pi[i]]+=1;
    }
    for(int i=n-1 ; i>0 ; i--){
        ind[pi[i-1]] += ind[i];
    }
    int len = pi[n-1];
    set<pair<int,int>> ms;
    ms.insert({n,1});
    while(1){
        if(len == 0) break;
        else{
            ms.insert({len,2+ind[len]});
            len = pi[len-1];
        }
    }
    cout << ms.size() << endl;
    for(auto ele : ms){
        cout << ele.first << " " << ele.second << endl;
    }
}
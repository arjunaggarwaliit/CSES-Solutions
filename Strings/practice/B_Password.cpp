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
    vector<int> ind(n,-1);
    for(int i=0; i<n-1; i++){
        ind[pi[i]] = i;
    }
    int len = pi[n-1];
    while(1){
        if(len==0){
            cout << "Just a legend" << endl;
            break;
        }
        else{
            if(ind[len] == -1){
                len = pi[len-1];
            }
            else{
                int i = ind[len];
                int j = i - len + 1;
                for(int k=j ; k<=i ; k++){
                    cout << s[k];
                }
                cout << endl;
                break;
            }
        }
    }
}
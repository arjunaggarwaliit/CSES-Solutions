#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> prefix_function_brute_force(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++){
        for (int k = 0; k <= i; k++){
        //     cout << i << " " << k << endl;
        // cout << s.substr(0,k) << " " << s.substr(i-k+1,k) << endl;
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
        }
    }
    return pi;
}
vector<int> prefix_function(string s) {
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

struct kmp{
    string t;
    vector<int> pi;
    int n;

    void init(int n_) {
        n = n_;
        t.clear();
        pi.clear();
    }

    vector<int> prefix_function(const string &s) {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    void build(const string &text) {
        t = text;
        n = t.size();
        pi = prefix_function(t);
    }

    vector<int> get_pi() {
        return pi;
    }

    vector<int> pattern(const string &p) {
        string concat = p + "#" + t;
        vector<int> k = prefix_function(concat);
        vector<int> occ;

        int m = p.size();
        for (int i = m + 1; i < concat.size(); i++) {
            if (k[i] == m) {
                occ.push_back(i - 2*m);
            }
        }
        return occ;
    }
};


int32_t main(){
    string s; cin >> s;
    vector<int> pre = prefix_function(s);
    for(auto ele : pre){
        cout << ele << " ";
    }
    cout << endl;
}
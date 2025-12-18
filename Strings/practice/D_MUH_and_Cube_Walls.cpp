#include <bits/stdc++.h>
using namespace std;
#define int long long

struct KMP{
    vector<int> t;
    vector<int> pi;
    int n;

    void init(int n_) {
        n = n_;
        t.clear();
        pi.clear();
    }

    vector<int> prefix_function(const vector<int> &a) {
        int n = a.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && a[i] != a[j])
                j = pi[j - 1];
            if (a[i] == a[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    void build(const vector<int> &text) {
        t = text;
        n = t.size();
        pi = prefix_function(t);
    }

    vector<int> get_pi() {
        return pi;
    }

    vector<int> pattern(const vector<int> &p) {
        vector<int> concat;
        concat.reserve(p.size() + 1 + t.size());
        concat.insert(concat.end(), p.begin(), p.end());
        concat.push_back(LLONG_MAX);
        concat.insert(concat.end(), t.begin(), t.end());
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

struct Z{
    vector<int> t;
    vector<int> zt;
    int n;

    void init(int n_) {
        n = n_;
        t.clear();
        zt.clear();
    }

    vector<int> z_function(const vector<int> &s){
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    void build(const vector<int> &text){
        t = text;
        n = t.size();
        zt = z_function(t);
    }

    vector<int> get_z(){
        return zt;
    }

    vector<int> pattern(const vector<int> &p) {
        vector<int> concat;
        concat.reserve(p.size() + 1 + t.size());
        for (int x : p) concat.push_back(x);
        concat.push_back(LLONG_MAX);
        for (int x : t) concat.push_back(x);
        vector<int> zc = z_function(concat);
        vector<int> occ;
        int m = p.size();
        for (int i = m + 1; i < concat.size(); i++){
            if (zc[i] >= m){
                occ.push_back(i - (m + 1));
            }
        }
        return occ;
    }
};


int32_t main(){
    int n,w; cin >> n >> w;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i=0 ; i<n-1 ; i++){
        a[i] -= a[i+1];
    }
    a.pop_back();
    KMP kmp;
    kmp.init(n-1);
    kmp.build(a);
    vector<int> p(w);
    for(int i=0 ; i<w ; i++) cin >> p[i];
    for(int i=0 ; i<w-1 ; i++) p[i] -= p[i+1];
    p.pop_back();
    if(w > n){
        cout << 0 << endl;
    }
    else if(w==1){
        cout << n << endl;
    }
    else{
        cout << kmp.pattern(p).size() << endl;
    }
}
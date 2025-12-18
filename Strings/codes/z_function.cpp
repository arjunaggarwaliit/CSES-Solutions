#include <bits/stdc++.h>
using namespace std;
#define int long long
// vector<int> z_function(string s) {
//     int n = s.size();
//     vector<int> z(n);
//     int l = 0, r = 0;
//     for(int i = 1; i < n; i++) {
//         if(i < r) {
//             z[i] = min(r - i, z[i - l]);
//         }
//         while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             z[i]++;
//         }
//         if(i + z[i] > r) {
//             l = i;
//             r = i + z[i];
//         }
//     }
//     return z;
// }
// struct z{
//     string t;
//     vector<int> zt;
//     int n;
//     void init(int n_){
//         n = n_;
//         t.clear();
//         zt.clear();
//     }

//     vector<int> z_function(const string &s){
//         int n = s.size();
//         vector<int> z(n);
//         int l = 0, r = 0;
//         for (int i = 1; i < n; i++){
//             if (i < r){
//                 z[i] = min(r - i, z[i - l]);
//             }
//             while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
//                 z[i]++;
//             }
//             if (i + z[i] > r){
//                 l = i;
//                 r = i + z[i];
//             }
//         }
//         return z;
//     }

//     void build(const string &text){
//         t = text;
//         n = t.size();
//         zt = z_function(t);
//     }

//     vector<int> get_z(){
//         return zt;
//     }

//     vector<int> pattern(const string &s){
//         string concat = s + "#" + t;
//         vector<int> zc = z_function(concat);
//         vector<int> occ;
//         int m = s.size();
//         for (int i = m + 1; i < concat.size(); i++){
//             if (zc[i] >= m) {
//                 occ.push_back(i - (m + 1));
//             }
//         }
//         return occ;
//     }

//     int distinct_substrings(){
//         int total = 0;
//         int curr = 0;
//         string s = "";
//         for (int i = 0; i < n; i++){
//             s.push_back(t[i]);
//             vector<int> zc = z_function(s);
//             int mx = 0;
//             for (int j = 1; j < zc.size(); j++) mx = max(mx, zc[j]);
//             total += s.size() - mx;
//         }
//         return total;
//     }

//     string compressed(){
//         if (t.empty()) return "";
//         vector<int> zc = zt;
//         int n = t.size();
//         for (int i = 1; i < n; i++) {
//             if (n % i == 0 && i + zc[i] == n){
//                 return t.substr(0, i);
//             }
//         }
//         return t;
//     }
// };
struct z{
    string t;
    vector<int> zt;
    int n;
    void init(int n_){
        n = n_;
        t.clear();
        zt.clear();
    }

    vector<int> z_function(const string &s){
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++){
            if (i < r){
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
                z[i]++;
            }
            if (i + z[i] > r){
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    void build(const string &text){
        t = text;
        n = t.size();
        zt = z_function(t);
    }

    vector<int> get_z(){
        return zt;
    }

    vector<int> pattern(const string &s){
        string concat = s + "#" + t;
        vector<int> zc = z_function(concat);
        vector<int> occ;
        int m = s.size();
        for (int i = m + 1; i < concat.size(); i++){
            if (zc[i] >= m) {
                occ.push_back(i - (m + 1));
            }
        }
        return occ;
    }
};

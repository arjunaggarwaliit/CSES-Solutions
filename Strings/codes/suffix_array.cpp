#include <bits/stdc++.h>
using namespace std;
#define int long long

// void radix_sort(vector<pair<pair<int,int>,int>> &a){
//     int n = a.size();
//     {
//         vector<int> cnt(n);
//         for(auto x : a) cnt[x.first.second]++;
//         vector<pair<pair<int,int>,int>> a_new(n);
//         vector<int> pos(n);
//         pos[0] = 0;
//         for(int i=1 ;i<n ; i++){
//             pos[i] = pos[i-1] + cnt[i-1];
//         }
//         for(auto x : a){
//             int i = x.first.second;
//             a_new[pos[i]] = x;
//             pos[i]++;
//         }
//         a = a_new;
//     }
//     {
//         vector<int> cnt(n);
//         for(auto x : a) cnt[x.first.first]++;
//         vector<pair<pair<int,int>,int>> a_new(n);
//         vector<int> pos(n);
//         pos[0] = 0;
//         for(int i=1 ;i<n ; i++){
//             pos[i] = pos[i-1] + cnt[i-1];
//         }
//         for(auto x : a){
//             int i = x.first.first;
//             a_new[pos[i]] = x;
//             pos[i]++;
//         }
//         a = a_new;
//     }
// }

// vector<int> suffix_array(string &s){
//     s += '$';
//     int n = s.size();
//     vector<int> p(n), c(n);
//     {
//         vector<pair<char,int>> a(n);
//         for(int i=0 ;i<n; i++) a[i] ={s[i],i};
//         sort(a.begin(),a.end());

//         for(int i=0 ; i<n ; i++) p[i] = a[i].second;
//         c[p[0]] = 0;
//         for(int i=1 ; i<n ; i++){
//             if(a[i].first == a[i-1].first){
//                 c[p[i]] = c[p[i-1]];
//             }
//             else{
//                 c[p[i]] = c[p[i-1]] + 1;
//             }
//         }
//     }

//     int k = 0;
//     while((1 << k) < n){
//         vector<pair<pair<int,int>,int>> a(n);
//         for(int i=0 ; i<n ; i++) a[i] = {{c[i],c[(i + (1 << k))% n]},i};
//         radix_sort(a);
//         for(int i=0 ; i<n ; i++) p[i] = a[i].second;
//         c[p[0]] = 0;
//         for(int i=1 ; i<n ; i++){
//             if(a[i].first == a[i-1].first){
//                 c[p[i]] = c[p[i-1]];
//             }
//             else{
//                 c[p[i]] = c[p[i-1]] + 1;
//             }
//         }
//         k++;
//     }

//     return p;
// }

void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();
    vector<int> cnt(n);
    for(auto x : c) cnt[x]++;
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i=1 ;i<n ; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

vector<int> suffix_array(string &s){
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i=0 ;i<n; i++) a[i] ={s[i],i};
        sort(a.begin(),a.end());

        for(int i=0 ; i<n ; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1 ; i<n ; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    int k = 0;
    while((1 << k) < n){

        for(int i=0 ; i<n ; i++){
            p[i] = (p[i] - (1<<k) +n)%n;
        }

        count_sort(p,c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i=1 ; i<n ; i++){
            pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int,int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if(prev == curr){
                c_new[p[i]] = c_new[p[i-1]];
            }
            else{
                c_new[p[i]] = c_new[p[i-1]] + 1;
            }
        }
        c = c_new;
        k++;
    }

    // return p;

    vector<int> lcp(n);
    k = 0;
    for(int i=0 ; i<n-1; i++){
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1,0LL);
    }
}



int32_t main(){
    string s;  cin >> s;
    vector<int> suff = suffix_array(s);
    for(auto ele : suff){
        cout << ele << " ";
    }
    cout << endl;
}
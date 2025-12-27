#include <bits/stdc++.h>
using namespace std;
#define int long long

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

pair<vector<int>,vector<int>> suffix_array(string &s){
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
    vector<int> lcp(n);
    k = 0;
    for(int i=0 ; i<n-1; i++){
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1,0LL);
    }

    return {p,lcp};
}

int different_substrings(string &s){
    int n = s.length();
    pair<vector<int>,vector<int>> pr = suffix_array(s);
    vector<int> suf = pr.first;
    vector<int> lcp = pr.second;
    int ans = 0;
    for(int i=1 ; i<=n ; i++){
        ans += (n-suf[i]-lcp[i]);
    }
    return ans;
}

string longest_common_substring(const string &s, const string &t){
    string op = s+'&'+t;
    int n = op.length();
    int n1 = s.length();
    int n2 = t.length();
    pair<vector<int>,vector<int>> pr = suffix_array(op);
    vector<int> suf = pr.first;
    vector<int> lcp = pr.second;
    int maxx = 0; int ind = -1;
    for(int i=2 ; i<=n; i++){
        int j = suf[i]; int k = suf[i-1];
        if(((j>=0 && j<n1)&&(k>n1 && k<n)) || ((k>=0 && k<n1)&&(j>n1 && j<n))){
            if(lcp[i] > maxx){
                ind = min(j,k); maxx = lcp[i];
            }
        }
    }
    if(maxx == 0){
        return "";
    }
    else{
        string ans = "";
        for(int i= ind; i < ind+maxx; i++){
            ans += op[i];
        }
        return ans;
    }
}

int32_t main(){
    string s,t; cin >> s >> t;
    cout << longest_common_substring(s,t) << endl;
}
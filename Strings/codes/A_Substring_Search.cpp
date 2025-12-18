#include <bits/stdc++.h>
using namespace std;

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

    return p;
}

bool substring_check(string& t, string& s, vector<int>& suff){
    int modt = t.length();
    int mods = s.length();
    int l = 0;
    int r = mods - 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        bool eq = true;
        for(int j = suff[mid]; j<mods && j-suff[mid]<modt ; j++){
            if(s[j] == t[j-suff[mid]]) continue;
            else if(s[j] > t[j-suff[mid]]){
                r = mid-1;
                eq = false; break;
            }
            else{
                l = mid+1;
                eq = false; break;
            }
        }
        if(eq && mods-suff[mid] >= modt){
            return true;
        }
        else{
            if(eq){
                l = mid + 1;
            }
        }
    }
    return false;
}

int substring_lower(string& t, string& s, vector<int>& suff){
    int modt = t.length();
    int mods = s.length();
    int l = 0;
    int r = mods - 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        bool eq = true;
        for(int j = suff[mid]; j<mods && j-suff[mid]<modt ; j++){
            if(s[j] == t[j-suff[mid]]) continue;
            else if(s[j] > t[j-suff[mid]]){
                r = mid-1;
                eq = false; break;
            }
            else{
                l = mid+1;
                eq = false; break;
            }
        }
        if(eq && mods-suff[mid] >= modt){
            r = mid - 1;
        }
        else{
            if(eq){
                l = mid + 1;
            }
        }
    }
    return r;
}

int substring_upper(string& t, string& s, vector<int>& suff){
    int modt = t.length();
    int mods = s.length();
    int l = 0;
    int r = mods - 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        bool eq = true;
        for(int j = suff[mid]; j<mods && j-suff[mid]<modt ; j++){
            if(s[j] == t[j-suff[mid]]) continue;
            else if(s[j] > t[j-suff[mid]]){
                r = mid-1;
                eq = false; break;
            }
            else{
                l = mid+1;
                eq = false; break;
            }
        }
        if(eq){
            l = mid + 1;
        }
    }
    return l;
}

int32_t main(){
    string s; cin >> s;
    vector<int> suff = suffix_array(s);
    suff.erase(suff.begin());
    s.pop_back();
    // cout << s << endl;
    // for(auto ele : suff){
    //     cout << ele << " ";
    // }
    // cout << endl;
    int t; cin >> t;
    while(t--){
        string t; cin >> t;
        if(substring_check(t,s,suff)){
            int r = substring_lower(t,s,suff);
            int l = substring_upper(t,s,suff);
            r++; l--;
            cout << l-r+1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}
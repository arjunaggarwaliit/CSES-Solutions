#include <bits/stdc++.h>
using namespace std;
struct cmpa{
    bool operator()(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b) const{
        if(a.first.second!=b.first.second){
            return a.first.second < b.first.second;
        }
        else{
            return a.first.first > b.first.first;
        }
    }
};
struct cmpb{
    bool operator()(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b) const{
        if(a.first.first!=b.first.first){
            return a.first.first < b.first.first;
        }
        else{
            return a.first.second > b.first.second;
        }
    }
};
int main(){
    int n; cin >> n;
    vector<pair<int,int>> ranges;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        ranges.push_back({a,b});
    }
    vector<int> ansa(n);
    vector<int> ansb(n);
    multiset<pair<pair<int,int>,int>,cmpa> msa;
    for(int i=0;i<n;i++){
        msa.insert({ranges[i],i});
    }
    int prev = INT_MIN;
    for(auto pr : msa){
        if(pr.first.first <= prev){
            ansa[pr.second] = 1;
        }
        else{
            prev = pr.first.first;
            ansa[pr.second] = 0;
        }
    }
    multiset<pair<pair<int,int>,int>,cmpb> msb;
    for(int i=0;i<n;i++){
        msb.insert({ranges[i],i});
    }
    int next = INT_MIN;
    for(auto pr : msb){
        if(pr.first.second <= next){
            ansb[pr.second] = 1;
        }
        else{
            next = pr.first.second;
            ansb[pr.second] = 0;
        }
    }
    for(auto ele : ansa){
        cout << ele << " ";
    }
    cout << endl;
    for(auto ele : ansb){
        cout << ele << " ";
    }
    cout << endl;
}
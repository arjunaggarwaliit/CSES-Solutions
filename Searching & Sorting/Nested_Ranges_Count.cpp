#include <bits/stdc++.h>
using namespace std;
// #define int long long
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main(){
    int n; cin >> n;
    vector<int> ind;
    vector<pair<int,int>> ranges;
    for(int i=0 ; i<n ; i++){
        ind.push_back(i);
        int x,y; cin >> x >> y;
        x--;y--;
        ranges.push_back({x,y});
    }
    vector<int> master(n,0);
    vector<int> master_of(n);
    indexed_set<pair<int,int>> master_tree;
    sort(ind.begin(),ind.end(),[&](const int&a, const int&b){
        if(ranges[a].second == ranges[b].second){
            return ranges[a].first > ranges[b].first;
        }
        else{
            return ranges[a].second < ranges[b].second;
        }
    });
    for(int i=0 ; i<n ; i++){
        master_of[ind[i]] = i-master_tree.order_of_key({ranges[ind[i]].first,INT_MIN});
        master_tree.insert({ranges[ind[i]].first,i});
    }
    for(int i=0 ; i<n ; i++){
        cout << master_of[i] << " ";
    }
    cout << endl;
    vector<int> slave(n,0);
    vector<int> slave_of(n);
    indexed_set<pair<int,int>> slave_tree;
    sort(ind.begin(),ind.end(),[&](const int&a, const int&b){
        if(ranges[a].first == ranges[b].first){
            return ranges[a].second > ranges[b].second;
        }
        else{
            return ranges[a].first < ranges[b].first;
        }
    });
    for(int i=0 ; i<n ; i++){
        slave_of[ind[i]] = i-slave_tree.order_of_key({ranges[ind[i]].second,INT_MIN});
        slave_tree.insert({ranges[ind[i]].second,i});
    }
    for(int i=0; i<n ; i++){
        cout << slave_of[i] << " ";
    }
    cout << endl;
}
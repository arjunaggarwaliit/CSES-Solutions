#include <bits/stdc++.h>
using namespace std;
#define int long long

// struct fenwicktree{
//     int n;
//     vector<int> bit;
//     vector<int> arr;
//     void init(int n_, const vector<int>& a){
//         n = n_;
//         bit.assign(n + 1, 0);
//         arr = a;
//     }
//     void build(const vector<int> &a){
//         init(a.size(),a);
//         for (int i = 1; i <= n; i++) {
//             bit[i] += a[i-1];
//             int j = (i) + ((i) & -(i));
//             if (j <= n) bit[j] += bit[i];
//         }
//     }
//     void update(int i, int val){
//         int delta = val - arr[i];
//         arr[i] = val;
//         for (i += 1; i <= n; i += i & -i){
//             bit[i] += delta;
//         }
//     }
//     int prefix_query(int i){
//         int s = 0;
//         for (i += 1; i > 0; i -= i & -i) s += bit[i];
//         return s;
//     }
//     int query(int l, int r){
//         return prefix_query(r) - (l ? prefix_query(l - 1) : 0);
//     }
// };

struct fenwicktree{
    int n;
    vector<int> bit;
    void init(int n_){
        n = n_;
        bit.assign(n + 1, 0);
    }
    void build(vector<int> &a){
        init(a.size());
        for (int i = 0; i < n; i++) {
            i++;
            bit[i] += a[i-1];
            int j = (i) + ((i) & -(i));
            if (j <= n) bit[j] += bit[i];
        }
    }
    void sum(int i, int val){
        for (i += 1; i <= n; i += i & -i) bit[i] += val;
    }
    int prefix_query(int i){
        int s = 0;
        for (i += 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int query(int l, int r){
        return prefix_query(r) - (l ? prefix_query(l - 1) : 0);
    }
};


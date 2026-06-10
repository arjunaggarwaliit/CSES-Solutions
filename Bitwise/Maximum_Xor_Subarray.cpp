#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    node* child[2];
    node(){
        child[0] = child[1] = nullptr;
    }
};

void insert(node *root, int x){
    node* curr = root;
    for(int i=30; i>=0; i--){
        int bit = (x >> i)&1;
        if(!(curr -> child[bit])){
            curr->child[bit] = new node();
        }
        curr = curr->child[bit];
    }
}

int query(node* root, int x){
    node* curr = root;
    int ans = 0;
    for(int i=30; i>=0; i--){
        int bit = (x >> i)&1;
        if(curr->child[1- bit]){
            ans |= (1 << i);
            curr = curr->child[1-bit];
        }
        else curr = curr->child[bit];
    }
    return ans;
}

int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    node* root = new node();
    insert(root, 0);
    int pref = 0;
    int ans = 0;
    for(int x : a){
        pref^=x;
        ans = max(ans , query(root, pref));
        insert(root, pref);
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> radj;
vector<int> start, finish, assign;
int timer = 0;
int value = 0;

void dfs(int node) {
    timer++;
    start[node] = timer;
    for (int neigh : adj[node]) {
        if (start[neigh] == 0) {
            dfs(neigh);
        }
    }
    timer++;
    finish[node] = timer;
}

void make(int node, int val) {
    assign[node] = val;
    for (int child : radj[node]) {
        if (assign[child] == 0) {
            make(child, val);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    adj.assign(2 * m + 1, vector<int>());
    radj.assign(2*m + 1, vector<int>());
    start.assign(2 * m + 1, 0);
    finish.assign(2 * m + 1, 0);
    assign.assign(2 * m + 1, 0);
    for (int i = 0; i < n; ++i) {
        char c1, c2;
        int n1, n2;
        cin >> c1 >> n1 >> c2 >> n2;
        if (c1 == '+' && c2 == '+') {
            adj[n1 + m].push_back(n2);
            adj[n2 + m].push_back(n1);
        } else if (c1 == '+' && c2 == '-') {
            adj[n1 + m].push_back(n2 + m);
            adj[n2].push_back(n1);
        } else if (c1 == '-' && c2 == '+') {
            adj[n1].push_back(n2);
            adj[n2 + m].push_back(n1 + m);
        } else {
            adj[n1].push_back(n2 + m);
            adj[n2].push_back(n1 + m);
        }
    }
    for (int i = 1; i <= 2 * m; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    for(int i=1 ; i<= 2*m ; i++){
        for(auto node : adj[i]){
            radj[node].push_back(i);
        }
    }
    for (int i = 1; i <= 2 * m; ++i) {
        if (start[i] == 0) {
            dfs(i);
        }
    }
    vector<int> lis(2 * m);
    iota(lis.begin(), lis.end(), 1);
    sort(lis.begin(), lis.end(), [](int a, int b) {
        return finish[a] > finish[b];
    });
    for (int node : lis) {
        if (assign[node] == 0) {
            value++;
            make(node, value);
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (assign[i] == assign[i + m]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (assign[i] < assign[i + m]) {
            cout << "- ";
        } else {
            cout << "+ ";
        }
    }
    cout << endl;
}

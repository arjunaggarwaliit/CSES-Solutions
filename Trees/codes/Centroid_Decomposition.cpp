#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
    int n;
    vector<vector<int>> &adj;
    vector<int> subtree_size;
    vector<int> parent_centroid;
    vector<bool> visited;

    CentroidDecomposition(int n, vector<vector<int>> &adj)
        : n(n), adj(adj) {
        subtree_size.resize(n + 1);
        parent_centroid.assign(n + 1, -1);
        visited.assign(n + 1, false);
    }

    int dfs_size(int node, int parent) {
        subtree_size[node] = 1;
        for (int child : adj[node]) {
            if (child != parent && !visited[child]) {
                subtree_size[node] += dfs_size(child, node);
            }
        }
        return subtree_size[node];
    }

    int find_centroid(int node, int parent, int total_nodes) {
        for (int child : adj[node]) {
            if (child != parent && !visited[child] &&
                subtree_size[child] > total_nodes / 2) {
                return find_centroid(child, node, total_nodes);
            }
        }
        return node;
    }

    void decompose(int node, int parent = -1) {
        int total_nodes = dfs_size(node, -1);
        int centroid = find_centroid(node, -1, total_nodes);

        visited[centroid] = true;
        parent_centroid[centroid] = parent;

        for (int child : adj[centroid]) {
            if (!visited[child]) {
                decompose(child, centroid);
            }
        }
    }
};

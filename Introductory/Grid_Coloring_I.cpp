#include <bits/stdc++.h>
using namespace std;
bool check(int row, int col, vector<vector<char>> &grid, int n, int m, vector<char> &letters) {
    if (row == n && col == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << grid[i][j];
            cout << endl;
        }
        return true;
    }
    for (char chr : letters) {
        if (grid[row][col] == chr) continue;
        if (row > 0 && grid[row - 1][col] == chr) continue;
        if (col > 0 && grid[row][col - 1] == chr) continue;
        grid[row][col] = chr;
        bool ok = false;
        if (col == m - 1) ok = check(row + 1, 0, grid, n, m, letters);
        else ok = check(row, col + 1, grid, n, m, letters);
        if (ok) return true;
    }
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }
    vector<char> letters = {'A', 'B', 'C', 'D'};
    if (!check(0, 0, grid, n, m, letters)) {
        cout << "IMPOSSIBLE\n";
    }
}

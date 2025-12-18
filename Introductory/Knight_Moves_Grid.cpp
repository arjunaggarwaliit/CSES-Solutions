#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    vector<vector<int>> grid(n,vector<int>(n,INT_MAX));
    grid[0][0] = 0;
    multiset<pair<int,int>> ms;
    ms.insert({0,0});
    while(!ms.empty()){
        auto it = ms.begin();
        int row = it->first;
        int col = it->second;
        ms.erase(it);
        if(col+2 < n){
            if(row+1 < n){
                if(grid[row+1][col+2] > grid[row][col] + 1){
                    ms.insert({row+1,col+2});
                    grid[row+1][col+2] = grid[row][col] + 1;
                }
            }
            if(row-1 >=0){
                if(grid[row-1][col+2] > grid[row][col] + 1){
                    ms.insert({row-1,col+2});
                    grid[row-1][col+2] = grid[row][col] + 1;
                }
            }
        }
        if(col-2 >=0){
            if(row+1 < n){
                if(grid[row+1][col-2] > grid[row][col] + 1){
                    ms.insert({row+1,col-2});
                    grid[row+1][col-2] = grid[row][col] + 1;
                }
            }
            if(row-1 >=0){
                if(grid[row-1][col-2] > grid[row][col] + 1){
                    ms.insert({row-1,col-2});
                    grid[row-1][col-2] = grid[row][col] + 1;
                }
            }
        }
        if(row+2 < n){
            if(col+1 < n){
                if(grid[row+2][col+1] > grid[row][col] + 1){
                    ms.insert({row+2,col+1});
                    grid[row+2][col+1] = grid[row][col] + 1;
                }
            }
            if(col-1 >=0){
                if(grid[row+2][col-1] > grid[row][col] + 1){
                    ms.insert({row+2,col-1});
                    grid[row+2][col-1] = grid[row][col] + 1;
                }
            }
        }
        if(row-2 >=0){
            if(col+1 < n){
                if(grid[row-2][col+1] > grid[row][col] + 1){
                    ms.insert({row-2,col+1});
                    grid[row-2][col+1] = grid[row][col] + 1;
                }
            }
            if(col-1 >=0){
                if(grid[row-2][col-1] > grid[row][col] + 1){
                    ms.insert({row-2,col-1});
                    grid[row-2][col-1] = grid[row][col] + 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

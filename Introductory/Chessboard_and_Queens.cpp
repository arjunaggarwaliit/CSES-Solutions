#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isSafe(vector<string>&board, int n, int row, int col){
    for(int i=0;i<n;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
void count(int row,int n,vector<string> &board, int& cnt){
    if(row == n){
        cnt += 1;
        return;
    }
    for(int col = 0; col< n; col++){
        if(board[row][col] == '*'){
            continue;
        }
        if(isSafe(board,n,row,col)){
            board[row][col] = 'Q';
            count(row + 1, n, board, cnt);
            board[row][col]= '.';
        }
    }
}
int32_t main(){
    int n = 8;
    vector<string> board;
    for(int i=0;i<8;i++){
        string s = "";
        for(int i=0;i<8;i++){
            char c; cin >> c;
            s += c;
        }
        board.push_back(s);
    }
    int cnt = 0;
    count(0,n,board,cnt);
    cout << cnt << endl;
}

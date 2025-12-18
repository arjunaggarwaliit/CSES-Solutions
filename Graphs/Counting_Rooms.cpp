#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int i, int j, int n, int m,vector<string>&vec,vector<vector<bool>> &vis, int prevdir){
    vis[i][j] = true;
    for(int k=0;k<=3;k++){
        if(k == prevdir){
            continue;
        }
        else{
            if(k==0 && i>0){
                if(!vis[i-1][j] && vec[i-1][j]=='.'){
                    dfs(i-1,j,n,m,vec,vis,2);
                }
            }
            if(k==1 && j<m-1){
                if(!vis[i][j+1] && vec[i][j+1]=='.'){
                    dfs(i,j+1,n,m,vec,vis,3);
                }
            }
            if(k==2 && i<n-1){
                if(!vis[i+1][j] && vec[i+1][j]=='.'){
                    dfs(i+1,j,n,m,vec,vis,0);
                }
            }
            if(k==3 && j>0){
                if(!vis[i][j-1] && vec[i][j-1]=='.'){
                    dfs(i,j-1,n,m,vec,vis,1);
                }
            }
        }
    }
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<string> vec(n);
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            char c; cin >> c;
            s += c;
        }
        vec[i] = s;
    }
    vector<vector<bool>> vis (n,vector<bool>(m,false));
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j] == '.'){
                if(!vis[i][j]){
                    cnt += 1;
                    dfs(i,j,n,m,vec,vis,-1);
                }
            }
        }
    }
    cout << cnt << endl;
}
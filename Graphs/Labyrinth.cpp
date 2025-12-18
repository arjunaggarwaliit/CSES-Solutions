#include <bits/stdc++.h>
using namespace std;
#define int long long
void bfs(int start, int end, int n, int m, vector<string>&vec){
    vector<vector<bool>> vis (n, vector<bool>(m,false));
    queue<pair<int,int>> q;
    q.push({start,end});
    vis[start][end] = true;
    vector<vector<char>> parent(n,vector<char> (m,'.'));
    parent[start][end] = '#';
    while(!q.empty()){
        pair<int,int> pr = q.front();
        q.pop();
        int i = pr.first;
        int j = pr.second;
        if(vec[i][j] == 'B'){
            cout << "YES" << endl;
            string ans = "";
            int tempi = i;
            int tempj = j;
            while(parent[tempi][tempj]!='#'){
                char c = parent[tempi][tempj];
                ans += c;
                if(c=='U'){
                    tempi++;
                }
                else if(c=='D'){
                    tempi--;
                }
                else if(c=='L'){
                    tempj++;
                }
                else{
                    tempj--;
                }
            }
            reverse(ans.begin(),ans.end());
            cout << ans.length() << endl;
            cout << ans << endl;
            return;
        }
        if(i > 0 && vec[i-1][j]!='#'){
            if(!vis[i-1][j]){
                vis[i-1][j] = true;
                q.push({i-1,j});
                parent[i-1][j] = 'U';
            }
        }
        if(i < n-1 && vec[i+1][j]!='#'){
            if(!vis[i+1][j]){
                vis[i+1][j] = true;
                q.push({i+1,j});
                parent[i+1][j] = 'D';
            }
        }
        if(j > 0 && vec[i][j-1]!='#'){
            if(!vis[i][j-1]){
                vis[i][j-1] = true;
                q.push({i,j-1});
                parent[i][j-1] = 'L';
            }
        }
        if(j < m-1 && vec[i][j+1]!='#'){
            if(!vis[i][j+1]){
                vis[i][j+1] = true;
                q.push({i,j+1});
                parent[i][j+1] = 'R';
            }
        }
    }
    cout << "NO" << endl;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<string> vec(n);
    pair<int,int> start;
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<m;j++){
            char c; cin >> c;
            if(c=='A'){
                start = {i,j};
            }
            s += c;
        }
        vec[i] = s;
    }
    bfs(start.first,start.second,n,m,vec);
}
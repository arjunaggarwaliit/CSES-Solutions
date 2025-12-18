#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> multi_bfs(vector<pair<int,int>> &startpos, int n, int m,vector<string> &mp){
    vector<vector<int>> time (n, vector<int> (m,-1));
    queue<pair<int,int>> q;
    for(auto node : startpos){
        q.push(node);
        time[node.first][node.second] = 0;
    }
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int i = pos.first;
        int j = pos.second;
        if(i > 0){
            if(time[i-1][j] == -1 && mp[i-1][j]!='#'){
                time[i-1][j] = time[i][j] + 1;
                q.push({i-1,j});
            }
        }
        if(i < n-1){
            if(time[i+1][j] == -1 && mp[i+1][j]!='#'){
                time[i+1][j] = time[i][j] + 1;
                q.push({i+1,j});
            }
        }
        if(j > 0){
            if(time[i][j-1] == -1 && mp[i][j-1]!='#'){
                time[i][j-1] = time[i][j] + 1;
                q.push({i,j-1});
            }
        }
        if(j < m-1){
            if(time[i][j+1] == -1 && mp[i][j+1]!='#'){
                time[i][j+1] = time[i][j] + 1;
                q.push({i,j+1});
            }
        }
    }
    return time;
}
void bfs(pair<int,int> start, vector<string> &mp, vector<vector<int>>& time, int n, int m){
    vector<vector<char>> vis (n, vector<char>(m , '.'));
    queue<pair<pair<int,int>,int>> q;
    q.push({{start.first,start.second},0});
    vis[start.first][start.second] = '#';
    while(!q.empty()){
        pair<pair<int,int>,int> pr = q.front(); q.pop();
        int i = pr.first.first;
        int j = pr.first.second;
        if((i==0 || i==n-1) || (j==0 || j==m-1)){
            int tempi = i;
            int tempj = j;
            string ans = "";
            while(1){
                if(tempi==start.first && tempj==start.second){
                    reverse(ans.begin(),ans.end());
                    cout << "YES" << endl;
                    cout << ans.length() << endl;
                    cout << ans << endl;
                    break;
                }
                else{
                    ans += vis[tempi][tempj];
                    char c = vis[tempi][tempj];
                    if(c=='D'){
                        tempi--;
                    }
                    else if(c=='U'){
                        tempi++;
                    }
                    else if(c=='L'){
                        tempj++;
                    }
                    else{
                        tempj--;
                    }
                }
            }
            return;
        }
        int timer = pr.second;
        if(i>0 && mp[i-1][j]!='#'){
            if(vis[i-1][j]=='.' && timer+1 < time[i-1][j]){
                vis[i-1][j] = 'U';
                q.push({{i-1,j},timer+1});
            }
        }
        if(i<n-1 && mp[i+1][j]!='#'){
            if(vis[i+1][j]=='.' && timer+1 < time[i+1][j]){
                vis[i+1][j] = 'D';
                q.push({{i+1,j},timer+1});
            }
        }
        if(j>0 && mp[i][j-1]!='#'){
            if(vis[i][j-1]=='.' && timer+1 < time[i][j-1]){
                vis[i][j-1] = 'L';
                q.push({{i,j-1},timer+1});
            }
        }
        if(j<m-1 && mp[i][j+1]!='#'){
            if(vis[i][j+1]=='.' && timer+1 < time[i][j+1]){
                vis[i][j+1] ='R';
                q.push({{i,j+1},timer+1});
            }
        }
    }
    cout << "NO" << endl;
}
int32_t main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> startpos;
    pair<int,int> start;
    vector<string> mp;
    for(int i=0; i<n ; i++){
        string s = "";
        for(int j=0; j<m ; j++){
            char c;cin >> c; s += c;
            if(c=='M'){
                startpos.push_back({i,j});
            }
            if(c=='A'){
                start = {i,j};
            }
        }
        mp.push_back(s);
    }
    vector<vector<int>> time = multi_bfs(startpos, n,m,mp);
    for(int i=0; i< n; i++){
        for(int j=0; j<m ; j++){
            if(time[i][j]==-1){
                time[i][j] = LLONG_MAX;
            }
        }
    }
    bfs(start,mp,time,n,m);
}
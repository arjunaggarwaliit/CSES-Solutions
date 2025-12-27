#include <bits/stdc++.h>
using namespace std;
#define int long long

string de_bruijn(int n){
    vector<int> covered((1 << n-1),0);
    stack<pair<int,char>> st;
    st.push({0,'#'});
    string s= "";
    while(!st.empty()){
        pair<int,char> node = st.top();
        if(covered[node.first] == 2){
            if(node.second != '#') s += node.second;
            st.pop();
        }
        else{
            st.push({(((node.first)<<1)+covered[node.first])%(1<<(n-1)),'0'+covered[node.first]});
            covered[node.first]++;
        }
    }
    for(int i=0 ; i<n-1 ; i++) s += '0';
    reverse(s.begin(),s.end());
    return s;
}

int32_t main(){
    int n; cin >> n;
    cout << de_bruijn(n) << endl;
}
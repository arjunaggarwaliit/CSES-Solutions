#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m ; cin >> n >> m;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    vector<int> ind(n + 1);
    for (int i = 0; i < n; ++i) ind[x[i]] = i;
    vector<bool> num(n);
    for(int i=1;i<n;i++){
        if(ind[i+1]>ind[i]){
            num[i] = true;
        }
        else num[i] = false;
    }
    int i=1;
    int count =1;
    while(i<n){
        while(i<n && num[i]){
            i++;
        }
        if(i==n) break;
        if(num[i] == false){
            count+=1;
        }
        i++;
    }
    while(m--){
        int a,b; cin >> a >> b;
        if(a==b){
            cout << count << endl;
            continue;
        }
        a--; b--;
        int va = x[a];
        int vb = x[b];
        ind[va] = b;
        ind[vb] = a;
        swap(x[a], x[b]);
        set<int> s;
        vector<int> vec = {x[a],x[b],x[a]-1,x[b]-1};
        for(int i=0;i<4;i++){
            if(vec[i]<n && vec[i]>=1) s.insert(vec[i]);
        }
        for(auto ele : s){
            if(ind[ele+1]>ind[ele]){
                if(num[ele]) continue;
                else{
                    num[ele] = true;
                    count--;
                }
            }
            else{
                if(num[ele]){
                    num[ele] = false;
                    count++;
                }
                else continue;
            }
        }
        cout << count << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int nc2(int x){
    return ((x*(x-1))/2);
}
int32_t main(){
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    int maxx = *(max_element(x.begin(),x.end()));
    vector<int> cnt(maxx+1,0);
    for(int i=0;i<n;i++){
        cnt[x[i]]+=1;
    }
    vector<int> lps(maxx+1,0);
    lps[1] = 1;
    int tot = 0;
    for(int i=2;i<=maxx;i++){
        int div = 0;
        if(lps[i]==0){
            for(int j=i; j<=maxx ; j+=i){
                if(lps[j]==0) lps[j] = i;
                div += cnt[j];
            }
            tot += nc2(div);
        }
        else{
            for(int j=i;j<=maxx;j+=i){
                div += cnt[j];
            }
            int temp = i;
            set<int> s;
            while(temp > 1){
                if(s.find(lps[temp])!= s.end()){
                    div = 1;
                    break;
                }
                s.insert(lps[temp]);
                temp/=lps[temp];
            }
            if(s.size() & 1){
                tot += nc2(div);
            }
            else{
                tot -= nc2(div);
            }
        }
    }
    cout << nc2(n) - tot << endl;
}
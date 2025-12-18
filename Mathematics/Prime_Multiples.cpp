#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; int k; cin >> n >> k;
    vector<long long> vec(k);
    for(int i=0;i<k;i++) cin >> vec[i];
    long long tot = 0;
    for(int i=1;i<(1<<k);i++){
        int cnt = 0;
        long long pro = 1LL;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                cnt +=1;
                // if(pro<=0 || pro>n){
                //     break;
                // }
                if(pro > n/vec[j]){
                    pro = n+1;
                    break;
                }
                pro *= vec[j];
            }
        }
        // if(pro<=0 || pro>n){
        //     continue;
        // }
        if(cnt&1){
            tot += (n/pro);
        }
        else{
            tot -= (n/pro);
        }
    }
    cout << tot << endl;
}
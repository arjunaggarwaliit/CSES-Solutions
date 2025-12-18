#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[18][10][2][2];
int dp_recur(int n, int prev,int restricted, int started, vector<int>&digits){
    if(n==-1) return 1;
    if(dp[n][prev][restricted][started] != -1) return dp[n][prev][restricted][started];
    int tot = 0;
    if(started){
        if(restricted){
            for(int i=0 ; i < digits[n]; i++){
                if(i == prev) continue;
                tot += dp_recur(n-1,i,0,started,digits);
            }
            if(digits[n]!=prev) tot += dp_recur(n-1,digits[n],1,started,digits);
        }
        else{
            for(int i=0 ; i < 10 ; i++){
                if( i == prev) continue;
                tot += dp_recur(n-1,i,0,started,digits);
            }
        }
    }
    else{
        if(restricted){
            tot += dp_recur(n-1,prev,1-restricted,started,digits);
            for(int i=1 ; i < digits[n]; i ++){
                tot += dp_recur(n-1,i,1-restricted,1-started,digits);
            }
            tot += dp_recur(n-1,digits[n],restricted,1-started,digits);
        }
        else{
            tot += dp_recur(n-1,prev,restricted,started,digits);
            for(int i=1; i < 10 ; i++){
                tot += dp_recur(n-1,i,restricted,1-started,digits);
            }
        }
    }
    return dp[n][prev][restricted][started] = tot;
}
int func(int num){
    // dp [length][prev][bool : is_restricted][bool started]
    // Digit DP
    // ANS dp [N][0][true][false]
    vector<int> digits;
    if(num == 0) return 1;
    while(num > 0){
        digits.push_back(num%10);
        num/=10;
    }
    memset(dp,-1,sizeof(dp));
    return dp_recur(digits.size()-1,0,1,0,digits);
}
int32_t main(){
    int a,b; cin >> a >> b;
    if(a==0){
        cout << func(b) << endl;
        return 0;
    }
    cout << func(b) - func(a-1) << endl;
    // cout << func(68) << endl;
}
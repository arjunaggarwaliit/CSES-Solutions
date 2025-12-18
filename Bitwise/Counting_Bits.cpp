#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
    int n; cin >> n;
    n++;
    int i= 2;
    int tot = 0;
    while(1){
        int parts = n/i;
        int sm = 0;
        sm += (parts * (i/2));
        int diff = n%i;
        if(diff > (i/2)){
            sm += (diff - i/2);
        }
        if(sm == 0){
            break;
        }
        tot += sm;
        i<<=1;
    }
    cout << tot << endl;
}
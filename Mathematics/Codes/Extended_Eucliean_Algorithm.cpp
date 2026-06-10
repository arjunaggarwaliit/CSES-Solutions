#include <bits/stdc++.h>
using namespace std;
#define int long long


// Scratch Implementation (using fact that each r_i can be expressed as L.C. of a and b)
pair<int,int> extended_euclidean(int a, int b){
    if(a < 0) a= -a;
    if(b < 0) b= -b;
    pair<int,int> acof = {1, 0}; // (a1, a2)
    pair<int,int> bcof = {0, 1}; // (b1, b2)
    while(a!=0){
        int q = b/a;
        int r = b%a;
        b = a;
        a = r;
        pair<int,int> rcof = {bcof.first- acof.first*q, bcof.second- acof.second*q};
        bcof = acof;
        acof = rcof;
    }
    return bcof;
}

// Implementation of cp-algorithms.com
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main(){
    pair<int,int> ans = extended_euclidean(-8,3);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
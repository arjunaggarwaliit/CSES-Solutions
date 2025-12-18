// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// bool prime(int n){
//     for(int i=2;i*i<=n;i++){
//         if(n%i == 0){
//             return false;
//         }
//     }
//     return true;
// }
// int32_t main(){
//     int t; cin >> t;
//     while(t--){
//         int n; cin >> n;
//         if(n==1){
//             cout << 2 << endl;
//         }
//         else{
//             int var = n+1;
//             while(1){
//                 if(prime(var)){
//                     cout << var << endl;
//                     break;
//                 }
//                 else {
//                     var ++;
//                 }
//             }
//         }
//     }
// }
// have to use miller rabin probablistic test
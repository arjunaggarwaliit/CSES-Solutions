// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int MOD = 1000000007;
// int pow(int a,int b,int mod){
//     int ans = 1;
//     while(b>0){
//         if(b&1){
//             ans*=a;
//             ans%=mod;
//         }
//         a = (a*a)%mod;
//         b>>=1;
//     }
//     return ans;
// }
// int inv(int a,int mod){
//     // for prime mod
//     // fermat theorem
//     return pow(a,mod-2,mod);
// }
// int gcd(int a,int b){
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
// int lcm(int a,int b,int mod){
//     int ans = 1;
//     ans = a*b;
//     ans %= mod;
//     ans *= inv(gcd(a,b),mod);
//     ans %= mod;
//     return ans;
// }
// int lcmlist(vector<int>& sz){
//     int ans = 1;
//     for(int i=0;i<sz.size();i++){
//         ans = lcm(ans,sz[i],MOD);
//         ans%=MOD;
//     }
//     return ans;
// }
// int32_t main(){
//     int n; cin>> n;
//     vector<bool> vis(n+1,false);
//     vector<int> vec(n+1);
//     for(int i=1;i<=n;i++) cin >> vec[i];
//     vector<int> sz;
//     for(int i=1;i<=n;i++){
//         if(vis[i]==false){
//             vis[i] = true;
//             int sztoadd = 1;
//             int temp = i;
//             while(vis[vec[temp]] == false){
//                 vis[vec[temp]] = true;
//                 temp = vec[temp];
//                 sztoadd +=1;
//             }
//             sz.push_back(sztoadd);
//         }
//     }
//     cout << lcmlist(sz) << endl;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

// Function for modular exponentiation (already correct)
int power(int a, int b, int mod) {
    int ans = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Map to store the maximum exponent for each prime factor found
map<int, int> max_exponents;

// Finds the prime factorization of n and updates max_exponents
void prime_factorize_and_update(int n) {
    // Only cycle sizes up to N=10^5 need to be factored
    // The prime factors will be relatively small
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int current_exponent = 0;
            while (n % i == 0) {
                current_exponent++;
                n /= i;
            }
            // Update the maximum exponent for prime i
            max_exponents[i] = max(max_exponents[i], current_exponent);
        }
    }
    // If n is still > 1, it is a prime factor itself (could be a prime > sqrt(original n))
    if (n > 1) {
        max_exponents[n] = max(max_exponents[n], 1LL);
    }
}

// Calculates the final LCM modulo MOD
int calculate_final_lcm_mod() {
    int final_lcm = 1;
    // The LCM is the product of (prime ^ max_exponent) for all primes found
    for (auto pr : max_exponents) {
        int prime = pr.first;
        int exponent = pr.second;
        // Calculate (prime ^ exponent) % MOD using modular exponentiation
        int term = power(prime, exponent, MOD);
        // Multiply into the result, keeping it modulo MOD
        final_lcm = (final_lcm * term) % MOD;
    }
    return final_lcm;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // The vector 'vec' stores the permutation P, where P[i] is the destination of i
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    vector<bool> vis(n + 1, false);
    vector<int> sz; // Stores the sizes of the cycles

    // Cycle Decomposition (Your logic was mostly correct here)
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            vis[i] = true;
            int sztoadd = 1;
            int temp = vec[i]; // Start at the next element in the cycle
            while (temp != i) { // Continue until we return to the starting element 'i'
                vis[temp] = true;
                temp = vec[temp];
                sztoadd += 1;
            }
            sz.push_back(sztoadd);
        }
    }

    // Corrected logic: Use prime factorization on all cycle sizes
    for (int size : sz) {
        prime_factorize_and_update(size);
    }

    // Output the final LCM mod MOD
    cout << calculate_final_lcm_mod() << endl;

    return 0;
}
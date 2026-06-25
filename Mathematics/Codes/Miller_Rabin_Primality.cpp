#include <bits/stdc++.h>
using namespace std;
#define int long long


int mod_mul(int a, int b, int mod) {
    return (__int128)a * b % mod;
}

int mod_pow(int a, int d, int mod) {
    int res = 1;
    while (d) {
        if (d & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool miller_rabin(int n, int iter = 40) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0) return false;

    int d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < iter; i++) {
        int a = uniform_int_distribution<int>(2, n - 2)(rng);

        int x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1) continue;

        bool composite = true;

        for (int r = 1; r < s; r++) {
            x = mod_mul(x, x, n);

            if (x == n - 1) {
                composite = false;
                break;
            }
        }

        if (composite) return false;
    }

    return true;
}
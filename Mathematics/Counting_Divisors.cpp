#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> hpf(N, 0);

void sieve_of_eratosthenes() {
    for (int i = 2; i < N; i++) {
        if (hpf[i] == 0) {
            for (int j = i; j < N; j += i) {
                hpf[j] = i;
            }
        }
    }
}

int32_t main() {
    sieve_of_eratosthenes();
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x == 1) {
            cout << 1 << endl;
            continue;
        }

        map<int,int> mp;
        int temp = x;
        while (temp > 1) {
            mp[hpf[temp]]++;
            temp /= hpf[temp];
        }

        int product = 1;
        for (auto pr : mp) product *= (pr.second + 1);
        cout << product << endl;
    }
}

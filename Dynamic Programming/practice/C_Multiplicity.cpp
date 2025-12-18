#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<int> updates;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (j <= n) updates.push_back(j);
                int k = a[i] / j;
                if (k != j && k <= n) updates.push_back(k);
            }
        }
        sort(updates.rbegin(), updates.rend());
        for (int len : updates) {
            dp[len] = (dp[len] + dp[len - 1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}

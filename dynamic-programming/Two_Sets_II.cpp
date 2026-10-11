#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MOD = 1e9 + 7;

    int n;
    cin >> n;

    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << 0;
        return 0;
    }

    sum /= 2;
    vector<int> dp(sum + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int x = sum; x >= i; x--) {
            dp[x] = (dp[x] + dp[x - i]) % MOD;
        }
    }
    
    // dp[sum] * modInverse(2, MOD - 2, MOD) = (dp[sum] / 2) % MOD;
    cout << (1LL * dp[sum] * 500000004) % MOD;
    return 0;
}
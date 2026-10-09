#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MOD = 1e9 + 7;

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - 6); j < i; j++) {
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    cout << dp[n];
    return 0;
}
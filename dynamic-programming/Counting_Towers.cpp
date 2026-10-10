#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MOD = 1e9 + 7;

    int t;
    cin >> t;
    vector<int> tests(t);
    int n = -1;
    for (int& i : tests) {
        cin >> i;
        n = max(n, i);
    }

    vector<vector<unsigned int>> dp(n, vector<unsigned int>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] * 4) % MOD;
        dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;

        dp[i][1] = (dp[i - 1][1] * 2) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
    }
    
    for (int i : tests) {
        cout << (dp[i - 1][0] + dp[i - 1][1]) % MOD << "\n";
    }

    return 0;
}
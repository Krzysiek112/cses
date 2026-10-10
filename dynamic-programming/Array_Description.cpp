#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MOD = 1e9 + 7;

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int& val : arr) {
        cin >> val;
    }

    vector<vector<int>> dp(n, vector<int>(m + 2));
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (num != 0) {
            if (i == 0) {
                dp[i][num] = 1;
                continue;
            }

            dp[i][num] = (dp[i][num] + dp[i - 1][num - 1]) % MOD;
            dp[i][num] = (dp[i][num] + dp[i - 1][num]) % MOD;
            dp[i][num] = (dp[i][num] + dp[i - 1][num + 1]) % MOD;
        }
        else {
            for (int num = 1; num <= m; num++) {
                if (i == 0) {
                    for (int j = 1; j <= m; j++) {
                        dp[i][num] = 1;
                    }
                    continue;
                }

                dp[i][num] = (dp[i][num] + dp[i - 1][num - 1]) % MOD;
                dp[i][num] = (dp[i][num] + dp[i - 1][num]) % MOD;
                dp[i][num] = (dp[i][num] + dp[i - 1][num + 1]) % MOD;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + dp[n - 1][i]) % MOD;
    }
    cout << res;
    return 0;
}
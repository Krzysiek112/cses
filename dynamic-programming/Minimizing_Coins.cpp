#include <bits/stdc++.h>
using namespace std;

/*
Observation:
-

Approach: Dynamic programming
lets consider every option

dimensions: 1
base case: dp[0] = 0
dp[i]: minimum number of coins to sum up to i
transition: dp[i] = min(dp[i - c1..c2..c3]) + 1
*/

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        coins[i] = c;
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (const int& c : coins) {
            int j = i - c;
            if (j >= 0 && dp[j] != INT_MAX) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[x] != INT_MAX) {
        cout << dp[x];
    }
    else {
        cout << -1;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MOD = 1e9 + 7;

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& c : coins) {
        cin >> c;
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int c : coins) {
        for (int i = 1; i <= x; i++) {
            if (i >= c) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }

    cout << dp[x];
    return 0;
}